//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "CorporationForm.h"
#include "FormFollowerUnit.h"
#include "CorporationOperations.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormCorporation *FormCorporation;
//---------------------------------------------------------------------------
__fastcall TFormCorporation::TFormCorporation(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormCorporation::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action = caFree;
    int formID = 0;
    observer->SetState(formID);
}
//---------------------------------------------------------------------------
void __fastcall TFormCorporation::Edit1KeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormCorporation::Edit2KeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormCorporation::Edit3KeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormCorporation::Edit4KeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormCorporation::Edit5KeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormCorporation::Edit6KeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormCorporation::Edit7KeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormCorporation::Edit8KeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------

void __fastcall TFormCorporation::Edit9KeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------

void __fastcall TFormCorporation::BtnOKClick(TObject *Sender)
{
    //Lisätään tiedot LoginOperations-olioon
    corporationOperations->AddEntry(Edit1->Text,Edit2->Text,Edit3->Text,
                      Edit4->Text, Edit5->Text,Edit6->Text,
                      Edit7->Text,Edit8->Text,Edit9->Text);
    //Ja tallennetaan tiedot tiedostoon..
    corporationOperations->SaveToFile("c:\\Laskutusohjelma\\yritystiedot.txt");
}
//---------------------------------------------------------------------------

void __fastcall TFormCorporation::FormShow(TObject *Sender)
{
    AnsiString name;
    AnsiString address;
    AnsiString postalCode;
    AnsiString city;
    AnsiString land;
    AnsiString phoneNumber;
    AnsiString fax;
    AnsiString email;
    AnsiString homePages;

    corporationOperations->LoadFromFile("c:\\Laskutusohjelma\\yritystiedot.txt");

    corporationOperations->GetEntry(name,address,postalCode,city,
    land,phoneNumber,fax,email,homePages);

    Edit1->Text = name;
    Edit2->Text = address;
    Edit3->Text = postalCode;
    Edit4->Text = city;
    Edit5->Text = land;
    Edit6->Text = phoneNumber;
    Edit7->Text = fax;
    Edit8->Text = email;
    Edit9->Text = homePages;
}
//---------------------------------------------------------------------------

