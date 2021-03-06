// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PCInfoMain.h"

#include "UtilsStr.h"
#include "UtilsMisc.h"

#include "AboutFrm.h"

#include "PCInfoAdd.h"
#include "PCInfoStrings.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMain *Main;

extern TPCInfoStrings * PCInfoStrings;
extern P3tr0viCh::TSystemInfo * SystemInfo;

// ---------------------------------------------------------------------------
__fastcall TMain::TMain(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TMain::FormCreate(TObject *Sender) {
	Caption = PCInfoStrings->Get(siMainFormTitle);

	tbtnSave->Caption = PCInfoStrings->Get(siBtnSave);
	tbtnAbout->Caption = PCInfoStrings->Get(siBtnAbout);
	tbtnClose->Caption = PCInfoStrings->Get(siBtnClose);

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
	StatusBar->Panels->Items[0]->Text = "� ������ �.�., ��������� �����";
	StatusBar->Panels->Items[1]->Text =
		Format(PCInfoStrings->Get(siStatusBarVersion),
		ARRAYOFCONST((GetFileVer(Application->ExeName), GetFileVerDate())));
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
