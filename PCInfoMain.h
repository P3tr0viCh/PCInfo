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

// ---------------------------------------------------------------------------
class TMain : public TForm {
__published: // IDE-managed Components

	TStatusBar *StatusBar;
	TPanel *PanelMain;
	TMemo *Memo;

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, System::WideChar &Key);

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
