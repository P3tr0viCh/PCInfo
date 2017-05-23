// ---------------------------------------------------------------------------

#pragma hdrstop

#include "PCInfoAdd.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

// ---------------------------------------------------------------------------
void StringListAdd(TStrings* Strings, int Level, String Text) {
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

	Strings->Add(S);
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
String SystemBoard(P3tr0viCh::TSystemInfo * SystemInfo) {
	String SBaseBoard = ConcatStrings(SystemInfo->BaseBoardManufacturer,
		SystemInfo->BaseBoardProduct, SPACE);

	String SSystemManufacturer = SystemInfo->SystemManufacturer;
	String SSystemProductName = SystemInfo->SystemProductName;

	if (AnsiCompareText(SSystemManufacturer, "System Manufacturer") == 0) {
		SSystemManufacturer = "";
	}
	if (AnsiCompareText(SSystemProductName, "System Product Name") == 0) {
		SSystemProductName = "";
	}

	String SSystem = ConcatStrings(SSystemManufacturer,
		SSystemProductName, SPACE);
	if (!IsEmpty(SSystem)) {
		SBaseBoard = SBaseBoard + SPACE + "(" + SSystem + ")";
	}

	return SBaseBoard;
}

// ---------------------------------------------------------------------------
void GetSystemInfo(TStrings* StringList, P3tr0viCh::TSystemInfo *SystemInfo) {
	StringListAdd(StringList, 0, "Имя компьютера");
	StringListAdd(StringList, 1, SystemInfo->ComputerName);

	if (SystemInfo->IPAddressList->Count > 1) {
		StringListAdd(StringList, 0, "IP адреса");
	}
	else {
		StringListAdd(StringList, 0, "IP адрес");
	}
	for (int i = 0; i < SystemInfo->IPAddressList->Count; i++) {
		StringListAdd(StringList, 1, SystemInfo->IPAddressList->Strings[i]);
	}

	StringListAdd(StringList, 0, "Операционная система");
	StringListAdd(StringList, 1, WindowsVersion(SystemInfo));

	StringListAdd(StringList, 0, "Системная плата");
	StringListAdd(StringList, 1, SystemBoard(SystemInfo));

	StringListAdd(StringList, 0, "Процессор");
	StringListAdd(StringList, 1, SystemInfo->ProcessorName);

	StringListAdd(StringList, 0, "Оперативная память");
	StringListAdd(StringList, 1, FormatBytes(SystemInfo->PhysMemory));

	StringListAdd(StringList, 0, "Логические диски");
	for (int i = 0; i < SystemInfo->LogicalDrives->Count; i++) {
		P3tr0viCh::TLogicalDrive* LogicalDrive =
			(P3tr0viCh::TLogicalDrive*) SystemInfo->LogicalDrives->Items[i];

		if (IsEmpty(LogicalDrive->Label)) {
			StringListAdd(StringList, 1,
				Format("%s:", ARRAYOFCONST((LogicalDrive->Letter))));
		}
		else {
			StringListAdd(StringList, 1,
				Format("%s: (%s)", ARRAYOFCONST((LogicalDrive->Letter,
				LogicalDrive->Label))));
		}
		StringListAdd(StringList, 2, Format("Объём: %s; Свободно: %s (%d %%)",
			ARRAYOFCONST((FormatBytes(LogicalDrive->Total),
			FormatBytes(LogicalDrive->Free),
			(int)Round(((Extended) LogicalDrive->Free / (Extended)
			LogicalDrive->Total) * 100)))));
	}

	if (!IsEmpty(SystemInfo->PrinterName)) {
		StringListAdd(StringList, 0, "Принтер");
		StringListAdd(StringList, 1, SystemInfo->PrinterName);
	}
}
