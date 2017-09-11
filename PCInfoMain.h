// ---------------------------------------------------------------------------

#ifndef PCInfoMainH
#define PCInfoMainH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ToolWin.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>

#include "SystemInfo.h"

// ---------------------------------------------------------------------------
class TMain : public TForm {
__published: // IDE-managed Components

	TStatusBar *StatusBar;
	TPanel *PanelMain;
	TMemo *Memo;
	TCoolBar *CoolBar;
	TToolBar *ToolBar;
	TToolButton *tbtnSave;
	TToolButton *tbtnClose;
	TImageList *ImageList;
	TSaveDialog *SaveDialog;
	TToolButton *tbtnAbout;

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall tbtnCloseClick(TObject *Sender);
	void __fastcall tbtnSaveClick(TObject *Sender);
	void __fastcall tbtnAboutClick(TObject *Sender);

private: // User declarations
	void UpdateAbout();
	void UpdateInfo();

	void MemoAdd(int Level, String Text);

public: // User declarations
	__fastcall TMain(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TMain *Main;
// ---------------------------------------------------------------------------
#endif
