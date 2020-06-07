//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "PersondetailForm.h"
#include "PersondetailOperations.h"
#include "MainForm.h"
#include "FormFollowerUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormPersondetail *FormPersondetail;
//---------------------------------------------------------------------------
__fastcall TFormPersondetail::TFormPersondetail(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormPersondetail::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action = caFree;
    int formID = 3;
    observer->SetState(formID);
}
//---------------------------------------------------------------------------
void __fastcall TFormPersondetail::Edit1KeyPress(TObject *Sender,
      char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //l‰hetet‰‰n Windosille viesti siirty‰ seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormPersondetail::Edit2KeyPress(TObject *Sender,
      char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //l‰hetet‰‰n Windosille viesti siirty‰ seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormPersondetail::Edit3KeyPress(TObject *Sender,
      char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //l‰hetet‰‰n Windosille viesti siirty‰ seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormPersondetail::Edit4KeyPress(TObject *Sender,
      char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //l‰hetet‰‰n Windosille viesti siirty‰ seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormPersondetail::Edit5KeyPress(TObject *Sender,
      char &Key)
{
     if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //l‰hetet‰‰n Windosille viesti siirty‰ seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------
void __fastcall TFormPersondetail::Edit6KeyPress(TObject *Sender,
      char &Key)
{
     if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //l‰hetet‰‰n Windosille viesti siirty‰ seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------
void __fastcall TFormPersondetail::Edit7KeyPress(TObject *Sender,
      char &Key)
{
     if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //l‰hetet‰‰n Windosille viesti siirty‰ seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------
void __fastcall TFormPersondetail::Edit8KeyPress(TObject *Sender,
      char &Key)
{
     if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //l‰hetet‰‰n Windosille viesti siirty‰ seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------
void __fastcall TFormPersondetail::Edit9KeyPress(TObject *Sender,
      char &Key)
{
     if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //l‰hetet‰‰n Windosille viesti siirty‰ seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------
void __fastcall TFormPersondetail::Edit10KeyPress(TObject *Sender,
      char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //l‰hetet‰‰n Windosille viesti siirty‰ seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormPersondetail::Edit11KeyPress(TObject *Sender,
      char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //l‰hetet‰‰n Windosille viesti siirty‰ seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------
//Funktiolla haetaan tiedot m‰‰ritellyst‰ tiedostosta
void __fastcall TFormPersondetail::btOpenFileClick(TObject *Sender)
{
    TListItem *row;
    AnsiString pNumber;
    AnsiString lName;
    AnsiString fName;
    AnsiString socCode;
    AnsiString date;
    AnsiString date2;
    AnsiString date3;
    AnsiString address;
    AnsiString postCode;
    AnsiString town;
    AnsiString city;
    AnsiString homeNumber;
    AnsiString gsm;
    AnsiString email;

    ListView1->Items->Clear();

    personOperations->SetCounter();

//    personOperations->LoadFromFile("c:\\Laskutusohjelma\\henkiltiedot.txt");
    int size = personOperations->GetSize();
    if(size!=0){
        for(int i=0; i< size; i++)
        {
            personOperations->GetEntry(i,pNumber,lName,fName,socCode,date,
                            date2,date3,address,postCode,town,city,
                            homeNumber,gsm,email);
            row = ListView1->Items->Add(); // uusi rivi
            row->Caption = pNumber;        // 1. sarakkeen arvo
            row->SubItems->Add(lName);     // 2. sarake
            row->SubItems->Add(fName);     // 3. sarake
            row->SubItems->Add(socCode);   // 4. sarake
            row->SubItems->Add(date);      // 5. Sarake
            row->SubItems->Add(date2);     // 6. Sarake
            row->SubItems->Add(date3);     // 7. Sarake
            row->SubItems->Add(address);   // 8. Sarake
            row->SubItems->Add(postCode);  // 9. Sarake
            row->SubItems->Add(town);      // 10. Sarake
            row->SubItems->Add(city);      // 11. Sarake
            row->SubItems->Add(homeNumber);// 12.Sarake
            row->SubItems->Add(gsm);       // 13.Sarake
            row->SubItems->Add(email);     // 14.Sarake
        }
    }
    else{
        Application->MessageBox("Tiedostossa ei ollut yht‰‰n tietoa", "Henkilˆtietojen luku", MB_OK)==IDOK;
    }
}
//---------------------------------------------------------------------------
//Funktiolla haetaan tiedot ITSE m‰‰ritellyst‰ tiedostosta
void __fastcall TFormPersondetail::btOpenFromFileClick(TObject *Sender)
{
    TListItem *row;
    AnsiString pNumber;
    AnsiString lName;
    AnsiString fName;
    AnsiString socCode;
    AnsiString date;
    AnsiString date2;
    AnsiString date3;
    AnsiString address;
    AnsiString postCode;
    AnsiString town;
    AnsiString city;
    AnsiString homeNumber;
    AnsiString gsm;
    AnsiString email;

 if (Application->MessageBox("Haetko tiedot levylt‰?", "Tiedostojen lataus", MB_YESNO)==IDYES)
    {
    if (FormMain->OpenDialog->Execute())
        {
            personOperations->LoadFromFile(FormMain->OpenDialog->FileName.c_str());
        }
    ListView1->Items->Clear();
    personOperations->SetCounter();

    int size = personOperations->GetSize();
    if(size!=0){
        for(int i=0; i< size; i++)
        {
            personOperations->GetEntry(i,pNumber,lName,fName,socCode,date,
                            date2,date3,address,postCode,town,city,
                            homeNumber,gsm,email);
            row = ListView1->Items->Add(); // uusi rivi
            row->Caption = pNumber;        // 1. sarakkeen arvo
            row->SubItems->Add(lName);     // 2. sarake
            row->SubItems->Add(fName);     // 3. sarake
            row->SubItems->Add(socCode);   // 4. sarake
            row->SubItems->Add(date);      // 5. Sarake
            row->SubItems->Add(date2);     // 6. Sarake
            row->SubItems->Add(date3);     // 7. Sarake
            row->SubItems->Add(address);   // 8. Sarake
            row->SubItems->Add(postCode);  // 9. Sarake
            row->SubItems->Add(town);      // 10. Sarake
            row->SubItems->Add(city);      // 11. Sarake
            row->SubItems->Add(homeNumber);// 12.Sarake
            row->SubItems->Add(gsm);       // 13.Sarake
            row->SubItems->Add(email);     // 14.Sarake
        }
         //Tulostetaan 1. k‰ytt‰j‰n tiedot myˆs edit-boxeihin
        /*personOperations->GetEntry(0, lName, fName, uID, pWD, usrR);
        LName->Text = lName;
        FName->Text = fName;
        UID->Text = uID;
        PWD->Text = pWD;
        UsrR->Text = usrR;*/
    }
    }
    else{
        Application->MessageBox("Tiedostossa ei ollut yht‰‰n tietoa", "K‰yttˆoikeustiedoston luku", MB_OK)==IDOK;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormPersondetail::btSaveClick(TObject *Sender)
{
     if (Application->MessageBox("Haluatko tallettaa tiedot tiedostoon?", "K‰yttˆoikeustiedostojen tallennus", MB_YESNO)==IDYES)
    {
        /*if(FormMain->SaveDialog->Execute()) // antaako k‰ytt‰j‰ tiedostonimen?
        {
            logins->SaveToFile(FormMain->SaveDialog->FileName.c_str());
        }*/
        personOperations->SaveToFile("c:\\Laskutusohjelma\\henktiedot.txt");
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormPersondetail::BtCreateNewClick(TObject *Sender)
{
    Edit1->Color = clWindow;
    Edit2->Color = clWindow;
    Edit3->Color = clWindow;
    Edit4->Color = clWindow;
    Edit5->Color = clWindow;
    Edit6->Color = clWindow;
    Edit7->Color = clWindow;
    Edit8->Color = clWindow;
    Edit9->Color = clWindow;
    Edit10->Color = clWindow;
    Edit11->Color = clWindow;

    Edit1->ReadOnly = false;
    Edit2->ReadOnly = false;
    Edit3->ReadOnly = false;
    Edit4->ReadOnly = false;
    Edit5->ReadOnly = false;
    Edit6->ReadOnly = false;
    Edit7->ReadOnly = false;
    Edit8->ReadOnly = false;
    Edit9->ReadOnly = false;
    Edit10->ReadOnly = false;
    Edit11->ReadOnly = false;

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
    Edit11->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TFormPersondetail::BtNewClick(TObject *Sender)
{
    if(Application->MessageBox("Haluatko luoda uuden k‰ytt‰j‰tiedoston?","Uuden k‰yttˆoikeustiedoston luonti",MB_YESNO)==ID_YES){
    //Haetaan vanha *.txt tiedosot, jossa voi olla tietoa
    //ja katsotaan onko siell‰ mit‰‰n. Jos on niin silti tuhotaan..
    personOperations->LoadFromFile("c:\\Laskutusohjelma\\usrs.txt");
    int size = personOperations->GetSize();
    if(size!=0){
        personOperations->DeleteAllEntries(); //Tyhjennet‰‰n kaikki oliot
        /*for(int i=0; i<size; i++)
            {
                logins->DeleteEntry(i);
            } */
        }
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
        Edit11->Text = "";
        ListView1->Items->Clear(); // Tyhjennet‰‰n ListView olio (ListItems)

        //personOperations->SaveToFile(":\\Laskutusohjelma\\usrs.txt");
    }
}
//---------------------------------------------------------------------------


void __fastcall TFormPersondetail::BtClearAllClick(TObject *Sender)
{
    //Tyhjennet‰‰n kaikki tiedot oliosta
    if(Application->MessageBox("Haluatko poistaa kaikki k‰yttˆoikeustiedostot", "K‰yttˆoikeustiedoston tyhjennys", MB_YESNO)==IDYES){
        personOperations->DeleteAllEntries();
        personOperations->DeleteFile("c:\\Laskutusohjelma\\henktiedot.txt");
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormPersondetail::BtClrChosenClick(TObject *Sender)
{
    int apu=personOperations->GetApu(); //Get counter number
    personOperations->DeleteEntry(apu); //Delete entry
}
//---------------------------------------------------------------------------

void __fastcall TFormPersondetail::BtnOKClick(TObject *Sender)
{
/*        if((LName->Text== "")&&(FName->Text== "")&&(UID->Text== "")
        &&(PWD->Text== "")&&(UsrR->Text=="")){
        ShowMessage("Anna kaikki tarvittavat tiedot");
    }
    else{*/

    //Lis‰t‰‰n tiedot LoginOperations-olioon
    personOperations->AddEntry( Edit4->Text,Edit5->Text, Edit6->Text,
                     Edit1->Text,Edit2->Text,Edit3->Text,Edit7->Text,
                      Edit8->Text,Edit9->Text,Edit10->Text,Edit11->Text,
                      Edit12->Text,Edit13->Text,Edit14->Text);

    //lis‰t‰‰n tiedot ListView-olioon
    TListItem *row;
    row = ListView1->Items->Add();       // --- uusi rivi
    row->Caption = Edit1->Text;           // 1.  sarake
    row->SubItems->Add(Edit2->Text);     // 2.  sarake
    row->SubItems->Add(Edit3->Text);     // 3.  sarake
    row->SubItems->Add(Edit4->Text);     // 4.  sarake
    row->SubItems->Add(Edit5->Text);     // 6.  sarake
    row->SubItems->Add(Edit6->Text);     // 7.  sarake
    row->SubItems->Add(Edit7->Text);     // 8.  sarake
    row->SubItems->Add(Edit8->Text);     // 9.  sarake
    row->SubItems->Add(Edit9->Text);     // 10. sarake
    row->SubItems->Add(Edit10->Text);    // 11. sarake
    row->SubItems->Add(Edit11->Text);    // 12. sarake
    row->SubItems->Add(Edit12->Text);    // 12. sarake
    row->SubItems->Add(Edit13->Text);    // 12. sarake
    row->SubItems->Add(Edit14->Text);    // 12. sarake


    //Tyhjennet‰‰n tiedot edit-boxeista
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
    Edit11->Text = "";
    Edit12->Text = "";
    Edit13->Text = "";
    Edit14->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TFormPersondetail::Edit12KeyPress(TObject *Sender,
      char &Key)
{
   if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //l‰hetet‰‰n Windosille viesti siirty‰ seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------

void __fastcall TFormPersondetail::Edit13KeyPress(TObject *Sender,
      char &Key)
{
   if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //l‰hetet‰‰n Windosille viesti siirty‰ seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------

void __fastcall TFormPersondetail::Edit14KeyPress(TObject *Sender,
      char &Key)
{
   if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //l‰hetet‰‰n Windosille viesti siirty‰ seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------

