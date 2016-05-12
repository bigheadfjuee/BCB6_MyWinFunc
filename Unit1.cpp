//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream.h>
#include <fstream.h>

#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
AnsiString MyMac();

__fastcall TForm1::TForm1(TComponent* Owner)
  : TForm(Owner)
{
  Memo1->Lines->Add(MyMac());
}
//---------------------------------------------------------------------------
AnsiString MyMac()
{
  ifstream infile;
  bool blRead = true;
  string strMac;

  system("ipconfig /all > mac.txt");
  infile.open("mac.txt"); 
  while(infile && blRead) // read the file line by line
  {
    infile>>strMac;
    if(strMac.size() == 17) // XX-XX-XX-XX-XX-XX
    {
      // 如果 主機名稱 或其它資訊 剛好17個字的話，可能會出錯
      blRead=false;
    }
  }
  infile.close();

  if(blRead)
    strMac = ""; // 沒有網路卡

  remove("mac.txt");
  return strMac.c_str();
}

 