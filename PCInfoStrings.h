// ---------------------------------------------------------------------------

#ifndef PCInfoStringsH
#define PCInfoStringsH

#include <System.Classes.hpp>

// ---------------------------------------------------------------------------
enum TLanguageId {
	LANGUAGE_DEFAULT, LANGUAGE_ENG
};

// ---------------------------------------------------------------------------
enum TStringId {
	APPLICATION_TITLE, MAIN_FORM_TITLE,

	BTN_SAVE, BTN_ABOUT, BTN_CLOSE,

	STATUS_BAR_VERSION,

	BYTES_B,
	BYTES_KB,
	BYTES_MB,
	BYTES_GB,
	BYTES_TB,

	INFO_CAPTION_HOSTNAME,
	INFO_CAPTION_IP_ADDRESS_SINGLE,
	INFO_CAPTION_IP_ADDRESS_MULTIPLE,
	INFO_CAPTION_WINDOWS_VERSION,
	INFO_CAPTION_MOTHERBOARD,
	INFO_CAPTION_CPU,
	INFO_CAPTION_RAM,
	INFO_CAPTION_LOGICAL_DRIVES,
	INFO_CAPTION_PHYSICAL_DRIVES,
	INFO_CAPTION_PRINTER,

	INFO_TEXT_UNKNOWN,
	INFO_TEXT_LOGICAL_DRIVES_CAPTION_WITH_NAME,
	INFO_TEXT_LOGICAL_DRIVES_CAPTION_WITHOUT_NAME,
	INFO_TEXT_LOGICAL_DRIVES_INFO,
	INFO_TEXT_PHYSICAL_DRIVES_CAPTION,
	INFO_TEXT_PHYSICAL_DRIVES_INFO,
	INFO_TEXT_PHYSICAL_DRIVES_NO_LOGICAL_DRIVES
};

// ---------------------------------------------------------------------------
class PACKAGE TPCInfoStrings : public TObject {
private:
	TStringList* FStrings;

public:
	__fastcall TPCInfoStrings(TLanguageId LanguageId);
	__fastcall ~TPCInfoStrings();

	String Get(TStringId StringId);
};
#endif
