// ---------------------------------------------------------------------------

#pragma hdrstop

#include "PCInfoStrings.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

// ---------------------------------------------------------------------------
__fastcall TPCInfoStrings::TPCInfoStrings(TLanguageId Language) {
	FStrings = new TStringList();

	switch (Language) {
	case liEng:
		FStrings->Insert(siApplicationTitle, "System info");
		FStrings->Insert(siMainFormTitle, "System info");

		FStrings->Insert(siBtnSave, "Save");
		FStrings->Insert(siBtnAbout, "About");
		FStrings->Insert(siBtnClose, "Close");

		FStrings->Insert(siStatusBarVersion, "Version %s (%s)");

		FStrings->Insert(siTextSavedToFile, "Saved to file '%s'");

		FStrings->Insert(siBytesB, "b");
		FStrings->Insert(siBytesKb, "Kb");
		FStrings->Insert(siBytesMb, "Mb");
		FStrings->Insert(siBytesGb, "Gb");
		FStrings->Insert(siBytesTb, "Tb");

		FStrings->Insert(siInfoCaptionHostname, "Host name");

		FStrings->Insert(siInfoCaptionIpAddressSingle, "IP address");
		FStrings->Insert(siInfoCaptionIpAddressMultiple, "IP addreses");

		FStrings->Insert(siInfoCaptionAdapterSingle, "Net adapter");
		FStrings->Insert(siInfoCaptionAdapterMultiple, "Net adapters");

		FStrings->Insert(siInfoCaptionWindowsVersion, "Operating system");
		FStrings->Insert(siInfoCaptionMotherboard, "Motherboard");
		FStrings->Insert(siInfoCaptionCpu, "CPU");
		FStrings->Insert(siInfoCaptionRam, "RAM");
		FStrings->Insert(siInfoCaptionLogicalDrives, "Logical drives");
		FStrings->Insert(siInfoCaptionPhysicalDrives, "Physical drives");
		FStrings->Insert(siInfoCaptionPrinter, "Printer");
		FStrings->Insert(siInfoCaptionMonitorsSingle, "Monitor");
		FStrings->Insert(siInfoCaptionMonitorsMultiple, "Monitors");

		FStrings->Insert(siInfoTextUnknown, "Unknown");
		FStrings->Insert(siInfoTextLogicalDrivesCaptionWithName, "%s: (%s)");
		FStrings->Insert(siInfoTextLogicalDrivesCaptionWithoutName, "%s:");
		FStrings->Insert(siInfoTextLogicalDrivesInfo,
			"Total: %s; Free: %s (%d %%)");
		FStrings->Insert(siInfoTextPhysicalDrivesCaption, "Drive #%d (%s)");
		FStrings->Insert(siInfoTextPhysicalDrivesInfo, "%s; Total: %s");
		FStrings->Insert(siInfoTextPhysicalDrivesNoLogicalDrives,
			"no logical drives");

		break;
	case liDefault:
	default:
		FStrings->Insert(siApplicationTitle, "���������� � �������");
		FStrings->Insert(siMainFormTitle, "���������� � �������");

		FStrings->Insert(siBtnSave, "���������");
		FStrings->Insert(siBtnAbout, "� ���������");
		FStrings->Insert(siBtnClose, "�������");

		FStrings->Insert(siStatusBarVersion, "������ %s (%s)");

		FStrings->Insert(siTextSavedToFile, "��������� � ���� '%s'");

		FStrings->Insert(siBytesB, "�");
		FStrings->Insert(siBytesKb, "��");
		FStrings->Insert(siBytesMb, "��");
		FStrings->Insert(siBytesGb, "��");
		FStrings->Insert(siBytesTb, "��");

		FStrings->Insert(siInfoCaptionHostname, "��� ����������");

		FStrings->Insert(siInfoCaptionIpAddressSingle, "IP �����");
		FStrings->Insert(siInfoCaptionIpAddressMultiple, "IP ������");

		FStrings->Insert(siInfoCaptionAdapterSingle, "������� �������");
		FStrings->Insert(siInfoCaptionAdapterMultiple, "������� ��������");

		FStrings->Insert(siInfoCaptionWindowsVersion, "������������ �������");
		FStrings->Insert(siInfoCaptionMotherboard, "��������� �����");

		FStrings->Insert(siInfoCaptionCpu, "���������");
		FStrings->Insert(siInfoCaptionRam, "����������� ������");
		FStrings->Insert(siInfoCaptionLogicalDrives, "���������� �����");
		FStrings->Insert(siInfoCaptionPhysicalDrives, "���������� �����");
		FStrings->Insert(siInfoCaptionPrinter, "�������");
		FStrings->Insert(siInfoCaptionMonitorsSingle, "�������");
		FStrings->Insert(siInfoCaptionMonitorsMultiple, "��������");

		FStrings->Insert(siInfoTextUnknown, "����������");
		FStrings->Insert(siInfoTextLogicalDrivesCaptionWithName, "%s: (%s)");
		FStrings->Insert(siInfoTextLogicalDrivesCaptionWithoutName, "%s:");
		FStrings->Insert(siInfoTextLogicalDrivesInfo,
			"�����: %s; ��������: %s (%d %%)");
		FStrings->Insert(siInfoTextPhysicalDrivesCaption, "���� �%d (%s)");
		FStrings->Insert(siInfoTextPhysicalDrivesInfo, "%s; �����: %s");
		FStrings->Insert(siInfoTextPhysicalDrivesNoLogicalDrives,
			"��� ���������� ������");
	}
}

// ---------------------------------------------------------------------------
__fastcall TPCInfoStrings::~TPCInfoStrings() {
	FStrings->Free();
}

// ---------------------------------------------------------------------------
String TPCInfoStrings::Get(TStringId StringId) {
	return FStrings->Strings[StringId];
}
