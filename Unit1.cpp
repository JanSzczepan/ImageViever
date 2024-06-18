#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner), Dragging(false), IsCropped(false), ImageOffsetX(0), ImageOffsetY(0), ScaleFactor(1.0)
{
	OriginalBitmap = new TBitmap();
	TempBitmap = new TBitmap();
    CropBitmap = new TBitmap();
}

__fastcall TForm1::~TForm1()
{
	delete OriginalBitmap;
	delete TempBitmap;
    delete CropBitmap;
}

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

void __fastcall TForm1::SaveImage(TObject *Sender)
{
	if (SaveDialog1->Execute())
    {
        Image1->Picture->SaveToFile(SaveDialog1->FileName);
    }
}

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

void __fastcall TForm1::StartCropping(TObject *Sender)
{
    Cropping = true;
    StatusBar1->SimpleText = "Select area to crop.";
}

void __fastcall TForm1::DrawCropRect()
{
    if (Cropping)
	{
        CropBitmap->Assign(OriginalBitmap);

        CropBitmap->Canvas->Pen->Style = psDash;
        CropBitmap->Canvas->Brush->Style = bsClear;
        CropBitmap->Canvas->Rectangle(CropStartX, CropStartY, CropEndX, CropEndY);

        Image1->Picture->Bitmap->Assign(CropBitmap);
    }
}

void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if (Cropping)
    {
        CropStartX = static_cast<int>(X / ScaleFactor);
        CropStartY = static_cast<int>(Y / ScaleFactor);
		CropEndX = CropStartX;
		CropEndY = CropStartY;
    }
    else
    {
        Dragging = true;
        StartX = X;
        StartY = Y;
    }
}

void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
    if (Cropping)
	{
        CropEndX = static_cast<int>(X / ScaleFactor);
        CropEndY = static_cast<int>(Y / ScaleFactor);
		DrawCropRect();
    }
    else if (Dragging)
    {
        ImageOffsetX += X - StartX;
        ImageOffsetY += Y - StartY;
        Image1->Left = ImageOffsetX;
        Image1->Top = ImageOffsetY;
    }
}

void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if (Cropping)
    {
        CropEndX = static_cast<int>(X / ScaleFactor);
        CropEndY = static_cast<int>(Y / ScaleFactor);
        Cropping = false;
        ApplyCrop();
        StatusBar1->SimpleText = "";
    }
    else
    {
        Dragging = false;
    }
}

void __fastcall TForm1::ButtonCropClick(TObject *Sender)
{
    StartCropping(Sender);
}

void __fastcall TForm1::ApplyCrop()
{
    if (CropStartX != CropEndX && CropStartY != CropEndY)
    {
        TRect CropRect(
            min(CropStartX, CropEndX),
            min(CropStartY, CropEndY),
            max(CropStartX, CropEndX),
            max(CropStartY, CropEndY)
        );

        TBitmap *CroppedBitmap = new TBitmap();
        try
        {
            CroppedBitmap->SetSize(CropRect.Width(), CropRect.Height());
            CroppedBitmap->Canvas->CopyRect(
                Rect(0, 0, CropRect.Width(), CropRect.Height()),
                Image1->Picture->Bitmap->Canvas,
                CropRect
            );
            Image1->Picture->Bitmap->Assign(CroppedBitmap);
            Image1->Width = CroppedBitmap->Width;
            Image1->Height = CroppedBitmap->Height;

            OriginalBitmap->Assign(CroppedBitmap);
            IsCropped = true;

            Image1->Repaint();
        }
        __finally
        {
            delete CroppedBitmap;
        }
    }
}


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

void __fastcall TForm1::ScaleImageUp(TObject *Sender)
{
	ApplyScale(1.1);
}

void __fastcall TForm1::ScaleImageDown(TObject *Sender)
{
	ApplyScale(0.9);
}


