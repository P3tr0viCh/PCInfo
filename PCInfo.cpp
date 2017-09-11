// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>

#include "UtilsMisc.h"
#include "UtilsStr.h"
#include "UtilsFiles.h"

#include "SystemInfo.h"

#include "PCInfoAdd.h"
#include "PCInfoStrings.h"

// ---------------------------------------------------------------------------
USEFORM("PCInfoMain.cpp", Main);

TPCInfoStrings *PCInfoStrings;

P3tr0viCh::TSystemInfo *SystemInfo;

// ---------------------------------------------------------------------------
void SaveToFile(String FileName) {
	TStrings *Strings = new TStringList();

	try {
		SystemInfo->Update();

		if (IsEmpty(FileName)) {
			FileName =
				FileInAppDir(SystemInfo->ComputerName + " " + GetDateTimeNow() +
				".txt");
		}

		GetSystemInfo(Strings, SystemInfo);

		Strings->SaveToFile(FileName);
	}
	__finally {
		SystemInfo->Free();
		Strings->Free();
	}
}

// ---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int) {
	try {
		Application->Initialize();
		Application->MainFormOnTaskBar = true;

		PCInfoStrings = new TPCInfoStrings(FindCmdLineSwitch("E") ?
			LANGUAGE_ENG : LANGUAGE_DEFAULT);

		SystemInfo = new P3tr0viCh::TSystemInfo();

		try {
			Application->Title = PCInfoStrings->Get(APPLICATION_TITLE);

			if (ParamCount() > 0) {
				String Param = AnsiUpperCase(ParamStr(1));

				if ((Param.Length() > 1) && (Param[1] == '/' ||
					Param[1] == '-')) {
					if (Param[2] == 'F') {
						SaveToFile(NULL);

						return 0;
					}
				}
			}

			Application->CreateForm(__classid(TMain), &Main);
			Application->Run();
		}
		__finally {
			SystemInfo->Free();
			PCInfoStrings->Free();
		}
	}
	catch (Exception &exception) {
		Application->ShowException(&exception);
	}
	catch (...) {
		try {
			throw Exception("");
		}
		catch (Exception &exception) {
			Application->ShowException(&exception);
		}
	}

	return 0;
}
// ---------------------------------------------------------------------------
