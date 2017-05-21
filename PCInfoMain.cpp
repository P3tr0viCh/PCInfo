// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PCInfoMain.h"

#include "UtilsStr.h"
#include "UtilsMisc.h"

#include "SystemInfo.h"

#include <winsock2.h>

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMain *Main;

// ---------------------------------------------------------------------------
__fastcall TMain::TMain(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TMain::FormCreate(TObject *Sender) {
	UpdateAbout();

	UpdateInfo();
}

// ---------------------------------------------------------------------------
void __fastcall TMain::FormKeyPress(TObject *Sender, System::WideChar &Key) {
	if (Key == char(27)) {
		Close();
	}
}

// ---------------------------------------------------------------------------
void TMain::UpdateAbout() {
	StatusBar->Panels->Items[0]->Text = "© Дураев К.П., ЦВТС, Уральская Сталь";
	StatusBar->Panels->Items[1]->Text =
		"Версия " + GetFileVer(Application->ExeName) + " (" +
		GetFileVerDate() + ")";
}

// ---------------------------------------------------------------------------
void TMain::MemoAdd(int Level, String Text) {
	String S = "";

	for (int i = 0; i < Level; i++) {
		S += "\t";
	}

	if (IsEmpty(Text)) {
		S += "Неизвестно";
	}
	else {
		S += Text;
	}

	Memo->Lines->Add(S);
}

// ---------------------------------------------------------------------------
String WindowsVersion(P3tr0viCh::TSystemInfo *SystemInfo) {
	String SWindowsVersion;
	if (SystemInfo->IsWindows64Bit) {
		SWindowsVersion = "x64";
	}
	else {
		SWindowsVersion = "x32";
	}
	return ConcatStrings(ConcatStrings(SystemInfo->WindowsProductName,
		SystemInfo->WindowsCSDVersion, SPACE),
		"(" + SWindowsVersion + ")", SPACE);
}

// ---------------------------------------------------------------------------
String SystemBoard(P3tr0viCh::TSystemInfo *SystemInfo) {
	String SManufacturer = "";
	String SProductName = "";

	SManufacturer = SystemInfo->BIOSSystemManufacturer;
	if (IsEmpty(SManufacturer) || AnsiCompareText(SManufacturer,
		"System Manufacturer") == 0) {
		SManufacturer = SystemInfo->BIOSBaseBoardManufacturer;
	}

	SProductName = SystemInfo->BIOSSystemProductName;
	if (IsEmpty(SProductName) || AnsiCompareText(SProductName,
		"System Product Name") == 0) {
		SProductName = SystemInfo->BIOSBaseBoardProduct;
	}

	return ConcatStrings(SManufacturer, SProductName, SPACE);
}

// ---------------------------------------------------------------------------
void TMain::UpdateInfo() {
	Memo->Clear();

	P3tr0viCh::TSystemInfo *SystemInfo = new P3tr0viCh::TSystemInfo();

	SystemInfo->Update();

	MemoAdd(0, "Имя компьютера");
	MemoAdd(1, SystemInfo->ComputerName);

	MemoAdd(0, "IP адрес");
	MemoAdd(1, SystemInfo->IPAddress);

	MemoAdd(0, "Операционная система");
	MemoAdd(1, WindowsVersion(SystemInfo));

	MemoAdd(0, "Системная плата");
	MemoAdd(1, SystemBoard(SystemInfo));

	MemoAdd(0, "Процессор");
	MemoAdd(1, SystemInfo->ProcessorName);

	MemoAdd(0, "Оперативная память");
	MemoAdd(1, FormatBytes(SystemInfo->PhysMemory));

	MemoAdd(0, "Логические диски");
	for (int i = 0; i < SystemInfo->LogicalDrives->Count; i++) {
		P3tr0viCh::TLogicalDrive* LogicalDrive =
			(P3tr0viCh::TLogicalDrive*) SystemInfo->LogicalDrives->Items[i];

		if (IsEmpty(LogicalDrive->Label)) {
			MemoAdd(1, Format("%s:", ARRAYOFCONST((LogicalDrive->Letter))));
		}
		else {
			MemoAdd(1, Format("%s: (%s)", ARRAYOFCONST((LogicalDrive->Letter,
				LogicalDrive->Label))));
		}
		MemoAdd(2, Format("Объём: %s; Свободно: %s (%d %%)",
			ARRAYOFCONST((FormatBytes(LogicalDrive->Total),
			FormatBytes(LogicalDrive->Free),
			(int)Round(((Extended) LogicalDrive->Free / (Extended)
			LogicalDrive->Total) * 100)))));
	}

	if (!IsEmpty(SystemInfo->PrinterName)) {
		MemoAdd(0, "Принтер");
		MemoAdd(1, SystemInfo->PrinterName);
	}

	delete SystemInfo;
}
// ---------------------------------------------------------------------------
