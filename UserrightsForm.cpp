//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UserrightsForm.h"
#include "LoginOperations.h"
#include "FormFollowerUnit.h"
#include "MainForm.h"
#include "Person.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormUserrights *FormUserrights;
//---------------------------------------------------------------------------
__fastcall TFormUserrights::TFormUserrights(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormUserrights::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    if(logins->GetSize()!=0)
    {
    if (Application->MessageBox("Haluatko tallentaa tiedot tiedostoon?", "Käyttöoikeus ikkunan sulkeminen", MB_YESNO)==IDYES)
        {
        /*if(FormMain->SaveDialog->Execute()) // antaako käyttäjä tiedostonimen?
        {
            logins->SaveToFile(FormMain->SaveDialog->FileName.c_str());
        } */
        logins->SaveToFile("c:\\Laskutusohjelma\\usrs.txt");
        }
    }
    Action = caFree;

    int formID = 1;
    observer->SetState(formID);
}
//---------------------------------------------------------------------------

void __fastcall TFormUserrights::LNameKeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormUserrights::FNameKeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormUserrights::UIDKeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormUserrights::PWDKeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormUserrights::UsrRKeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        if((UsrR->Text=="r--")||(UsrR->Text=="rw-")||(UsrR->Text=="rwx")){
            Key = 0; // poistetaan napin painallus
            PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
        }
        else{
            ShowMessage("Väärin annetut oikeudet");
            UsrR->Text="";
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormUserrights::BtnOKClick(TObject *Sender)
{
    if((LName->Text== "")&&(FName->Text== "")&&(UID->Text== "")
        &&(PWD->Text== "")&&(UsrR->Text=="")){
        ShowMessage("Anna kaikki tarvittavat tiedot");
    }
    else{
         //Lisätään tiedot LoginOperations-olioon
        logins->AddEntry(LName->Text, FName->Text, UID->Text,PWD->Text,UsrR->Text);
        //lisätään tiedot ListView-olioon
        TListItem *row;
        row = ListView1->Items->Add(); // uusi rivi
        row->Caption = LName->Text; // 1. sarakkeen arvo
        row->SubItems->Add(FName->Text);
        row->SubItems->Add(UID->Text); // 2. sarake
        row->SubItems->Add(PWD->Text); // 3. sarake
        row->SubItems->Add(UsrR->Text); // 4. sarake

        //Tyhjennetään tiedot edit-boxeista
        LName->Text= "";
        FName->Text= "";
        UID->Text= "";
        PWD->Text= "";
        UsrR->Text="";
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormUserrights::BtClearAllClick(TObject *Sender)
{
    //Tyhjennetään kaikki tiedot oliosta
    if(Application->MessageBox("Haluatko poistaa kaikki käyttöoikeustiedostot", "Käyttöoikeustiedoston tyhjennys", MB_YESNO)==IDYES){
        logins->DeleteAllEntries();
        logins->DeleteFile("c:\\Laskutusohjelma\\usrs.txt");
    }
}
//---------------------------------------------------------------------------


void __fastcall TFormUserrights::BtClrChosenClick(TObject *Sender)
{
     int apu=logins->GetApu(); //Get counter number
    logins->DeleteEntry(apu); //Delete entry
}
//---------------------------------------------------------------------------
//Haetaan tiedostosta tiedot (A. OpenDialog tai B. "c:\\Laskutusohjelma\\usrs.txt"
void __fastcall TFormUserrights::BtNewClick(TObject *Sender)
{
    if(Application->MessageBox("Haluatko luoda uuden käyttäjätiedoston?","Uuden käyttöoikeustiedoston luonti",MB_YESNO)==ID_YES){
        //Haetaan vanha *.txt tiedosot, jossa voi olla tietoa
        //ja katsotaan onko siellä mitään. Jos on niin silti tuhotaan..
        logins->LoadFromFile("c:\\Laskutusohjelma\\usrs.txt");
        int size = logins->GetSize();
        if(size!=0){
            logins->DeleteAllEntries(); //Tyhjennetään kaikki oliot
            /*for(int i=0; i<size; i++)
            {
                logins->DeleteEntry(i);
            } */
        }
        LName->Text= "";
        FName->Text= "";
        UID->Text= "";
        PWD->Text= "";
        UsrR->Text="";
        ListView1->Items->Clear(); // Tyhjennetään ListView olio (ListItems)

        //      logins->SaveToFile(":\\Laskutusohjelma\\usrs.txt");
    }
}
//---------------------------------------------------------------------------



void __fastcall TFormUserrights::BtnOKKeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormUserrights::SBPreviousClick(TObject *Sender)
{
    AnsiString lName;
    AnsiString fName;
    AnsiString uID;
    AnsiString pWD;
    AnsiString usrR;

    logins->DecInput();
     int joo = logins->GetSize();
        for (int i=0; i< joo; i++)
         {
            if(logins->GetCounter()==i)
            {
            //apu=i;
                logins->GetEntry(i, lName, fName, uID, pWD, usrR);
                LName->Text = lName;
                FName->Text = fName;
                UID->Text = uID;
                PWD->Text = pWD;
                UsrR->Text = usrR;
            }
        }
    int job=logins->GetCounter();
    ShowMessage(job);
}
//---------------------------------------------------------------------------

void __fastcall TFormUserrights::SBNextClick(TObject *Sender)
{
    AnsiString lName;
    AnsiString fName;
    AnsiString uID;
    AnsiString pWD;
    AnsiString usrR;

    logins->IncInput();
     int joo = logins->GetSize();
        for (int i=0; i< joo; i++)
         {
            if(logins->GetCounter()==i)
            {
                //apu=i; //hmm apu kts. loginops.
                logins->GetEntry(i, lName, fName, uID, pWD, usrR);
                LName->Text = lName;
                FName->Text = fName;
                UID->Text = uID;
                PWD->Text = pWD;
                UsrR->Text = usrR;
            }
        }

    int job=logins->GetCounter();
    ShowMessage(job);
}
//---------------------------------------------------------------------------
//Formin avauksen yhteydessä haetaan tiedot valmiiksi esille
//ja tarkistetaan käyttöoikeudet
void __fastcall TFormUserrights::FormShow(TObject *Sender)
{
    TListItem *row;
    AnsiString lName;
    AnsiString fName;
    AnsiString uID;
    AnsiString pWD;
    AnsiString usrR;

    //Tyhjennetään varmuuden vuoksi aina listview-olio (ei pak.)
    ListView1->Items->Clear();

    //Haetaan tiedoston koko ja tulostetaan tiedot listviewiin
    int size = logins->GetSize();
    if(size!=0){
        for(int i=0; i< size; i++){
            logins->GetEntry(i,lName, fName, uID, pWD, usrR);
            row = ListView1->Items->Add(); // uusi rivi
            row->Caption = lName;          // 1. sarakkeen arvo
            row->SubItems->Add(fName);     // 2. sarake
            row->SubItems->Add(uID);       // 3. sarake
            row->SubItems->Add(pWD);       // 4. sarake
            row->SubItems->Add(usrR);      //5.Sarake
        }
        //Tulostetaan 1. käyttäjän tiedot myös edit-boxeihin
        logins->GetEntry(0, lName, fName, uID, pWD, usrR);
        LName->Text = lName;
        FName->Text = fName;
        UID->Text = uID;
        PWD->Text = pWD;
        UsrR->Text = usrR;
    }
    else{
        Application->MessageBox("Tiedostossa ei ollut yhtään tietoa", "Käyttöoikeustiedoston luku", MB_OK)==IDOK;
    }
}
//---------------------------------------------------------------------------
//Käytetään luomaan uudet käyttöoikeudet henkilölle
void __fastcall TFormUserrights::BtCreateNewClick(TObject *Sender)
{
    LName->Color = clWindow;
    FName->Color = clWindow;
    UID->Color = clWindow;
    PWD->Color = clWindow;
    UsrR->Color = clWindow;
    LName->ReadOnly = false;
    FName->ReadOnly = false;
    UID->ReadOnly = false;
    PWD->ReadOnly = false;
    UsrR->ReadOnly = false;
    LName->Text = "";
    FName->Text = "";
    UID->Text = "";
    PWD->Text = "";
    UsrR->Text = "";

}
//---------------------------------------------------------------------------
//Hiiren tupla-klikkauksella valitaan jonkin henkilön tiedot, jotka
//tuodaan näytölle (ediotinti sallittu)
void __fastcall TFormUserrights::ListView1DblClick(TObject *Sender)
{
    //Ensin edit-boxien readonly - falseksi ja vaihdetaan
    //edit boxien väri ediointi väriksi (valkoinen)
    LName->Color = clWindow;
    FName->Color = clWindow;
    UID->Color = clWindow;
    PWD->Color = clWindow;
    UsrR->Color = clWindow;
    LName->ReadOnly = false;
    FName->ReadOnly = false;
    UID->ReadOnly = false;
    PWD->ReadOnly = false;
    UsrR->ReadOnly = false;

    // TListItem *row;
    //TString *j = new TString;
    //Otetaan talteen käyttäjän sukunim
    AnsiString lname = ListView1->Items->Item[ListView1->Selected->Index]->Caption;
    int pIndex=ListView1->Selected->Index;

    //row = ListView1->Items->Item[ListView1->Selected->Index];
    //AnsiString user = row->SubItems->GetText();

    //Haetaan käyttäjän sukunimen ja "row-indexin" avulla indexi numero recordista
    int rIndex = logins->GetUsers(lname, pIndex);
    //Indexin avulla haetaan käyttäjän tiedot
    AnsiString lName;
    AnsiString fName;
    AnsiString uID;
    AnsiString pWD;
    AnsiString usrR;
    logins->GetEntry(rIndex, lName, fName, uID, pWD, usrR);
    LName->Text = lName;
    FName->Text = fName;
    UID->Text = uID;
    PWD->Text = pWD;
    UsrR->Text = usrR;
}
//---------------------------------------------------------------------------
//Hiiren tupla-klikkauksella valitaan jonkin henkilön tiedot, jotka
//tuodaan näytölle (ediotinti EI OLE sallittu)
void __fastcall TFormUserrights::ListView1Click(TObject *Sender)
{
   try{
        AnsiString lname = ListView1->Items->Item[ListView1->Selected->Index]->Caption;
        int pIndex=ListView1->Selected->Index;
        //Haetaan käyttäjän sukunimen ja "row-indexin" avulla indexi numero recordista
        int rIndex = logins->GetUsers(lname, pIndex);
        //Indexin avulla haetaan käyttäjän tiedot
        AnsiString lName;
        AnsiString fName;
        AnsiString uID;
        AnsiString pWD;
        AnsiString usrR;
        logins->GetEntry(rIndex, lName, fName, uID, pWD, usrR);
        LName->Text = lName;
        FName->Text = fName;
        UID->Text = uID;
        PWD->Text = pWD;
        UsrR->Text = usrR;
    }catch(...)
    {
        ShowMessage("Yrität valita tietoa listan ulkopuolelta");
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormUserrights::BtSave1Click(TObject *Sender)
{
    if (Application->MessageBox("Haluatko tallettaa tiedot tiedostoon?", "Käyttöoikeustiedostojen tallennus", MB_YESNO)==IDYES)
    {
        /*if(FormMain->SaveDialog->Execute()) // antaako käyttäjä tiedostonimen?
        {
            logins->SaveToFile(FormMain->SaveDialog->FileName.c_str());
        }*/
        logins->SaveToFile("c:\\Laskutusohjelma\\usrs.txt");
    }    
}
//---------------------------------------------------------------------------

void __fastcall TFormUserrights::BtGetClick(TObject *Sender)
{
  TListItem *row;
    AnsiString lName;
    AnsiString fName;
    AnsiString uID;
    AnsiString pWD;
    AnsiString usrR;

 /*if (Application->MessageBox("Haetko tiedot levyltä?", "Sanoma", MB_YESNO)==IDYES)
    {
    if (FormMain->OpenDialog->Execute())
        {
            logins->LoadFromFile(FormMain->OpenDialog->FileName.c_str());
        }*/
    ListView1->Items->Clear();
    logins->SetCounter();

//    logins->LoadFromFile("c:\\Laskutusohjelma\\usrs.txt");
    int size = logins->GetSize();
    if(size!=0){
        for(int i=0; i< size; i++)
        {
            logins->GetEntry(i,lName, fName, uID, pWD, usrR);
            row = ListView1->Items->Add(); // uusi rivi
            row->Caption = lName; // 1. sarakkeen arvo
            row->SubItems->Add(fName); // 2. sarake
            row->SubItems->Add(uID); // 3. sarake
            row->SubItems->Add(pWD); // 4. sarake
            row->SubItems->Add(usrR); //5.Sarake
        }
         //Tulostetaan 1. käyttäjän tiedot myös edit-boxeihin
        /*logins->GetEntry(0, lName, fName, uID, pWD, usrR);
        LName->Text = lName;
        FName->Text = fName;
        UID->Text = uID;
        PWD->Text = pWD;
        UsrR->Text = usrR;*/
    }
    else{
        Application->MessageBox("Tiedostossa ei ollut yhtään tietoa", "Käyttöoikeustiedoston luku", MB_OK)==IDOK;
    }    
}
//---------------------------------------------------------------------------

