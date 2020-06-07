//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "CountSalaryForm.h"
#include "CountSalaryOperations.h"
#include "PersondetailOperations.h"
#include "FormFollowerUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormCountSalary *FormCountSalary;
//---------------------------------------------------------------------------
__fastcall TFormCountSalary::TFormCountSalary(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormCountSalary::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    int formID = 5;
    observer->SetState(formID);
    Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormCountSalary::Edit1KeyPress(TObject *Sender, char &Key)
{
 if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------

void __fastcall TFormCountSalary::Edit2KeyPress(TObject *Sender, char &Key)
{
 if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------

void __fastcall TFormCountSalary::Edit3KeyPress(TObject *Sender, char &Key)
{
 if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------

void __fastcall TFormCountSalary::Edit4KeyPress(TObject *Sender, char &Key)
{
 if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------

void __fastcall TFormCountSalary::Edit5KeyPress(TObject *Sender, char &Key)
{
 if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------

void __fastcall TFormCountSalary::Edit6KeyPress(TObject *Sender, char &Key)
{
 if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------

void __fastcall TFormCountSalary::Edit7KeyPress(TObject *Sender, char &Key)
{
 if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------

void __fastcall TFormCountSalary::Edit8KeyPress(TObject *Sender, char &Key)
{
 if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------

void __fastcall TFormCountSalary::Edit9KeyPress(TObject *Sender, char &Key)
{
 if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------

void __fastcall TFormCountSalary::Edit10KeyPress(TObject *Sender,
      char &Key)
{
 if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------

void __fastcall TFormCountSalary::Edit11KeyPress(TObject *Sender,
      char &Key)
{
 if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------

void __fastcall TFormCountSalary::Edit12KeyPress(TObject *Sender,
      char &Key)
{
 if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------

void __fastcall TFormCountSalary::Edit13KeyPress(TObject *Sender,
      char &Key)
{
 if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------

void __fastcall TFormCountSalary::Edit14KeyPress(TObject *Sender,
      char &Key)
{
 if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------

void __fastcall TFormCountSalary::Edit15KeyPress(TObject *Sender,
      char &Key)
{
 if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }    
}
//---------------------------------------------------------------------------

void __fastcall TFormCountSalary::Edit16KeyPress(TObject *Sender,
      char &Key)
{
 if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------


void __fastcall TFormCountSalary::BtnOKClick(TObject *Sender)
{
    //Lisätään tiedot LoginOperations-olioon
    salaryOperations->AddEntry(Edit1->Text,Edit2->Text,Edit3->Text,
                      Edit4->Text,Edit5->Text,Edit6->Text,Edit7->Text,
                      Edit8->Text,Edit9->Text,Edit10->Text, Edit11->Text,
                      Edit12->Text,Edit13->Text,Edit14->Text, Edit15->Text,
                      Edit16->Text,Edit17->Text,Edit18->Text, Edit19->Text);

    //lisätään tiedot ListView-olioon
    TListItem *row;
    row = ListView1->Items->Add();       // --- uusi rivi
    row->Caption = Edit1->Text;           // 1.  sarake
    row->SubItems->Add(Edit2->Text);     // 2.  sarake
    row->SubItems->Add(Edit3->Text);     // 3.  sarake
    row->SubItems->Add(Edit4->Text);     // 4.  sarake
    row->SubItems->Add(Edit5->Text);     // 6.  sarake
    row->SubItems->Add(Edit6->Text);     // 7.  sarake
    row->SubItems->Add(Edit7->Text);     // 7.  sarake
    row->SubItems->Add(Edit8->Text);     // 7.  sarake
    row->SubItems->Add(Edit9->Text);     // 10. sarake
    row->SubItems->Add(Edit12->Text);     // 7.  sarake

    //Tyhjennetään tiedot edit-boxeista
    /*Edit1->Text = "";
    Edit2->Text = "";
    Edit3->Text = "";
    Edit4->Text = "";
    Edit5->Text = "";
    Edit6->Text = "";
    Edit7->Text = "";
    Edit8->Text = "";
    Edit9->Text = "";
    Edit10->Text = "";
    Edit11->Text = "";*/
}
//---------------------------------------------------------------------------

void __fastcall TFormCountSalary::btSaveClick(TObject *Sender)
{
     if (Application->MessageBox("Haluatko tallettaa tiedot tiedostoon?", "Käyttöoikeustiedostojen tallennus", MB_YESNO)==IDYES)
    {
        /*if(FormMain->SaveDialog->Execute()) // antaako käyttäjä tiedostonimen?
        {
            logins->SaveToFile(FormMain->SaveDialog->FileName.c_str());
        }*/
        salaryOperations->SaveToFile("c:\\Laskutusohjelma\\palkkalaskelma.txt");
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormCountSalary::BitBtn1Click(TObject *Sender)
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

    AnsiString jee;
    AnsiString kee;
    AnsiString lee;
    AnsiString mee;
    AnsiString nee;


    ListView1->Items->Clear();

    salaryOperations->SetCounter();

    salaryOperations->LoadFromFile("c:\\Laskutusohjelma\\palkkalaskelma.txt");
    int size = salaryOperations->GetSize();
    if(size!=0){
        for(int i=0; i< size; i++)
        {
            salaryOperations->GetEntry(i,pNumber,lName,fName,socCode,date,
                            date2,date3,address,postCode,town,city,homeNumber,
                            gsm,email, jee, kee, lee, mee, nee);
            row = ListView1->Items->Add(); // uusi rivi
            row->Caption = pNumber;        // 1. sarakkeen arvo
            row->SubItems->Add(lName);     // 2. sarake
            row->SubItems->Add(fName);     // 3. sarake
            row->SubItems->Add(socCode);   // 4. sarake
            row->SubItems->Add(date);      // 5. Sarake
            row->SubItems->Add(date2);     // 6. Sarake
            row->SubItems->Add(date3);     // 7. Sarake
            row->SubItems->Add(address);      // 8. Sarake
            row->SubItems->Add(postCode);      // 9. Sarake
            row->SubItems->Add(homeNumber);     // 12.Sarake
        }
    }
    else{
        Application->MessageBox("Tiedostossa ei ollut yhtään tietoa", "Henkilötietojen luku", MB_OK)==IDOK;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormCountSalary::FormShow(TObject *Sender)
{
    AnsiString pNumber;
    AnsiString lName;
    AnsiString fName;
    AnsiString comboText;

    personOperations->SetCounter();

    personOperations->LoadFromFile("c:\\Laskutusohjelma\\henktiedot.txt");
    int size = personOperations->GetSize();
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

void __fastcall TFormCountSalary::ComboBox1KeyPress(TObject *Sender,
      char &Key)
{
        if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }        
}
//---------------------------------------------------------------------------

void __fastcall TFormCountSalary::ComboBox1Change(TObject *Sender)
{
    AnsiString pNumber;
    AnsiString lName;
    AnsiString fName;

     personOperations->GetEntry2((ComboBox1->ItemIndex),pNumber,lName,fName);
     Edit1->Text = pNumber;
     Edit2->Text = lName;
     Edit3->Text = fName;
     PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
}
//---------------------------------------------------------------------------
void __fastcall TFormCountSalary::ListView1Click(TObject *Sender)
{
   try{
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

        AnsiString jee;
        AnsiString kee;
        AnsiString lee;
        AnsiString mee;
        AnsiString nee;

        AnsiString lname = ListView1->Items->Item[ListView1->Selected->Index]->Caption;
        int pIndex=ListView1->Selected->Index;
        //Haetaan käyttäjän sukunimen ja "row-indexin" avulla indexi numero recordista
        int rIndex = salaryOperations->GetPerson(lName,pIndex);
        //Indexin avulla haetaan käyttäjän tiedot
        salaryOperations->GetEntry(rIndex,pNumber,lName,fName,socCode,date,
                            date2,date3,address,postCode,town,city,homeNumber,
                            gsm,email, jee, kee, lee, mee, nee);
        Edit1->Text = lName;
        Edit2->Text = fName;
        Edit3->Text = socCode;
        Edit4->Text = date;
        Edit5->Text = date2;
        Edit6->Text = date;
        Edit7->Text = address;
        Edit8->Text = postCode;
        Edit9->Text = homeNumber;
        Edit10->Text = gsm;
        Edit11->Text = email;
        Edit12->Text = jee;
        Edit13->Text = kee;
        Edit14->Text = lee;
        Edit15->Text = mee;
        Edit16->Text = nee;
     }
    catch(...)
    {
        ShowMessage("Yrität valita tietoa listan ulkopuolelta");
    }    
}
//---------------------------------------------------------------------------

void __fastcall TFormCountSalary::ListView1DblClick(TObject *Sender)
{
   try{
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

        AnsiString jee;
        AnsiString kee;
        AnsiString lee;
        AnsiString mee;
        AnsiString nee;

        AnsiString lname = ListView1->Items->Item[ListView1->Selected->Index]->Caption;
        int pIndex=ListView1->Selected->Index;
        //Haetaan käyttäjän sukunimen ja "row-indexin" avulla indexi numero recordista
        int rIndex = salaryOperations->GetPerson(lName,pIndex);
        //Indexin avulla haetaan käyttäjän tiedot
        salaryOperations->GetEntry(rIndex,pNumber,lName,fName,socCode,date,
                            date2,date3,address,postCode,town,city,homeNumber,
                            gsm,email, jee, kee, lee, mee, nee);
        Edit1->Text = lName;
        Edit2->Text = fName;
        Edit3->Text = socCode;
        Edit4->Text = date;
        Edit5->Text = date2;
        Edit6->Text = date;
        Edit7->Text = address;
        Edit8->Text = postCode;
        Edit9->Text = homeNumber;
        Edit10->Text = gsm;
        Edit11->Text = email;
        Edit12->Text = jee;
        Edit13->Text = kee;
        Edit14->Text = lee;
        Edit15->Text = mee;
        Edit16->Text = nee;
     }
    catch(...)
    {
        ShowMessage("Yrität valita tietoa listan ulkopuolelta");
    }     
}
//---------------------------------------------------------------------------

