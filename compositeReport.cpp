//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "compositeReport.h"

#include "PaySlipReport.h"
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

void __fastcall TForm1::QRCompositeReport1AddReports(TObject *Sender)
{
//((TQRCompositeReport*)Sender)->Reports->Add(QuickReport1);        
}
//---------------------------------------------------------------------------
