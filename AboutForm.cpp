//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "AboutForm.h"
#include "MainForm.h"
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TFormAbout *FormAbout;
//--------------------------------------------------------------------- 
__fastcall TFormAbout::TFormAbout(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TFormAbout::OKButtonClick(TObject *Sender)
{
    FormAbout->Close();    
}
//---------------------------------------------------------------------------

