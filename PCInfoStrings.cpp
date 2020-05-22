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
		FStrings->Insert(siApplicationTitle, "Информация о системе");
		FStrings->Insert(siMainFormTitle, "Информация о системе");

		FStrings->Insert(siBtnSave, "Сохранить");
		FStrings->Insert(siBtnAbout, "О программе");
		FStrings->Insert(siBtnClose, "Закрыть");

		FStrings->Insert(siStatusBarVersion, "Версия %s (%s)");

		FStrings->Insert(siTextSavedToFile, "Сохранено в файл '%s'");

		FStrings->Insert(siBytesB, "б");
		FStrings->Insert(siBytesKb, "Кб");
		FStrings->Insert(siBytesMb, "Мб");
		FStrings->Insert(siBytesGb, "Гб");
		FStrings->Insert(siBytesTb, "Тб");

		FStrings->Insert(siInfoCaptionHostname, "Имя компьютера");

		FStrings->Insert(siInfoCaptionIpAddressSingle, "IP адрес");
		FStrings->Insert(siInfoCaptionIpAddressMultiple, "IP адреса");

		FStrings->Insert(siInfoCaptionAdapterSingle, "Сетевой адаптер");
		FStrings->Insert(siInfoCaptionAdapterMultiple, "Сетевые адаптеры");

		FStrings->Insert(siInfoCaptionWindowsVersion, "Операционная система");
		FStrings->Insert(siInfoCaptionMotherboard, "Системная плата");

		FStrings->Insert(siInfoCaptionCpu, "Процессор");
		FStrings->Insert(siInfoCaptionRam, "Оперативная память");
		FStrings->Insert(siInfoCaptionLogicalDrives, "Логические диски");
		FStrings->Insert(siInfoCaptionPhysicalDrives, "Физические диски");
		FStrings->Insert(siInfoCaptionPrinter, "Принтер");
		FStrings->Insert(siInfoCaptionMonitorsSingle, "Монитор");
		FStrings->Insert(siInfoCaptionMonitorsMultiple, "Мониторы");

		FStrings->Insert(siInfoTextUnknown, "Неизвестно");
		FStrings->Insert(siInfoTextLogicalDrivesCaptionWithName, "%s: (%s)");
		FStrings->Insert(siInfoTextLogicalDrivesCaptionWithoutName, "%s:");
		FStrings->Insert(siInfoTextLogicalDrivesInfo,
			"Объём: %s; Свободно: %s (%d %%)");
		FStrings->Insert(siInfoTextPhysicalDrivesCaption, "Диск №%d (%s)");
		FStrings->Insert(siInfoTextPhysicalDrivesInfo, "%s; Объём: %s");
		FStrings->Insert(siInfoTextPhysicalDrivesNoLogicalDrives,
			"нет логических дисков");
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
