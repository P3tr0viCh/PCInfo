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

int _tmain(int argc, _TCHAR* argv[]) {
	TStrings *Strings = new TStringList();
	P3tr0viCh::TSystemInfo *SystemInfo = new P3tr0viCh::TSystemInfo();

	try {
		SystemInfo->Update();

		bool UseRusCaptions = !FindCmdLineSwitch("E");

		GetSystemInfo(Strings, SystemInfo, UseRusCaptions);

		setlocale(LC_CTYPE, "RUS");

		if (FindCmdLineSwitch("F")) {
			String FileName =
				FileInAppDir(SystemInfo->ComputerName + " " + GetDateTimeNow() +
				".txt");

			Strings->SaveToFile(FileName);

			String S = UseRusCaptions ? "Сохранено в файл" : "Saved to file";

			wprintf(L"%s '%s'", S, FileName);

			return 0;
		}

		for (int i = 0; i < Strings->Count; i++) {
			wprintf(L"%s\n", Strings->Strings[i]);
		}
	}
	__finally {
		SystemInfo->Free();
		Strings->Free();
	}

	return 0;
}
