// ---------------------------------------------------------------------------

#pragma hdrstop

#include "PCInfoAdd.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

// ---------------------------------------------------------------------------
void StringListAdd(TStrings* Strings, int Level, String Text,
	bool UseRusCaptions) {
	String S = "";

	for (int i = 0; i < Level; i++) {
		S += "\t";
	}

	if (IsEmpty(Text)) {
		S += UseRusCaptions ? "Неизвестно" : "Unknown";
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
void GetSystemInfo(TStrings* StringList, P3tr0viCh::TSystemInfo *SystemInfo,
	bool UseRusCaptions) {
	StringListAdd(StringList, 0, UseRusCaptions ? "Имя компьютера" :
		"Host name", UseRusCaptions);
	StringListAdd(StringList, 1, SystemInfo->ComputerName, UseRusCaptions);

	if (SystemInfo->IPAddressList->Count > 1) {
		StringListAdd(StringList, 0, UseRusCaptions ? "IP адреса" :
			"IP addreses", UseRusCaptions);
	}
	else {
		StringListAdd(StringList, 0, UseRusCaptions ? "IP адрес" : "IP address",
			UseRusCaptions);
	}
	for (int i = 0; i < SystemInfo->IPAddressList->Count; i++) {
		StringListAdd(StringList, 1, SystemInfo->IPAddressList->Strings[i],
			UseRusCaptions);
	}

	StringListAdd(StringList, 0, UseRusCaptions ? "Операционная система" :
		"Operating system", UseRusCaptions);
	StringListAdd(StringList, 1, WindowsVersion(SystemInfo), UseRusCaptions);

	StringListAdd(StringList, 0, UseRusCaptions ? "Системная плата" :
		"Motherboard", UseRusCaptions);
	StringListAdd(StringList, 1, SystemBoard(SystemInfo), UseRusCaptions);

	StringListAdd(StringList, 0, UseRusCaptions ? "Процессор" : "CPU",
		UseRusCaptions);
	StringListAdd(StringList, 1, SystemInfo->ProcessorName, UseRusCaptions);

	TStrings *ByteNames = new TStringList();
	if (!UseRusCaptions) {
		ByteNames->Add("b");
		ByteNames->Add("Kb");
		ByteNames->Add("Mb");
		ByteNames->Add("Gb");
		ByteNames->Add("Tb");
	}

	StringListAdd(StringList, 0, UseRusCaptions ? "Оперативная память" : "RAM",
		UseRusCaptions);
	StringListAdd(StringList, 1, FormatBytes(SystemInfo->PhysMemory, ByteNames),
		UseRusCaptions);

	// TODO: выводить список логических дисков в строке физического диска

	StringListAdd(StringList, 0, UseRusCaptions ? "Логические диски" :
		"Logical drives", UseRusCaptions);

	String F = UseRusCaptions ? "Объём: %s; Свободно: %s (%d %%)" :
		"Total: %s; Free: %s (%d %%); Drive #%d";
	for (int i = 0; i < SystemInfo->LogicalDrives->Count; i++) {
		P3tr0viCh::TLogicalDrive* LogicalDrive =
			(P3tr0viCh::TLogicalDrive*) SystemInfo->LogicalDrives->Items[i];

		if (IsEmpty(LogicalDrive->Label)) {
			StringListAdd(StringList, 1, Format("%s:; Диск №%d",
				ARRAYOFCONST((LogicalDrive->Letter,
				LogicalDrive->PhysicalDriveNum + 1))), UseRusCaptions);
		}
		else {
			StringListAdd(StringList, 1, Format("%s: (%s); Диск №%d",
				ARRAYOFCONST((LogicalDrive->Letter, LogicalDrive->Label,
				LogicalDrive->PhysicalDriveNum + 1))), UseRusCaptions);
		}

		StringListAdd(StringList, 2,
			Format(F, ARRAYOFCONST((FormatBytes(LogicalDrive->Total, ByteNames),
			FormatBytes(LogicalDrive->Free, ByteNames),
			(int)Round(((Extended) LogicalDrive->Free / (Extended)
			LogicalDrive->Total) * 100)))), UseRusCaptions);
	}

	StringListAdd(StringList, 0, UseRusCaptions ? "Физические диски" :
		"Physical drives", UseRusCaptions);

	F = UseRusCaptions ? "Диск №%d: %s (%s)" : "Drive #%d: %s (%s)";
	for (int i = 0; i < SystemInfo->PhysicalDrives->Count; i++) {
		P3tr0viCh::TPhysicalDrive* PhysicalDrive =
			(P3tr0viCh::TPhysicalDrive*) SystemInfo->PhysicalDrives->Items[i];

		StringListAdd(StringList, 1,
			Format(F, ARRAYOFCONST((i + 1, PhysicalDrive->Product,
			FormatBytes(PhysicalDrive->Size, ByteNames)))), UseRusCaptions);
	}

	if (!IsEmpty(SystemInfo->PrinterName)) {
		StringListAdd(StringList, 0, UseRusCaptions ? "Принтер" : "Printer",
			UseRusCaptions);
		StringListAdd(StringList, 1, SystemInfo->PrinterName, UseRusCaptions);
	}

	ByteNames->Free();
}

// ---------------------------------------------------------------------------
String GetDateTimeNow() {
	return FormatDateTime("yyyy.mm.dd hh-mm-ss", Now());
}
