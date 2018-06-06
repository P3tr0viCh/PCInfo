// ---------------------------------------------------------------------------

#pragma hdrstop

#include <math.hpp>

#include "PCInfoAdd.h"
#include "PCInfoStrings.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)

extern TPCInfoStrings * PCInfoStrings;

// ---------------------------------------------------------------------------
void StringListAdd(TStrings * Strings, int Level, String Text) {
	String S = "";

	for (int i = 0; i < Level; i++) {
		S += "\t";
	}

	if (IsEmpty(Text)) {
		S += PCInfoStrings->Get(INFO_TEXT_UNKNOWN);
	}
	else {
		S += Text;
	}

	Strings->Add(S);
}

// ---------------------------------------------------------------------------
String WindowsVersion(P3tr0viCh::TSystemInfo * SystemInfo) {
	String SWindowsProductName = SystemInfo->WindowsProductName;
	if (IsEmpty(SWindowsProductName)) {
		return NULL;
	}

	String SWindowsVersion = SystemInfo->IsWindows64Bit ? "x64" : "x32";

	return ConcatStrings(ConcatStrings(SWindowsProductName,
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
void GetSystemInfo(TStrings * StringList, P3tr0viCh::TSystemInfo * SystemInfo) {
	String S1, S2, S3;

	TStrings * ByteNames = new TStringList();

	ByteNames->Add(PCInfoStrings->Get(BYTES_B));
	ByteNames->Add(PCInfoStrings->Get(BYTES_KB));
	ByteNames->Add(PCInfoStrings->Get(BYTES_MB));
	ByteNames->Add(PCInfoStrings->Get(BYTES_GB));
	ByteNames->Add(PCInfoStrings->Get(BYTES_TB));

	// ----------- HOST NAME -------------------------------------------------

	StringListAdd(StringList, 0, PCInfoStrings->Get(INFO_CAPTION_HOSTNAME));
	StringListAdd(StringList, 1, SystemInfo->ComputerName);

	// ----------- IP --------------------------------------------------------

	if (SystemInfo->IPAddressList->Count > 1) {
		StringListAdd(StringList, 0,
			PCInfoStrings->Get(INFO_CAPTION_IP_ADDRESS_MULTIPLE));
	}
	else {
		StringListAdd(StringList, 0,
			PCInfoStrings->Get(INFO_CAPTION_IP_ADDRESS_SINGLE));
	}
	if (SystemInfo->IPAddressList->Count > 0) {
		for (int i = 0; i < SystemInfo->IPAddressList->Count; i++) {
			StringListAdd(StringList, 1, SystemInfo->IPAddressList->Strings[i]);
		}
	}
	else {
		StringListAdd(StringList, 1, NULL);
	}
	// ----------- WINDOWS VERSION -------------------------------------------

	StringListAdd(StringList, 0,
		PCInfoStrings->Get(INFO_CAPTION_WINDOWS_VERSION));
	StringListAdd(StringList, 1, WindowsVersion(SystemInfo));

	// ----------- MOTHERBOARD -----------------------------------------------

	StringListAdd(StringList, 0, PCInfoStrings->Get(INFO_CAPTION_MOTHERBOARD));
	StringListAdd(StringList, 1, SystemBoard(SystemInfo));

	// ----------- CPU -------------------------------------------------------

	StringListAdd(StringList, 0, PCInfoStrings->Get(INFO_CAPTION_CPU));
	StringListAdd(StringList, 1, SystemInfo->ProcessorName);

	// ----------- RAM -------------------------------------------------------

	StringListAdd(StringList, 0, PCInfoStrings->Get(INFO_CAPTION_RAM));
	StringListAdd(StringList, 1, FormatBytes(SystemInfo->PhysMemory,
		ByteNames));

	// ----------- LOGICAL DRIVES --------------------------------------------

	StringListAdd(StringList, 0,
		PCInfoStrings->Get(INFO_CAPTION_LOGICAL_DRIVES));

	P3tr0viCh::TLogicalDrive * LogicalDrive;

	S1 = PCInfoStrings->Get(INFO_TEXT_LOGICAL_DRIVES_CAPTION_WITHOUT_NAME);
	S2 = PCInfoStrings->Get(INFO_TEXT_LOGICAL_DRIVES_CAPTION_WITH_NAME);
	S3 = PCInfoStrings->Get(INFO_TEXT_LOGICAL_DRIVES_INFO);

	for (int i = 0; i < SystemInfo->LogicalDrives->Count; i++) {
		LogicalDrive = (P3tr0viCh::TLogicalDrive*)
			SystemInfo->LogicalDrives->Items[i];

		if (IsEmpty(LogicalDrive->Label)) {
			StringListAdd(StringList, 1,
				Format(S1, ARRAYOFCONST((LogicalDrive->Letter))));
		}
		else {
			StringListAdd(StringList, 1,
				Format(S2, ARRAYOFCONST((LogicalDrive->Letter,
				LogicalDrive->Label))));
		}

		if (LogicalDrive->Total > 0) {
			StringListAdd(StringList, 2,
				Format(S3, ARRAYOFCONST((FormatBytes(LogicalDrive->Total,
				ByteNames), FormatBytes(LogicalDrive->Free, ByteNames),
				Floor(((Extended) LogicalDrive->Free / (Extended)
				LogicalDrive->Total) * 100.0)))));
		}
		else {
			StringListAdd(StringList, 2, "");
		}
	}

	// ----------- PHYSICAL DRIVES -------------------------------------------

	StringListAdd(StringList, 0,
		PCInfoStrings->Get(INFO_CAPTION_PHYSICAL_DRIVES));

	P3tr0viCh::TPhysicalDrive * PhysicalDrive;

	S1 = PCInfoStrings->Get(INFO_TEXT_PHYSICAL_DRIVES_CAPTION);
	S2 = PCInfoStrings->Get(INFO_TEXT_PHYSICAL_DRIVES_INFO);

	String LogicalDrives;
	String PhysicalDriveProduct;

	for (int i = 0; i < SystemInfo->PhysicalDrives->Count; i++) {
		PhysicalDrive = (P3tr0viCh::TPhysicalDrive*)
			SystemInfo->PhysicalDrives->Items[i];

		LogicalDrives = "";
		for (int j = 0; j < SystemInfo->LogicalDrives->Count; j++) {
			LogicalDrive = (P3tr0viCh::TLogicalDrive*)
				SystemInfo->LogicalDrives->Items[j];

			if (LogicalDrive->PhysicalDriveNum == i) {
				LogicalDrives =
					ConcatStrings(LogicalDrives, String(LogicalDrive->Letter) +
					":", ", ");
			}
		}

		if (IsEmpty(LogicalDrives)) {
			LogicalDrives =
				PCInfoStrings->Get(INFO_TEXT_PHYSICAL_DRIVES_NO_LOGICAL_DRIVES);
		}

		StringListAdd(StringList, 1,
			Format(S1, ARRAYOFCONST((i + 1, LogicalDrives))));

		PhysicalDriveProduct = Trim(PhysicalDrive->Product);

		if (PhysicalDrive->Size > 0) {
			if (IsEmpty(PhysicalDriveProduct)) {
				PhysicalDriveProduct = PCInfoStrings->Get(INFO_TEXT_UNKNOWN);
			}

			StringListAdd(StringList, 2,
				Format(S2, ARRAYOFCONST((PhysicalDriveProduct,
				FormatBytes(PhysicalDrive->Size, ByteNames)))));
		}
		else {
			StringListAdd(StringList, 2, "");

		}
	}

	// ----------- PRINTER ---------------------------------------------------

	if (!IsEmpty(SystemInfo->PrinterName)) {
		StringListAdd(StringList, 0, PCInfoStrings->Get(INFO_CAPTION_PRINTER));
		StringListAdd(StringList, 1, SystemInfo->PrinterName);
	}

	ByteNames->Free();
}

// ---------------------------------------------------------------------------
String GetDateTimeNow() {
	return FormatDateTime("yyyy.mm.dd hh-mm-ss", Now());
}
