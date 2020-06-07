//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TaxesForm.h"
#include "FormFollowerUnit.h"
#include "TaxOperations.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormTaxes *FormTaxes;
//---------------------------------------------------------------------------
__fastcall TFormTaxes::TFormTaxes(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormTaxes::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action = caFree;
    int formID = 2;
    observer->SetState(formID);
}
//---------------------------------------------------------------------------
void __fastcall TFormTaxes::Edit1KeyPress(TObject *Sender, char &Key)
{
   if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormTaxes::BtnOKClick(TObject *Sender)
{
    //Lisätään tiedot LoginOperations-olioon
    taxOperations->AddEntry(Edit1->Text,Edit2->Text);
    taxOperations->SaveToFile("c:\\Laskutusohjelma\\verotus.txt");
}
//---------------------------------------------------------------------------

void __fastcall TFormTaxes::FormShow(TObject *Sender)
{
    AnsiString tel;
    AnsiString vak;

    taxOperations->LoadFromFile("c:\\Laskutusohjelma\\verotus.txt");
    if(taxOperations->CheckSize()!=0)
    {
        taxOperations->GetEntry(tel,vak);
        Edit1->Text = tel;
        Edit2->Text = vak;
    }
    else{
        Application->MessageBox("Tiedostossa ei ollut yhtään tietoa", "Henkilötietojen luku", MB_OK)==IDOK;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormTaxes::Edit2KeyPress(TObject *Sender, char &Key)
{
 if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------

