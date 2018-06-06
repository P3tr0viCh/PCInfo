#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
typedef char _TCHAR;
#define _tmain main
#endif

#include <stdio.h>

#include <SystemInfo.h>

#include "UtilsFiles.h"

#include "PCInfoAdd.h"
#include "PCInfoStrings.h"

TPCInfoStrings *PCInfoStrings;

int _tmain(int argc, _TCHAR* argv[]) {
	TStrings *Strings = new TStringList();

	PCInfoStrings = new TPCInfoStrings
		(FindCmdLineSwitch(CMD_LINE_SWITCH_LANGUAGE_ENG) ? liEng : liDefault);

	P3tr0viCh::TSystemInfo *SystemInfo = new P3tr0viCh::TSystemInfo();

	try {
		try {
			SystemInfo->Update();
		}
		catch (Exception &exception) {
			wprintf(L"Exception: %s", exception.Message);

			return 100;
		}

		GetSystemInfo(Strings, SystemInfo);

		setlocale(LC_CTYPE, "RUS");

		if (FindCmdLineSwitch(CMD_LINE_SWITCH_SAVE_TO_FILE)) {
			String FileName =
				FileInAppDir(SystemInfo->ComputerName + " " + GetDateTimeNow() +
				".txt");

			Strings->SaveToFile(FileName);

			String S = Format(PCInfoStrings->Get(siTextSavedToFile),
				ARRAYOFCONST((FileName)));

			wprintf(L"%s", S);

			return 0;
		}

		for (int i = 0; i < Strings->Count; i++) {
			wprintf(L"%s\n", Strings->Strings[i]);
		}
	}
	__finally {
		SystemInfo->Free();
		PCInfoStrings->Free();
		Strings->Free();
	}

	return 0;
}
