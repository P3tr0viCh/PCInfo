// ---------------------------------------------------------------------------

#ifndef PCInfoStringsH
#define PCInfoStringsH

#include <System.Classes.hpp>

// ---------------------------------------------------------------------------
enum TLanguageId {
	liDefault, liEng
};

// ---------------------------------------------------------------------------
enum TStringId {
	siApplicationTitle, siMainFormTitle,

	siBtnSave, siBtnAbout, siBtnClose,

	siStatusBarVersion,

	siTextSavedToFile,

	siBytesB, siBytesKb, siBytesMb, siBytesGb, siBytesTb,

	siInfoCaptionHostname, siInfoCaptionIpAddressSingle,
	siInfoCaptionIpAddressMultiple, siInfoCaptionWindowsVersion,
	siInfoCaptionMotherboard, siInfoCaptionCpu, siInfoCaptionRam,
	siInfoCaptionLogicalDrives, siInfoCaptionPhysicalDrives,
	siInfoCaptionPrinter, siInfoCaptionMonitorsSingle,
	siInfoCaptionMonitorsMultiple,

	siInfoTextUnknown, siInfoTextLogicalDrivesCaptionWithName,
	siInfoTextLogicalDrivesCaptionWithoutName, siInfoTextLogicalDrivesInfo,
	siInfoTextPhysicalDrivesCaption, siInfoTextPhysicalDrivesInfo,
	siInfoTextPhysicalDrivesNoLogicalDrives
};

// ---------------------------------------------------------------------------
class PACKAGE TPCInfoStrings : public TObject {
private:
	TStringList * FStrings;

public:
	__fastcall TPCInfoStrings(TLanguageId LanguageId);
	__fastcall ~TPCInfoStrings();

	String Get(TStringId StringId);
};
#endif
