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
	TButton *ButtonScaleUp;
	TButton *ButtonScaleDown;
	void __fastcall Open1Click(TObject *Sender);
	void __fastcall Open2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall ButtonScaleUpClick(TObject *Sender);
	void __fastcall ButtonScaleDownClick(TObject *Sender);

private:
	bool Dragging;
    int StartX, StartY;
	int ImageOffsetX, ImageOffsetY;
	double ScaleFactor;
	void __fastcall ScaleImage(double Factor);
    TBitmap *OriginalBitmap;
public:
	__fastcall TForm1(TComponent* Owner);
    __fastcall ~TForm1();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
