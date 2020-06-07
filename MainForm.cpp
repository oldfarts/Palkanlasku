//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
#include "FormFollowerUnit.h" //Lomakkeiden tarkkailija yksikkö

#include "CorporationForm.h"  //ID 0 (FormFollowerUnit)
#include "CorporationOperations.h"
#include "UserrightsForm.h"   //ID 1
#include "TaxesForm.h"        //ID 2
#include "PersondetailForm.h" //ID 3
#include "PersontaxForm.h"    //ID 4
#include "CountSalaryForm.h"  //ID 5
#include "CountSalaryOperations.h"
//#include "CompositeReport.H"

#include "LoginForm.h"        //Sisäänkirjautumisen lomake
#include "LoginOperations.h"  //ed. operaatiot

#include <Printers.hpp>       //Tulostin operaatiot
#include "PaySlipDialogi.h"   //Palkkalaskelma dialogi (raportit)

#include "AboutForm.h"        //"About" lomake
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::OnHint(TObject *Sender)
{
     //Kopioidaan tilariville Application->Hint-
     //ominaisuuteen tallettuva vihjeteksti...
    StatusBar1->SimpleText = Application->Hint;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormCreate(TObject *Sender)
{
     //Uudelleenóhjaus: ohjataan pääohjelman tapahtumakäsittelijä omaan tapahtumakäsittelijään
     Application->OnHint = OnHint;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::FormClose(TObject *Sender, TCloseAction &Action)
{
    //Tuhotaan yrityksen tietoja käsittelevä olio
    delete corporationOperations;
    //Tuhotaan palkanlaskussa käytetty olio
    delete salaryOperations;
    //Tuhotaan lomakkeita vahtiva tilaolio
    delete observer;
    //Tuhotaan käyttäjätietoja vahtiva (LoginOperations) olio
    delete logins;
    //Action = vapauta ohjelman käyttöön varattu muisti
    Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::Tulostimenasetukset1Click(TObject *Sender)
{
    PrinterSetupDialog1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::FormShow(TObject *Sender)
{
    //Näytetään ensin sisäänkirjautumis-dialogi..
    FormLogin->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::Poistuohjelmasta1Click(TObject *Sender)
{
    //Suljetaan ohjelma
    if(Application->MessageBox("Haluatko poistua laskutusohjelmasta?","Postuminen laskutusohjelmasta?",MB_YESNO)==IDYES)
    {
    delete corporationOperations;
    //Tuhotaan palkanlaskussa käytetty olio
    delete salaryOperations;
    //Tuhotaan lomakkeita vahtiva tilaolio
    delete observer;
    //Tuhotaan käyttäjätietoja vahtiva (LoginOperations) olio
    delete logins;
    //Suljetaan pääohjelma
    FormMain->Close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::Kirjautuminen1Click(TObject *Sender)
{
    //Piilotetaan päälomake kirjautumisen ajaksi
    FormMain->Hide();
    //Uusien käyttöoikeuksien antaminen....
    FormLogin->ShowModal();
    //Näytetään päälomake uusilla käyttöoikeuksilla
    FormMain->Show();
}
//---------------------------------------------------------------------------


void __fastcall TFormMain::About1Click(TObject *Sender)
{
    FormAbout->ShowModal();    
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::Tile1Click(TObject *Sender)
{
    TileMode = tbHorizontal;
    //TileMode = tbVertical
    Tile();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::Cascade1Click(TObject *Sender)
{
    Cascade();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::Arrangeall1Click(TObject *Sender)
{
    ArrangeIcons();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Yrityksentiedot1Click(TObject *Sender)
{
    //Avataan yrityksentietojennanto ali-ikkuna
    //Ali-ikkunan Observer-olion ID on "0"
    int formID = 0;
    if(observer->GetState(formID)==0){
        observer->SetState(formID);
        TFormCorporation *FormCorporation = dynamic_cast<TFormCorporation *>(ActiveMDIChild);
        FormCorporation  = new TFormCorporation(this);
        FormCorporation->Show();
    }
    else{
        ShowMessage("Lomake on jo auki");
    }

}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Salasanat1Click(TObject *Sender)
{
    //Avataan käyttöoikeuksienanto ali-ikkuna
    //Ali-ikkunan Observer-olion ID on "1"
    int formID = 1;
    if(observer->GetState(formID)==0){
        observer->SetState(formID);
        TFormUserrights *FormUserrights = dynamic_cast<TFormUserrights *>(ActiveMDIChild);
        FormUserrights  = new TFormUserrights(this);
        FormUserrights->Show();
    }
    else{
        ShowMessage("Lomake on jo auki");
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Verotustietojenmritys1Click(TObject *Sender)
{
    //Avataan yleisten verotustietojenanto ali-ikkuna
    //Ali-ikkunan Observer-olion ID on "2"
    int formID = 2;
    if(observer->GetState(formID)==0){
        observer->SetState(formID);
        TFormTaxes *FormTaxes = dynamic_cast<TFormTaxes *>(ActiveMDIChild);
        FormTaxes  = new TFormTaxes(this);
        FormTaxes->Show();
    }
    else{
        ShowMessage("Lomake on jo auki!");
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Henkiltiedot1Click(TObject *Sender)
{
    //Avataan henkilötietojennanto ali-ikkuna
    //Ali-ikkunan Observer-olion ID on "3"
    int formID = 3;
    if(observer->GetState(formID)==0){
        observer->SetState(formID);
        TFormPersondetail *FormPersondetail = dynamic_cast<TFormPersondetail *>(ActiveMDIChild);
        FormPersondetail  = new TFormPersondetail(this);
        FormPersondetail->Show();
    }
    else{
        ShowMessage("Lomake on jo auki!");
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Verotustiedot2Click(TObject *Sender)
{
    //Avataan henkilötietojennanto ali-ikkuna
    //Ali-ikkunan Observer-olion ID on "4"
    int formID = 4;
    if(observer->GetState(formID)==0){
        observer->SetState(formID);
        TFormPersontax *FormPersontax = dynamic_cast<TFormPersontax *>(ActiveMDIChild);
        FormPersontax  = new TFormPersontax(this);
        FormPersontax->Show();
    }
    else{
        ShowMessage("Lomake on jo auki!");
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Palkanlaskeminen1Click(TObject *Sender)
{
    //Avataan palkanlaskenta ali-ikkuna
    //Ali-ikkunan Observer-olion ID on "5"
    int formID = 5;
    if(observer->GetState(formID)==0){
        observer->SetState(formID);
        TFormCountSalary *FormCountSalary = dynamic_cast<TFormCountSalary *>(ActiveMDIChild);
        FormCountSalary  = new TFormCountSalary(this);
        FormCountSalary->Show();
    }
    else{
        ShowMessage("Lomake on jo auki!");
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::Tulosta1Click(TObject *Sender)
{
    //Yleinen stringi vain "childin Namen" tarkistusta varten
    String Aktiivinen;

    //Jos ei aktiivista ikkunaa oleenkaan niin...
    if(!ActiveMDIChild)
    {
    Application->MessageBox("Valitse ensin tulostettava ikkuna","Tulostusvirhe",MB_OK);
    return;
    }
    else
    {
      Aktiivinen = ActiveMDIChild->Name;
        //Sitten ei muuta kuin lisäyksenä tulostuksen
        //ohjaukset. (Ensin ikkunan tarkistus)
        if(Aktiivinen=="FormCorporation") //(1)
        {
        Application->MessageBox("Yritystieto lomakkeen tulostus","Tulostuksen ilmoitus",MB_OK);
        FormMain->PrintCorporation();
        }
        if(Aktiivinen=="FormUserrights") //(2)
        {
         Application->MessageBox("Käyttäjätieto lomakkeen tulostus","Tulostuksen ilmoitus",MB_OK);
         FormMain->PrintUserrights();
        }
        if(Aktiivinen=="FormTaxes") //(3)
        {
        Application->MessageBox("Yleisen verotustieto lomakkeen tulostus","Tulostuksen ilmoitus",MB_OK);
        FormMain->PrintTaxes();
        }
        if(Aktiivinen=="FormPersondetail") //(4)
        {
        Application->MessageBox("Henkilötieto lomakkeen tulostus","Tulostuksen ilmoitus",MB_OK);
        FormMain->PrintPersondetail();
        }
        if(Aktiivinen=="FormPersontac")    //(5)
        {
        Application->MessageBox("Verotustieto lomakkeen tulostus","Tulostuksen ilmoitus",MB_OK);
        FormMain->PrintPersontaxForm();
        }
        if(Aktiivinen=="FormCountSalary")  //(6)
        {
        Application->MessageBox("Palkanlasku lomakkeen tulostus","Tulostuksen ilmoitus",MB_OK);
        FormMain->PrintCountSalaryForm();
        }
    }
}
//---------------------------------------------------------------------------
void TFormMain::PrintCorporation()  //(1)
{
     TFormCorporation *FormCorporation = dynamic_cast<TFormCorporation *>(ActiveMDIChild);

    if(PrintDialog1->Execute())
    {
        FormPersontax->Print();
    }
    else
    {
        ShowMessage("Nyt mattaa jokin?");
    }
}
//---------------------------------------------------------------------------
void TFormMain::PrintUserrights()  //(2)
{
    TFormUserrights *FormUserrights = dynamic_cast<TFormUserrights *>(ActiveMDIChild);

    Application->MessageBox("Meni lapi","OK?",MB_OK);

    TPrinter *Prntr = Printer();    // Otetaan oletuskirjoittimen ilmentymä.

     Prntr->Canvas->Font->Size = 12;     // Fontin koko 12 pistettä.
     int rkork = Prntr->Canvas->TextHeight(" ") *1.2;
     int klev= Prntr->Canvas->TextWidth(" ");
     int rivilask=1;

     Prntr->BeginDoc();             // Ilmoitetaan tulostuksen alkamisesta.

     //Asetetaan otsikko ja lähetetään tiedot
     //Printer()->Title = "LASKUTUS";
     /*Prntr->Canvas->TextOut(klev, rivilask * rkork, FormSales->DBCustomer->Text);
     Prntr->Canvas->TextOut(klev, rivilask * rkork, FormSales->DBName->Text);
     Prntr->Canvas->TextOut(klev, rivilask * rkork, FormSales->DBLast->Text);
     Prntr->Canvas->TextOut(klev, rivilask * rkork, FormSales->DBGame->Text);
     Prntr->Canvas->TextOut(klev, rivilask * rkork, FormSales->DBPrice->Text);
     Prntr->Canvas->TextOut(klev, rivilask * rkork, FormSales->DBOrder->Text);
     Prntr->Canvas->TextOut(klev, rivilask * rkork, FormSales->DBDate->Date);
     Prntr->Canvas->TextOut(klev, rivilask * rkork, FormSales->DBAmount->Text);
     Prntr->Canvas->TextOut(108,100, FormSales->DBWholePrice->Text);*/

     Prntr->EndDoc();          //Tulostuksen lopetus merkin anto
}
//---------------------------------------------------------------------------
void TFormMain::PrintTaxes() //(3)
{
    TFormTaxes *FormTaxes = dynamic_cast<TFormTaxes *>(ActiveMDIChild);

    if(PrintDialog1->Execute())
    {
        FormPersontax->Print();
    }
    else
    {
        ShowMessage("Nyt mattaa jokin?");
    }
}
//---------------------------------------------------------------------------
void TFormMain::PrintPersondetail() //(4)
{
     TFormPersondetail *FormPersondetail = dynamic_cast<TFormPersondetail *>(ActiveMDIChild);

     Application->MessageBox("Meni lapi","OK?",MB_OK);
     TPrinter *Prntr = Printer();    // Otetaan oletuskirjoittimen ilmentymä.

     Prntr->Canvas->Font->Size = 12;     // Fontin koko 12 pistettä.
     int rkork = Prntr->Canvas->TextHeight(" ") *1.2;
     int klev= Prntr->Canvas->TextWidth(" ");
     int rivilask=1;

     //Asetetaan otsikko ja lähetetään tiedot
     /*Printer()->Title = "ASIAKAS TIETOJA";
     Prntr->Canvas->TextOut(klev, rivilask * rkork,FormCustomers->NumberField->Text);
     Prntr->Canvas->TextOut(klev, rivilask * rkork,FormCustomers->NameField->Text);
     Prntr->Canvas->TextOut(klev, rivilask * rkork,FormCustomers->LastField->Text);
     Prntr->Canvas->TextOut(klev, rivilask * rkork,FormCustomers->StateField->Text);
     Prntr->Canvas->TextOut(klev, rivilask * rkork,FormCustomers->AddrField->Text);
     Prntr->Canvas->TextOut(klev, rivilask * rkork,FormCustomers->PlaceField->Text);
     Prntr->Canvas->TextOut(klev, rivilask * rkork,FormCustomers->LandField->Text);
     Prntr->Canvas->TextOut(klev, rivilask * rkork,FormCustomers->CorpField->Text);
     Prntr->Canvas->TextOut(klev, rivilask * rkork,FormCustomers->PhoneField->Text);
     Prntr->Canvas->TextOut(klev, rivilask * rkork,FormCustomers->FaxField->Text);
     Prntr->Canvas->TextOut(klev, rivilask * rkork,FormCustomers->EmailField->Text);
     */
     Prntr->EndDoc();          //Tulostuksen lopetus merkin anto
}
//---------------------------------------------------------------------------
void TFormMain::PrintPersontaxForm()  //(5)
{
    TFormPersontax *FormPersontax = dynamic_cast<TFormPersontax *>(ActiveMDIChild);

    if(PrintDialog1->Execute())
    {
        FormPersontax->Print();
    }
    else
    {
        ShowMessage("Nyt mattaa jokin?");
    }
}
//---------------------------------------------------------------------------
void TFormMain::PrintCountSalaryForm()  //(6)
{
     TFormCountSalary *FormCountSalary = dynamic_cast<TFormCountSalary *>(ActiveMDIChild);

    if(PrintDialog1->Execute())
    {
        FormPersontax->Print();
    }
    else
    {
        ShowMessage("Nyt mattaa jokin?");
    }
}
//---------------------------------------------------------------------------


void __fastcall TFormMain::Palkkalaskelma1Click(TObject *Sender)
{
   //TPaySlipDialog *PaySlipDialog = new TPaySlipDialog();
   PaySlipDialog->Show();
}
//---------------------------------------------------------------------------

