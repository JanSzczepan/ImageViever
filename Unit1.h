//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TPanel *Panel1;
	TImage *Image1;
	TStatusBar *StatusBar1;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TMenuItem *N1;
	TMenuItem *Fil1;
	TMenuItem *Open1;
	TMenuItem *Open2;
	TMenuItem *Exit1;
	TMenuItem *Image2;
	TMenuItem *Rotateright1;
	TMenuItem *Rotateright2;
	TMenuItem *Crop1;
	TMenuItem *Help1;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	void __fastcall Open1Click(TObject *Sender);
	void __fastcall Open2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
