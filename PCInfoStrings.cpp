// ---------------------------------------------------------------------------

#pragma hdrstop

#include "PCInfoStrings.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

// ---------------------------------------------------------------------------
__fastcall TPCInfoStrings::TPCInfoStrings(TLanguageId Language) {
	FStrings = new TStringList();

	switch (Language) {
	case LANGUAGE_ENG:
		FStrings->Insert(APPLICATION_TITLE, "System info");
		FStrings->Insert(MAIN_FORM_TITLE, "System info");

		FStrings->Insert(BTN_SAVE, "Save");
		FStrings->Insert(BTN_ABOUT, "About");
		FStrings->Insert(BTN_CLOSE, "Close");

		FStrings->Insert(STATUS_BAR_VERSION, "Version %s (%s)");

		FStrings->Insert(TEXT_SAVED_TO_FILE, "Saved to file '%s'");

		FStrings->Insert(BYTES_B, "b");
		FStrings->Insert(BYTES_KB, "Kb");
		FStrings->Insert(BYTES_MB, "Mb");
		FStrings->Insert(BYTES_GB, "Gb");
		FStrings->Insert(BYTES_TB, "Tb");

		FStrings->Insert(INFO_CAPTION_HOSTNAME, "Host name");
		FStrings->Insert(INFO_CAPTION_IP_ADDRESS_SINGLE, "IP address");
		FStrings->Insert(INFO_CAPTION_IP_ADDRESS_MULTIPLE, "IP addreses");
		FStrings->Insert(INFO_CAPTION_WINDOWS_VERSION, "Operating system");
		FStrings->Insert(INFO_CAPTION_MOTHERBOARD, "Motherboard");
		FStrings->Insert(INFO_CAPTION_CPU, "CPU");
		FStrings->Insert(INFO_CAPTION_RAM, "RAM");
		FStrings->Insert(INFO_CAPTION_LOGICAL_DRIVES, "Logical drives");
		FStrings->Insert(INFO_CAPTION_PHYSICAL_DRIVES, "Physical drives");
		FStrings->Insert(INFO_CAPTION_PRINTER, "Printer");

		FStrings->Insert(INFO_TEXT_UNKNOWN, "Unknown");
		FStrings->Insert(INFO_TEXT_LOGICAL_DRIVES_CAPTION_WITH_NAME,
			"%s: (%s)");
		FStrings->Insert(INFO_TEXT_LOGICAL_DRIVES_CAPTION_WITHOUT_NAME, "%s:");
		FStrings->Insert(INFO_TEXT_LOGICAL_DRIVES_INFO,
			"Total: %s; Free: %s (%d %%)");
		FStrings->Insert(INFO_TEXT_PHYSICAL_DRIVES_CAPTION, "Drive #%d (%s)");
		FStrings->Insert(INFO_TEXT_PHYSICAL_DRIVES_INFO, "%s; Total: %s");
		FStrings->Insert(INFO_TEXT_PHYSICAL_DRIVES_NO_LOGICAL_DRIVES,
			"no logical drives");

		break;
	case LANGUAGE_DEFAULT:
	default: ;
		FStrings->Insert(APPLICATION_TITLE, "Информация о системе");
		FStrings->Insert(MAIN_FORM_TITLE, "Информация о системе");

		FStrings->Insert(BTN_SAVE, "Сохранить");
		FStrings->Insert(BTN_ABOUT, "О программе");
		FStrings->Insert(BTN_CLOSE, "Закрыть");

		FStrings->Insert(STATUS_BAR_VERSION, "Версия %s (%s)");

		FStrings->Insert(TEXT_SAVED_TO_FILE, "Сохранено в файл '%s'");

		FStrings->Insert(BYTES_B, "б");
		FStrings->Insert(BYTES_KB, "Кб");
		FStrings->Insert(BYTES_MB, "Мб");
		FStrings->Insert(BYTES_GB, "Гб");
		FStrings->Insert(BYTES_TB, "Тб");

		FStrings->Insert(INFO_CAPTION_HOSTNAME, "Имя компьютера");
		FStrings->Insert(INFO_CAPTION_IP_ADDRESS_SINGLE, "IP адрес");
		FStrings->Insert(INFO_CAPTION_IP_ADDRESS_MULTIPLE, "IP адреса");
		FStrings->Insert(INFO_CAPTION_WINDOWS_VERSION, "Операционная система");
		FStrings->Insert(INFO_CAPTION_MOTHERBOARD, "Системная плата");
		FStrings->Insert(INFO_CAPTION_CPU, "Процессор");
		FStrings->Insert(INFO_CAPTION_RAM, "Оперативная память");
		FStrings->Insert(INFO_CAPTION_LOGICAL_DRIVES, "Логические диски");
		FStrings->Insert(INFO_CAPTION_PHYSICAL_DRIVES, "Физические диски");
		FStrings->Insert(INFO_CAPTION_PRINTER, "Принтер");

		FStrings->Insert(INFO_TEXT_UNKNOWN, "Неизвестно");
		FStrings->Insert(INFO_TEXT_LOGICAL_DRIVES_CAPTION_WITH_NAME,
			"%s: (%s)");
		FStrings->Insert(INFO_TEXT_LOGICAL_DRIVES_CAPTION_WITHOUT_NAME, "%s:");
		FStrings->Insert(INFO_TEXT_LOGICAL_DRIVES_INFO,
			"Объём: %s; Свободно: %s (%d %%)");
		FStrings->Insert(INFO_TEXT_PHYSICAL_DRIVES_CAPTION, "Диск №%d (%s)");
		FStrings->Insert(INFO_TEXT_PHYSICAL_DRIVES_INFO, "%s; Объём: %s");
		FStrings->Insert(INFO_TEXT_PHYSICAL_DRIVES_NO_LOGICAL_DRIVES,
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
