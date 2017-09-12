// ---------------------------------------------------------------------------

#ifndef PCInfoAddH
#define PCInfoAddH

#include <System.Classes.hpp>

#include "UtilsStr.h"
#include "UtilsMisc.h"

#include "SystemInfo.h"

// ---------------------------------------------------------------------------
const String CMD_LINE_SWITCH_LANGUAGE_ENG = "E";
const String CMD_LINE_SWITCH_SAVE_TO_FILE = "F";

// ---------------------------------------------------------------------------
void GetSystemInfo(TStrings* StringList, P3tr0viCh::TSystemInfo *SystemInfo);

String GetDateTimeNow();
#endif
