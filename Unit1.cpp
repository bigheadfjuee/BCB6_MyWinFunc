//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream.h>
#include <fstream.h>

#pragma hdrstop

#include "Unit1.h"
#include "uMyWinFunc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
  : TForm(Owner)
{
  Memo1->Lines->Add(MyMac());
  Memo1->Lines->Add(GetAppVer());
}
//---------------------------------------------------------------------------

