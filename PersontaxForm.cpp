//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "PersontaxForm.h"
#include "FormFollowerUnit.h"       //Lomakkeen tarkkailija

#include "PersondetailOperations.h" //Tietojen käsittely

#include "PersontaxOperations.h"    //Tietojen tallennus ja käsittely
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormPersontax *FormPersontax;
//---------------------------------------------------------------------------
__fastcall TFormPersontax::TFormPersontax(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormPersontax::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action = caFree;
    int formID = 4;
    observer->SetState(formID);
}
//---------------------------------------------------------------------------
void __fastcall TFormPersontax::Edit0KeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormPersontax::Edit1KeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormPersontax::Edit2KeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormPersontax::Edit3KeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormPersontax::Edit4KeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormPersontax::Edit5KeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormPersontax::Edit6KeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormPersontax::Edit7KeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormPersontax::Edit8KeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormPersontax::Edit9KeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormPersontax::Edit10KeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormPersontax::ComboBox1KeyPress(TObject *Sender,
      char &Key)
{
        if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------

void __fastcall TFormPersontax::ComboBox1Change(TObject *Sender)
{
    AnsiString pNumber;
    AnsiString lName;
    AnsiString fName;

     personOperations->GetEntry2((ComboBox1->ItemIndex-1),pNumber,lName,fName);
     Edit0->Text = pNumber;
     Edit1->Text = lName;
     Edit2->Text = fName;
     PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
}
//---------------------------------------------------------------------------
//Funktiolla haetaan henkilön tiedot valmiiksi comboboxia varten
void __fastcall TFormPersontax::FormShow(TObject *Sender)
{
    AnsiString pNumber;
    AnsiString lName;
    AnsiString fName;
    AnsiString comboText;

    personOperations->SetCounter();

    personOperations->LoadFromFile("c:\\Laskutusohjelma\\henktiedot.txt");
    int size = personOperations->GetSize();
//    ShowMessage(size);
    if(size!=0){
        for(int i=0; i< size; i++)
        {
            personOperations->GetEntry2(i,pNumber,lName,fName);
            comboText = pNumber + ", " + lName + ", " + fName;
            ComboBox1->Items->Add(comboText); // uusi rivi
           /* ComboBox1->Items->Add(pNumber); // uusi rivi
            ComboBox1->Items->Add(lName);     // 2. sarake
            ComboBox1->Items->Add(fName);     // 3. sarake*/
        }
    }
    else{
        Application->MessageBox("Tiedostossa ei ollut yhtään tietoa", "Henkilötietojen luku", MB_OK)==IDOK;
    }
}
//---------------------------------------------------------------------------


void __fastcall TFormPersontax::BtnOKClick(TObject *Sender)
{
    //Lisätään tiedot LoginOperations-olioon
    persontaxOperations->AddEntry(Edit0->Text,
                      Edit1->Text,Edit2->Text,Edit3->Text,
                      Edit4->Text, Edit5->Text,Edit6->Text,
                      Edit7->Text,Edit8->Text,Edit9->Text,Edit10->Text);

    //lisätään tiedot ListView-olioon
    TListItem *row;
    row = ListView1->Items->Add();       // --- uusi rivi
    row->Caption = Edit0->Text;          // 1.  sarake
    row->SubItems->Add(Edit1->Text);     // 2.  sarake
    row->SubItems->Add(Edit2->Text);     // 3.  sarake
    row->SubItems->Add(Edit3->Text);     // 4.  sarake
    row->SubItems->Add(Edit4->Text);     // 5.  sarake
    row->SubItems->Add(Edit5->Text);     // 6.  sarake
    row->SubItems->Add(Edit6->Text);     // 7.  sarake
    row->SubItems->Add(Edit7->Text);     // 8.  sarake
    row->SubItems->Add(Edit8->Text);     // 9.  sarake
    row->SubItems->Add(Edit9->Text);     // 10. sarake
    row->SubItems->Add(Edit10->Text);    // 11. sarake

    //Tyhjennetään tiedot edit-boxeista
    //ComboBox1->
    Edit0->Text = "";
    Edit1->Text = "";
    Edit2->Text = "";
    Edit3->Text = "";
    Edit4->Text = "";
    Edit5->Text = "";
    Edit6->Text = "";
    Edit7->Text = "";
    Edit8->Text = "";
    Edit9->Text = "";
    Edit10->Text = "";
}
//---------------------------------------------------------------------------


void __fastcall TFormPersontax::BitBtn1Click(TObject *Sender)
{
    TListItem *row;
    AnsiString pNumber;
    AnsiString lName;
    AnsiString fName;
    AnsiString tiliNum;
    AnsiString pPros;
    AnsiString lPros;
    AnsiString vvTuloraja;
    AnsiString kkTuloraja;
    AnsiString kahdenvkTuloraja;
    AnsiString vkTuloraja;
    AnsiString pvTuloraja;

    ListView1->Items->Clear();

    persontaxOperations->DeleteAllEntries();
    persontaxOperations->SetCounter();
    persontaxOperations->LoadFromFile("c:\\Laskutusohjelma\\verotustiedot.txt");
    int size = persontaxOperations->GetSize();
    if(size!=0){
        for(int i=0; i< size; i++)
        {
            persontaxOperations->GetEntry(i,pNumber,lName,fName,tiliNum,pPros,
                                            lPros,vvTuloraja,kkTuloraja,kahdenvkTuloraja,
                                            vkTuloraja,pvTuloraja);
            row = ListView1->Items->Add(); // uusi rivi
            row->Caption = pNumber;              // 1. sarakkeen arvo
            row->SubItems->Add(lName);           // 2. sarake
            row->SubItems->Add(fName);           // 3. sarake
            row->SubItems->Add(tiliNum);         // 4. sarake
            row->SubItems->Add(pPros);           // 5. Sarake
            row->SubItems->Add(lPros);           // 6. Sarake
            row->SubItems->Add(vvTuloraja);      // 7. Sarake
            row->SubItems->Add(kkTuloraja);      // 8. Sarake
            row->SubItems->Add(kahdenvkTuloraja);// 9. Sarake
            row->SubItems->Add(vkTuloraja);      // 10.Sarake
            row->SubItems->Add(pvTuloraja);      // 11.Sarake
        }
    }
    else{
        Application->MessageBox("Tiedostossa ei ollut yhtään tietoa", "Verotustietojen luku", MB_OK)==IDOK;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormPersontax::BitBtn2Click(TObject *Sender)
{
     if (Application->MessageBox("Haluatko tallettaa tiedot tiedostoon?", "Käyttöoikeustiedostojen tallennus", MB_YESNO)==IDYES)
    {
        /*if(FormMain->SaveDialog->Execute()) // antaako käyttäjä tiedostonimen?
        {
            logins->SaveToFile(FormMain->SaveDialog->FileName.c_str());
        }*/
        persontaxOperations->SaveToFile("c:\\Laskutusohjelma\\verotustiedot.txt");
    }
}
//---------------------------------------------------------------------------

