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
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Open1Click(TObject *Sender)
{
	if (OpenDialog1->Execute())
	{
		Image1->Picture->LoadFromFile(OpenDialog1->FileName);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Open2Click(TObject *Sender)
{
	if (SaveDialog1->Execute())
    {
        Image1->Picture->SaveToFile(SaveDialog1->FileName);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
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

void __fastcall TForm1::Button2Click(TObject *Sender)
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

