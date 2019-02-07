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
		S += PCInfoStrings->Get(siInfoTextUnknown);
	}
	else {
		S += Text;
	}

	Strings->Add(S);
}

// ---------------------------------------------------------------------------
String WindowsVersion(P3tr0viCh::TSystemInfo * SystemInfo) {
	String Result = SystemInfo->WindowsVersion->ProductName;
	if (IsEmpty(Result)) {
		return NULL;
	}

	if (!IsEmpty(SystemInfo->WindowsVersion->CSDVersion)) {
		Result = Result + SPACE + SystemInfo->WindowsVersion->CSDVersion;
	}

	String SWindowsVersion = SystemInfo->WindowsVersion->Is64Bit ?
		"x64" : "x32";

	Result = Result + SPACE + "[" + SWindowsVersion + "]";

	String Version = ConcatStrings(SystemInfo->WindowsVersion->ReleaseId,
		ConcatStrings(SystemInfo->WindowsVersion->CurrentBuild,
		SystemInfo->WindowsVersion->UBR, "."), "-");

	if (!IsEmpty(Version)) {
		Result = Result + SPACE + "(" + Version + ")";
	}

	return Result;
}

// ---------------------------------------------------------------------------
String ProcessorInfo(P3tr0viCh::TSystemInfo * SystemInfo) {
	String Result = SystemInfo->ProcessorName;

	String ProcessorSocket = P3tr0viCh::FormatProcessorSocket
		(SystemInfo->ProcessorSocket);
	if (!IsEmpty(ProcessorSocket)) {
		Result = Result + SPACE + "[" + ProcessorSocket + "]";
	}

	return Result;
}

// ---------------------------------------------------------------------------
String MemoryInfo(P3tr0viCh::TSystemInfo * SystemInfo, TStrings * ByteNames) {
	String Result = FormatBytes(SystemInfo->PhysMemory, ByteNames);

	if (SystemInfo->PhysMemoryCount > 0) {
		Result = Result + "; " + P3tr0viCh::FormatMemoryType
			(SystemInfo->PhysMemoryType) + " x" + SystemInfo->PhysMemoryCount;
	}

	return Result;
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

	ByteNames->Add(PCInfoStrings->Get(siBytesB));
	ByteNames->Add(PCInfoStrings->Get(siBytesKb));
	ByteNames->Add(PCInfoStrings->Get(siBytesMb));
	ByteNames->Add(PCInfoStrings->Get(siBytesGb));
	ByteNames->Add(PCInfoStrings->Get(siBytesTb));

	// ----------- HOST NAME -------------------------------------------------

	StringListAdd(StringList, 0, PCInfoStrings->Get(siInfoCaptionHostname));
	StringListAdd(StringList, 1, SystemInfo->ComputerName);

	// ----------- WINDOWS VERSION -------------------------------------------

	StringListAdd(StringList, 0,
		PCInfoStrings->Get(siInfoCaptionWindowsVersion));
	StringListAdd(StringList, 1, WindowsVersion(SystemInfo));

	// ----------- IP --------------------------------------------------------

	if (SystemInfo->IPAddressList->Count > 1) {
		StringListAdd(StringList, 0,
			PCInfoStrings->Get(siInfoCaptionIpAddressMultiple));
	}
	else {
		StringListAdd(StringList, 0,
			PCInfoStrings->Get(siInfoCaptionIpAddressSingle));
	}
	if (SystemInfo->IPAddressList->Count > 0) {
		for (int i = 0; i < SystemInfo->IPAddressList->Count; i++) {
			StringListAdd(StringList, 1, SystemInfo->IPAddressList->Strings[i]);
		}
	}
	else {
		StringListAdd(StringList, 1, NULL);
	}

	// ----------- MOTHERBOARD -----------------------------------------------

	StringListAdd(StringList, 0, PCInfoStrings->Get(siInfoCaptionMotherboard));
	StringListAdd(StringList, 1, SystemBoard(SystemInfo));

	// ----------- CPU -------------------------------------------------------

	StringListAdd(StringList, 0, PCInfoStrings->Get(siInfoCaptionCpu));
	StringListAdd(StringList, 1, ProcessorInfo(SystemInfo));

	// ----------- RAM -------------------------------------------------------

	StringListAdd(StringList, 0, PCInfoStrings->Get(siInfoCaptionRam));
	StringListAdd(StringList, 1, MemoryInfo(SystemInfo, ByteNames));

	// ----------- LOGICAL DRIVES --------------------------------------------

	StringListAdd(StringList, 0,
		PCInfoStrings->Get(siInfoCaptionLogicalDrives));

	P3tr0viCh::TLogicalDrive * LogicalDrive;

	S1 = PCInfoStrings->Get(siInfoTextLogicalDrivesCaptionWithoutName);
	S2 = PCInfoStrings->Get(siInfoTextLogicalDrivesCaptionWithName);
	S3 = PCInfoStrings->Get(siInfoTextLogicalDrivesInfo);

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
			StringListAdd(StringList, 2, NULL);
		}
	}

	// ----------- PHYSICAL DRIVES -------------------------------------------

	StringListAdd(StringList, 0,
		PCInfoStrings->Get(siInfoCaptionPhysicalDrives));

	P3tr0viCh::TPhysicalDrive * PhysicalDrive;

	S1 = PCInfoStrings->Get(siInfoTextPhysicalDrivesCaption);
	S2 = PCInfoStrings->Get(siInfoTextPhysicalDrivesInfo);

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
				PCInfoStrings->Get(siInfoTextPhysicalDrivesNoLogicalDrives);
		}

		StringListAdd(StringList, 1,
			Format(S1, ARRAYOFCONST((i + 1, LogicalDrives))));

		PhysicalDriveProduct = Trim(PhysicalDrive->Product);

		if (PhysicalDrive->Size > 0) {
			if (IsEmpty(PhysicalDriveProduct)) {
				PhysicalDriveProduct = PCInfoStrings->Get(siInfoTextUnknown);
			}

			StringListAdd(StringList, 2,
				Format(S2, ARRAYOFCONST((PhysicalDriveProduct,
				FormatBytes(PhysicalDrive->Size, ByteNames)))));
		}
		else {
			StringListAdd(StringList, 2, NULL);

		}
	}

	// ----------- PRINTER ---------------------------------------------------

	if (!IsEmpty(SystemInfo->PrinterName)) {
		StringListAdd(StringList, 0, PCInfoStrings->Get(siInfoCaptionPrinter));
		StringListAdd(StringList, 1, SystemInfo->PrinterName);
	}

	// ----------- MONITORS --------------------------------------------------

	if (SystemInfo->MonitorList->Count > 1) {
		StringListAdd(StringList, 0,
			PCInfoStrings->Get(siInfoCaptionMonitorsMultiple));
	}
	else {
		StringListAdd(StringList, 0,
			PCInfoStrings->Get(siInfoCaptionMonitorsSingle));
	}
	if (SystemInfo->MonitorList->Count > 0) {
		for (int i = 0; i < SystemInfo->MonitorList->Count; i++) {
			StringListAdd(StringList, 1, SystemInfo->MonitorList->Strings[i]);
		}
	}
	else {
		StringListAdd(StringList, 1, NULL);
	}

	ByteNames->Free();
}

// ---------------------------------------------------------------------------
String GetDateTimeNow() {
	return FormatDateTime("yyyy.mm.dd hh-mm-ss", Now());
}
