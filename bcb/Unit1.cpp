//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
LibLiskApi *liskapi=NULL;
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	liskapi->InitAPI("http://test01.lisk.asia:7000");
	Memo1->Lines->Add("-------------Balance---------------");
	Memo1->Lines->Add(liskapi->Balance("18158154284022017392L"));
  
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	  liskapi=new LibLiskApi(ExtractFilePath(Application->ExeName)+"\\libliskApi.dll");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
     if(liskapi)delete liskapi;
}
//---------------------------------------------------------------------------

