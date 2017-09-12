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
		FStrings->Insert(APPLICATION_TITLE, "���������� � �������");
		FStrings->Insert(MAIN_FORM_TITLE, "���������� � �������");

		FStrings->Insert(BTN_SAVE, "���������");
		FStrings->Insert(BTN_ABOUT, "� ���������");
		FStrings->Insert(BTN_CLOSE, "�������");

		FStrings->Insert(STATUS_BAR_VERSION, "������ %s (%s)");

		FStrings->Insert(TEXT_SAVED_TO_FILE, "��������� � ���� '%s'");

		FStrings->Insert(BYTES_B, "�");
		FStrings->Insert(BYTES_KB, "��");
		FStrings->Insert(BYTES_MB, "��");
		FStrings->Insert(BYTES_GB, "��");
		FStrings->Insert(BYTES_TB, "��");

		FStrings->Insert(INFO_CAPTION_HOSTNAME, "��� ����������");
		FStrings->Insert(INFO_CAPTION_IP_ADDRESS_SINGLE, "IP �����");
		FStrings->Insert(INFO_CAPTION_IP_ADDRESS_MULTIPLE, "IP ������");
		FStrings->Insert(INFO_CAPTION_WINDOWS_VERSION, "������������ �������");
		FStrings->Insert(INFO_CAPTION_MOTHERBOARD, "��������� �����");
		FStrings->Insert(INFO_CAPTION_CPU, "���������");
		FStrings->Insert(INFO_CAPTION_RAM, "����������� ������");
		FStrings->Insert(INFO_CAPTION_LOGICAL_DRIVES, "���������� �����");
		FStrings->Insert(INFO_CAPTION_PHYSICAL_DRIVES, "���������� �����");
		FStrings->Insert(INFO_CAPTION_PRINTER, "�������");

		FStrings->Insert(INFO_TEXT_UNKNOWN, "����������");
		FStrings->Insert(INFO_TEXT_LOGICAL_DRIVES_CAPTION_WITH_NAME,
			"%s: (%s)");
		FStrings->Insert(INFO_TEXT_LOGICAL_DRIVES_CAPTION_WITHOUT_NAME, "%s:");
		FStrings->Insert(INFO_TEXT_LOGICAL_DRIVES_INFO,
			"�����: %s; ��������: %s (%d %%)");
		FStrings->Insert(INFO_TEXT_PHYSICAL_DRIVES_CAPTION, "���� �%d (%s)");
		FStrings->Insert(INFO_TEXT_PHYSICAL_DRIVES_INFO, "%s; �����: %s");
		FStrings->Insert(INFO_TEXT_PHYSICAL_DRIVES_NO_LOGICAL_DRIVES,
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
