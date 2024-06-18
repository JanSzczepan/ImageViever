//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner), Dragging(false), ImageOffsetX(0), ImageOffsetY(0), ScaleFactor(1.0)
{
	OriginalBitmap = new TBitmap();
}
__fastcall TForm1::~TForm1()
{
    delete OriginalBitmap;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OpenImage(TObject *Sender)
{
    if (OpenDialog1->Execute())
    {
        TGraphic *Graphic = nullptr;
        String FileExt = ExtractFileExt(OpenDialog1->FileName).LowerCase();
        if (FileExt == ".bmp")
            Graphic = new TBitmap();
        else if (FileExt == ".jpg" || FileExt == ".jpeg")
            Graphic = new TJPEGImage();
        else if (FileExt == ".png")
            Graphic = new TPngImage();
        if (Graphic)
        {
            try
            {
                Graphic->LoadFromFile(OpenDialog1->FileName);
                OriginalBitmap->Assign(Graphic);
                Image1->Picture->Bitmap->Assign(OriginalBitmap);
                Image1->Width = Image1->Picture->Width;
                Image1->Height = Image1->Picture->Height;
                ScaleFactor = 1.0;
                Image1->Repaint();
            }
            __finally
            {
                delete Graphic;
            }
        }
        else
        {
            ShowMessage("Unsupported image format.");
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::SaveImage(TObject *Sender)
{
	if (SaveDialog1->Execute())
    {
        Image1->Picture->SaveToFile(SaveDialog1->FileName);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RotateImageLeft(TObject *Sender)
{
	TBitmap *Bitmap = new TBitmap();
		try
		{
			Bitmap->Assign(Image1->Picture->Graphic);
			TBitmap *RotatedBitmap = new TBitmap();
			RotatedBitmap->Width = Bitmap->Height;
			RotatedBitmap->Height = Bitmap->Width;
			for (int x = 0; x < Bitmap->Width; x++)
			{
				for (int y = 0; y < Bitmap->Height; y++)
				{
					RotatedBitmap->Canvas->Pixels[y][Bitmap->Width - 1 - x] = Bitmap->Canvas->Pixels[x][y];
				}
			}
			Image1->Picture->Assign(RotatedBitmap);
			delete RotatedBitmap;
		}
		__finally
		{
			delete Bitmap;
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RotateImageRight(TObject *Sender)
{
	TBitmap *Bitmap = new TBitmap();
		try
		{
			Bitmap->Assign(Image1->Picture->Graphic);
			TBitmap *RotatedBitmap = new TBitmap();
			RotatedBitmap->Width = Bitmap->Height;
			RotatedBitmap->Height = Bitmap->Width;
			for (int x = 0; x < Bitmap->Width; x++)
			{
				for (int y = 0; y < Bitmap->Height; y++)
				{
					RotatedBitmap->Canvas->Pixels[Bitmap->Height - 1 - y][x] = Bitmap->Canvas->Pixels[x][y];
				}
			}
			Image1->Picture->Assign(RotatedBitmap);
			delete RotatedBitmap;
		}
		__finally
		{
			delete Bitmap;
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Dragging = true;
    StartX = X;
    StartY = Y;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
    if (Dragging)
    {
        ImageOffsetX += X - StartX;
        ImageOffsetY += Y - StartY;
        Image1->Left = ImageOffsetX;
        Image1->Top = ImageOffsetY;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Dragging = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ApplyScale(double Factor)
{
    ScaleFactor *= Factor;
    int NewWidth = static_cast<int>(OriginalBitmap->Width * ScaleFactor);
    int NewHeight = static_cast<int>(OriginalBitmap->Height * ScaleFactor);
    TBitmap *ScaledBitmap = new TBitmap();
    try
    {
        ScaledBitmap->SetSize(NewWidth, NewHeight);
        ScaledBitmap->Canvas->StretchDraw(Rect(0, 0, NewWidth, NewHeight), OriginalBitmap);
        Image1->Picture->Bitmap->Assign(ScaledBitmap);
        Image1->Width = NewWidth;
        Image1->Height = NewHeight;
        Image1->Repaint();
    }
    __finally
    {
        delete ScaledBitmap;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ScaleImageUp(TObject *Sender)
{
	ApplyScale(1.1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ScaleImageDown(TObject *Sender)
{
	ApplyScale(0.9);
}
//---------------------------------------------------------------------------

