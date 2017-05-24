// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PCInfoMain.h"

#include "UtilsStr.h"
#include "UtilsMisc.h"

#include "AboutFrm.h"

#include "PCInfoAdd.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMain *Main;

// ---------------------------------------------------------------------------
__fastcall TMain::TMain(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TMain::FormCreate(TObject *Sender) {
	SystemInfo = new P3tr0viCh::TSystemInfo();

	UpdateAbout();

	UpdateInfo();
}

// ---------------------------------------------------------------------------
void __fastcall TMain::FormKeyPress(TObject *Sender, System::WideChar &Key) {
	if (Key == char(27)) {
		Close();
	}
}

// ---------------------------------------------------------------------------
void TMain::UpdateAbout() {
	StatusBar->Panels->Items[0]->Text = "© Дураев К.П., ЦВТС, Уральская Сталь";
	StatusBar->Panels->Items[1]->Text =
		"Версия " + GetFileVer(Application->ExeName) + " (" +
		GetFileVerDate() + ")";
}

// ---------------------------------------------------------------------------
void TMain::UpdateInfo() {
	Memo->Clear();

	SystemInfo->Update();

	GetSystemInfo(Memo->Lines, SystemInfo);
}

// ---------------------------------------------------------------------------
void __fastcall TMain::tbtnCloseClick(TObject *Sender) {
	Close();
}

// ---------------------------------------------------------------------------
void __fastcall TMain::tbtnSaveClick(TObject *Sender) {
	SaveDialog->FileName = SystemInfo->ComputerName + " " + GetDateTimeNow();

	if (SaveDialog->Execute()) {
		Memo->Lines->SaveToFile(SaveDialog->FileName);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TMain::tbtnAboutClick(TObject *Sender) {
	ShowAbout(16);
}
// ---------------------------------------------------------------------------
