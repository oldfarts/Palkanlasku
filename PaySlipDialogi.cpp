//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <fstream.h>

#include "PaySlipDialogi.h" //dialogi
#include "PaySlipReport.h"  //itse raportti

//Raportin tietojen laatimista varten..
#include "PersondetailOperations.h"
#include "TaxOperations.h"
#include "PersontaxOperations.h"
#include "CountSalaryOperations.h"
#include "CountPrevSalaryOperatios.h"
#include "compositeReport.h"
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TPaySlipDialog *PaySlipDialog;

//---------------------------------------------------------------------
__fastcall TPaySlipDialog::TPaySlipDialog(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TPaySlipDialog::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    //Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TPaySlipDialog::CancelBtnClick(TObject *Sender)
{
    PaySlipDialog->Close();
}
//---------------------------------------------------------------------------
void __fastcall TPaySlipDialog::ComboBox1KeyPress(TObject *Sender,
      char &Key)
{
        if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //lähetetään Windosille viesti siirtyä seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------

void __fastcall TPaySlipDialog::ComboBox1Change(TObject *Sender)
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

void __fastcall TPaySlipDialog::FormShow(TObject *Sender)
{
    AnsiString pNumber;
    AnsiString lName;
    AnsiString fName;
    AnsiString comboText;

    //Tyhjennetään comboboxi
    ComboBox1->Items->Clear();
    
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
void __fastcall TPaySlipDialog::OKBtnClick(TObject *Sender)
{
    // (0.) ------------------------------------------>
    //Alustetaan laskennassa käytettävät muuttujat
    double perusprosenttI;//Perusprosentti (13,5) (%)
    double lisaprosenttI;//Lisaprosentti (33,5) (%)
    double kktulorajA;   //Tuloraja/Kuukaudessa (833,33euroa)

    AnsiString kausiAlku; //Palkkakauden alku PVM
    AnsiString kausiLoppu; //Palkkakauden loppu PVM

    double kkpalkkA;     //KK-palkka ilman lisiä  (euroa)
    double lisA;         //Lisätunnit (h)
    double ylityoA;      //50% ylityotunnit (h)
    double ylityoB;      //100%ylityötunnit (h)
    double lisahintA;    //Lisätuntien hinta (euroa)
    double lisayhT;      //(Ylityot)/Lista yhteensä
    double kkpalkkayhT;  //KK-palkka lisien kanssa  (euroa)

    double teL;          //TEL-maksu (%)
    double telsummA;     //TEL-maksu (euroa)
    double vuodenteL;    //TEL-maksu vuoden alusta lähtien (euroa)(toinen file)
    double vaK;          //työt.vak. maksu (%)
    double vaksummA;     //työt.vak. maksu (euroa)
    double vuodenvak;    //työ.vak.maksu vuoden alusta lähtien (euroa)(toinen file)

    double ennakonpiD;   //Ennakonpidätys (euroa)
    double maksetaan;    //Vähennysten jälkeen käteen jäävä summa (euroa)

    double vahennykset;  //Tel+tyot.vak.maksu (euroa)

    // <------------ Alustusten osuus loppuu ---


    // (1.) ------------------------------------------>
    //(Person.h ja PersondetailOperations.h)
    AnsiString PersonNumber;    //Henkilön numero (tunnistus nro.)
    AnsiString LastName;        //Sukunimi
    AnsiString FirstName;       //Etunimi (et)
    AnsiString SocialCode;      //Henkilö tunnus
    AnsiString AddTime;         //aloitus pvm
    AnsiString Add2Time;        //Yksikön aloitus pvm
    AnsiString EndTime;         //lopetus pvm
    AnsiString Address;         //Lähiosoite
    AnsiString PostalCode;      //Postiosoite
    AnsiString City;            //Kaupunki
    AnsiString Land;            //Maa
    AnsiString HomeNumber;      //Kotinumero
    AnsiString MobileNumber;    //Kännykkä
    AnsiString HomeEmail;       //Email-osoite

    //1. Haetaan hekilötiedot
    personOperations->DeleteAllEntries();
    personOperations->SetCounter();
    personOperations->LoadFromFile("c:\\Laskutusohjelma\\henktiedot.txt");
    int sizeOne = personOperations->GetSize();
    if(sizeOne!=0){
            personOperations->GetForReport(Edit1->Text, Edit2->Text, Edit3->Text,
            PersonNumber,LastName,FirstName,
            AddTime,Add2Time,EndTime,
            SocialCode,Address,PostalCode,City,Land,
            HomeNumber,MobileNumber,HomeEmail);
    }
    else{
        Application->MessageBox("Henkilötietojen haku epäonnistui", "Henkilötietojen luku", MB_OK)==IDOK;
    }

    //Tietojen asetus raporttiin
    QuickReport1->QRLabel6->Caption = SocialCode;   //Sos.tunnus
    QuickReport1->QRLabel7->Caption = PersonNumber;   //Henk. nro (!!!)
    QuickReport1->QRLabel8->Caption = "";           // (!!!)
    QuickReport1->QRLabel48->Caption = "";           // (!!!)
    QuickReport1->QRLabel19->Caption = LastName;    //Sukunimi
    QuickReport1->QRLabel20->Caption = FirstName;   //Etunimi
    QuickReport1->QRLabel21->Caption = Address;     //Lähiosoite
    QuickReport1->QRLabel22->Caption = PostalCode;  //Postiosoite
    QuickReport1->QRLabel23->Caption = City;        //Kaupunki
    QuickReport1->QRLabel24->Caption = AddTime;     //Alotus PVM
    QuickReport1->QRLabel25->Caption = Add2Time;    //Yks. Alotus PVM
    QuickReport1->QRLabel26->Caption = EndTime;     //Lopetus PVM
    // <------------ Henkilötietojen osuus loppuu ---


    // (2.) ---------------------------------------->
    // Taxes.h ja PersontaxOperations.h
    AnsiString PersonNumber2;
    AnsiString LastName2;
    AnsiString FirstName2;
    AnsiString TiliNumero;            //Henkilön tilinumero
    AnsiString PerusProsentti;        //Perusveroprosentti  (13,5%)
    AnsiString LisaProsentti;         //Lisäveroprosentti   (33,5%)
    AnsiString VVTuloraja;            //Perustuloraja / vv  (10000e)
    AnsiString KKTuloraja;            //Perustuloraha / kk  (833,33e)
    AnsiString KahdenVKTuloraja;      //Perustuloraja  / 2.vk (384,62e)
    AnsiString VKTuloraja;            //Perustuloraja / 1.vk (192,31e) (kts.ed.)
    AnsiString PVTuloraja;            //Perustuloraja / pv. (27,47e)

    // Haetaan henkilön verotustiedot
    persontaxOperations->DeleteAllEntries();
    persontaxOperations->SetCounter();
    persontaxOperations->LoadFromFile("c:\\Laskutusohjelma\\verotustiedot.txt");
    int sizeTwo = persontaxOperations->GetSize();
    if(sizeTwo!=0){
            persontaxOperations->GetForReport(Edit1->Text, Edit2->Text, Edit3->Text,
            PersonNumber2, LastName2, FirstName2, TiliNumero,
            VVTuloraja,PerusProsentti,LisaProsentti, KKTuloraja, KahdenVKTuloraja,
            VKTuloraja,PVTuloraja);
    }
    else{
        Application->MessageBox("Verotietojen haku epäonnistui", "Verotustietojen luku", MB_OK)==IDOK;
    }

    //ShowMessage(PerusProsentti + LisaProsentti + VVTuloraja);
    //Tietojen asetus raporttiin
    QuickReport1->QRLabel9->Caption  = PerusProsentti;
    QuickReport1->QRLabel10->Caption = LisaProsentti;
    QuickReport1->QRLabel11->Caption = VVTuloraja;
    QuickReport1->QRLabel12->Caption = KKTuloraja;
    QuickReport1->QRLabel77->Caption = TiliNumero;

    //Tietojen talteenotto laskentaa varten (kts. palkan laskenta (5.) )
    perusprosenttI = (PerusProsentti.ToDouble())/100; //PerusProsentti (%)
    lisaprosenttI  = (LisaProsentti.ToDouble())/100;  //(Ylityo)/lisat (h)
    kktulorajA     = KKTuloraja.ToDouble();           //KK-Tuloraja
    // <------------ Verotustietojen osuus loppuu ---


    // (3.) ---------------------------------------->
    //TaxOperations.h ja Taxes.h
    AnsiString Tel;
    AnsiString Vak;

    // Haetaan palkkalaskelma
    taxOperations->LoadFromFile("c:\\Laskutusohjelma\\verotus.txt");

    int sizeThree = taxOperations->CheckSize();
    if(sizeThree ==1){
            taxOperations->GetEntry(Tel, Vak);
    }
    else{
        Application->MessageBox("Verotustietojen haku epäonnistui", "Verotietojen luku", MB_OK)==IDOK;
    }
    //Tietojen asetus raporttiin
    QuickReport1->QRLabel174->Caption = Tel;         //Tel-maksu (4,4%)
    QuickReport1->QRLabel175->Caption = Vak;         //työt.vak.maksu (0,4%)

    //Tietojen muutos laskentaa varten
    teL = Tel.ToDouble();                            //TEL-maksu (%)
    vaK = Vak.ToDouble();                            //työ.vak. maksu (%)
    // <------------ Yleisten verotustietojen osuus loppuu ---


    // (4.) ---------------------------------------->
    //CountSalaryOperations.h  (CountSalaryForm) ja Taxes.h<-(salary)
    AnsiString PersonNumber3;
    AnsiString LastName3;
    AnsiString FirstName3;
    AnsiString StartDate;                   //Palkanmaksu kauden alku PVM
    AnsiString EndDate;                     //Palkanmaksu kauden loppu PVM
    AnsiString PayDate;                     //Liksanmaksupäivä
    AnsiString Days;                        //Työ päivämäärät
    AnsiString Hours;                       //norm. työtunnit
    AnsiString Salary;                      //Norm. KK-liksa !!!!
    AnsiString Ylityo, YlityoHinta,Yhteensa;//Ylityöt
    AnsiString Lomaraha,Lomakorvaus;        //Lomakorvaukset

     // Haetaan palkkalaskelma
    salaryOperations->DeleteAllEntries();
    salaryOperations->SetCounter();
    salaryOperations->LoadFromFile("c:\\Laskutusohjelma\\palkkalaskelma.txt");
    int sizeFour = salaryOperations->GetSize();
    if(sizeFour!=0){
            salaryOperations->GetForReport(Edit1->Text, Edit2->Text, Edit3->Text,
            PersonNumber3, LastName3, FirstName3,
            StartDate, EndDate, PayDate, Days, Hours, Salary,
            Ylityo, YlityoHinta, Yhteensa,
            Lomaraha, Lomakorvaus);
    }
    else{
        Application->MessageBox("Palkkalaskelmatietojen haku epäonnistui", "Palkkalaskelmatietojen luku", MB_OK)==IDOK;
    }

    //Tietojen asetus raporttiin
    QuickReport1->QRLabel16->Caption = PayDate;
    QuickReport1->QRLabel17->Caption = StartDate;
    kausiAlku = StartDate;                        //Tallennus myöh. käsittelyä varten (6.)
    QuickReport1->QRLabel18->Caption = EndDate;
    kausiLoppu = EndDate;                         //Tallennus myöh. käsittelyä varten (6.)

    QuickReport1->QRLabel36->Caption = Days;
    QuickReport1->QRLabel37->Caption = Hours;

    QuickReport1->QRLabel30->Caption = Salary;       //Normaali liksa-kaikkine lisineen yhteensä
    QuickReport1->QRLabel173->Caption = Salary;       //Normaalin liksan erottelu

    QuickReport1->QRLabel172->Caption = Ylityo;      //Norm. lisät (ei vars. ylityö)
    QuickReport1->QRLabel170->Caption = YlityoHinta; //Kk-liksa/22(työPVM) = tunti-liksa
    //QuickReport1->QRLabel77->Caption = Yhteensa;
    //QuickReport1->QRLabel12->Caption = Lomaraha;
    //QuickReport1->QRLabel77->Caption = Lomakorvaus;

    //Tietojen muutos laskentaa varten
    kkpalkkA = Salary.ToDouble();                //KK-palkka (euroa)
    lisA = Ylityo.ToDouble();                    //(Ylityo)/lisat (h)
    lisahintA = YlityoHinta.ToDouble();          // (Ylityo)/lisat (euroa) eli kk-palkka/22
    // <------------ Palkkalaskelmatietojen osuus loppuu ---


    // (5.) ---------------------------------------->
    //Palkanlaskenta osuus ja muutos alkaa tästä eteenpäin
    kkpalkkayhT = kkpalkkA + (lisA * lisahintA);     //KK-liksa kaikkine lisineen
    telsummA    = (kkpalkkayhT * teL)/100;           //TEL-maksu yht.
    vaksummA    = (kkpalkkayhT * vaK)/100;           //Työt.vak.maksu yht.
    vahennykset = telsummA + vaksummA;               //Vähennykset yht.
    lisayhT     = lisA * lisahintA;                  //(Ylityot)/Lisat yhteensä

    double helpperusproS = kktulorajA * perusprosenttI;              //Perus-%:lla menevä osuus
    double helplisaproS  = (kkpalkkayhT - kktulorajA)*lisaprosenttI; //Lisaprosentilla menevä osuus
    ennakonpiD  = helpperusproS + helplisaproS;      //Ennakonpidätys
    maksetaan   = kkpalkkayhT - ennakonpiD;          //Käteen käävä osuus
//    double markkA = 5.95;                            //1 euro = 5,94573 MK..
//    double maksetaanMK = maksetaan * markkA;         //..Markkaa

    QuickReport1->QRLabel29->Caption  = maksetaan; //maksetaanMK;
    QuickReport1->QRLabel30->Caption  = kkpalkkayhT;
    QuickReport1->QRLabel31->Caption  = telsummA;
    QuickReport1->QRLabel32->Caption  = vaksummA;
    QuickReport1->QRLabel33->Caption  = ennakonpiD;
    QuickReport1->QRLabel38->Caption  = maksetaan;
    QuickReport1->QRLabel78->Caption  = maksetaan;
    QuickReport1->QRLabel42->Caption  = lisayhT;
    QuickReport1->QRLabel67->Caption  = vahennykset;
    // <------------ Palkkalaskelmatietojen muutos ja laskenta loppuu ---

    // (6.) ---------------------------------------->
    //Edellisten kuukausien tietojen luku ja asetus
     // Haetaan palkkalaskelma
    AnsiString PersonNumber6;   //Henkilön numero (tunnistus nro.)
    AnsiString LastName6;       //Sukunimi
    AnsiString FirstName6;      //Etunimi (et)
    AnsiString PayslipStart6;    //Palkkakausi (alku)
    AnsiString PayslipEnd6;      //Palkkakausi (loppu)

    AnsiString PeriodtimeLimit6;  //Tuloraja/ka
    AnsiString PaycumulTax6;      //Ansio verok.al
    AnsiString TaxDays6;          //veropvt. verok. al
    AnsiString PayrolltaxCum6;    //Enn.pid. Verko. al.

    AnsiString SalaryMonth6;     //Palkka/kk yhteensä
    AnsiString TaxableIncome6;   //Veronal. ansio
    AnsiString Lisat6;           // Lisat
    AnsiString Vahennykset6;     //Vähennykset
    salaryprevOperations->DeleteAllEntries();
    salaryprevOperations->SetCounter();
    salaryprevOperations->LoadFromFile("c:\\Laskutusohjelma\\palkkaedkk.txt");
    bool ThereIsEntry = salaryprevOperations->CheckSalary(Edit1->Text,Edit2->Text,Edit3->Text);
    if(ThereIsEntry == false)
    {
    //ShowMessage("Lisataan uuden henkilon tiedot");
     //Jos ei ole vielä yhtään henkilön tieota olemassa
        salaryprevOperations->AddEntry(Edit1->Text,Edit2->Text,Edit3->Text,
                                       kausiAlku, kausiLoppu,
                                       KKTuloraja, kkpalkkayhT,Days,ennakonpiD,
                                       kkpalkkayhT, kkpalkkayhT,
                                       lisayhT,vahennykset);
        salaryprevOperations->SaveToFile("c:\\Laskutusohjelma\\palkkaedkk.txt");
     }
     else
     {
       // ShowMessage("Paivitetaan vanhan henkilon tiedot");
       // salaryprevOperations->LoadFromFile("c:\\Laskutusohjelma\\palkkaedkk.txt");
        salaryprevOperations->GetForReport(Edit1->Text,Edit2->Text,Edit3->Text,
                                           PersonNumber6,LastName6,FirstName6,
                                           PayslipStart6,PayslipEnd6,
                                           PeriodtimeLimit6,PaycumulTax6,TaxDays6,
                                           PayrolltaxCum6,SalaryMonth6,TaxableIncome6,
                                           Lisat6,Vahennykset6);

       PayslipStart6       = kausiAlku;                    //Palkkakausi alku PVM
       PayslipEnd6         = kausiLoppu;                   //Palkkakausi loppu PVM
       PeriodtimeLimit6    = KKTuloraja;                   //KK-tuloraja

       double paycumultax6 = PaycumulTax6.ToDouble();      //Ansio.verok.al
       paycumultax6        = (paycumultax6 + kkpalkkayhT);
       PaycumulTax6        = paycumultax6;
       double taxDays6     = TaxDays6.ToDouble();          //Veropäivät  yht.
       double days6        = Days.ToDouble();
       taxDays6            = (taxDays6 + days6);
       TaxDays6            = taxDays6;

       double payroltaxCum6= PayrolltaxCum6.ToDouble();    //Ennakonpidätys yht.
       payroltaxCum6       = (ennakonpiD + payroltaxCum6);
       PayrolltaxCum6      = payroltaxCum6;
       double salaryMonth6 = SalaryMonth6.ToDouble();      //Koko liksa yhteensä
       salaryMonth6        = (kkpalkkayhT + salaryMonth6);
       SalaryMonth6        = salaryMonth6;
       TaxableIncome6      = SalaryMonth6;                 //Veronal. ansio
       double lisat6       = Lisat6.ToDouble();
       lisat6              = (lisat6 + lisayhT);           //Lisat yht.
       Lisat6              = lisat6;
       double ahennykset6  = Vahennykset6.ToDouble();
       ahennykset6         = (ahennykset6 + vahennykset); //vahennykset yht.
       Vahennykset6        = ahennykset6;
         
         //tallennetaan muutokset
        salaryprevOperations->UpdateEntry(Edit1->Text,Edit2->Text,Edit3->Text,
                                       kausiAlku, kausiLoppu,
                                       KKTuloraja, PaycumulTax6,TaxDays6,PayrolltaxCum6,
                                       SalaryMonth6, TaxableIncome6,
                                       Lisat6,Vahennykset6);
        salaryprevOperations->SaveToFile("c:\\Laskutusohjelma\\palkkaedkk.txt");

        //ja liitetään raporttiin
       QuickReport1->QRLabel13->Caption  = PaycumulTax6;     //Ansio verok.al
       QuickReport1->QRLabel14->Caption  = TaxDays6;         //Veropvt verok.al
       QuickReport1->QRLabel15->Caption  = PayrolltaxCum6;   //enn.pid verok.al  (?!?)
       QuickReport1->QRLabel39->Caption  = kkpalkkayhT;      //Rahapalkka/kk
       QuickReport1->QRLabel46->Caption  = SalaryMonth6;     //Rahaplkka/kk yht.
       QuickReport1->QRLabel41->Caption  = kkpalkkayhT;      //Veronal. ansio/kk = rahapalkka/kk
       QuickReport1->QRLabel48->Caption  = TaxableIncome6;   //veronal. ansio/kk yht.
       QuickReport1->QRLabel49->Caption  = Lisat6;           //(Ylityo)/lisat yht.
       QuickReport1->QRLabel73->Caption  = Vahennykset6;     //vahennykset/kk yht.

    }

    
    // <------------ Edellisten kuukausien laskenta loppuu ---

//--------------------------------------------------------
//Ensiksi suljetaan dialogi, ettei se jää näkyviin
PaySlipDialog->Close();

//Sitten kutsutaan raportti-viewia
//QuickReport1->QRLabel1->Caption ="taitaapi toimia?!?!";
//Form1->QRCompositeReport1AddReports(QuickReport1);
    //Tietojen asetus raporttiin
    Form1->QRLabel6->Caption = SocialCode;   //Sos.tunnus
    Form1->QRLabel7->Caption = PersonNumber;   //Henk. nro (!!!)
    Form1->QRLabel8->Caption = "";           // (!!!)
    Form1->QRLabel48->Caption = "";           // (!!!)
    Form1->QRLabel19->Caption = LastName;    //Sukunimi
    Form1->QRLabel20->Caption = FirstName;   //Etunimi
    Form1->QRLabel21->Caption = Address;     //Lähiosoite
    Form1->QRLabel22->Caption = PostalCode;  //Postiosoite
    Form1->QRLabel23->Caption = City;        //Kaupunki
    Form1->QRLabel24->Caption = AddTime;     //Alotus PVM
    Form1->QRLabel25->Caption = Add2Time;    //Yks. Alotus PVM
    Form1->QRLabel26->Caption = EndTime;     //Lopetus PVM
    // <------------ Henkilötietojen osuus loppuu ---
        //Tietojen asetus raporttiin
    Form1->QRLabel9->Caption  = PerusProsentti;
    Form1->QRLabel10->Caption = LisaProsentti;
    Form1->QRLabel11->Caption = VVTuloraja;
    Form1->QRLabel12->Caption = KKTuloraja;
    Form1->QRLabel77->Caption = TiliNumero;

    Form1->QRLabel29->Caption  = maksetaan; //maksetaanMK;
    Form1->QRLabel30->Caption  = kkpalkkayhT;
    Form1->QRLabel31->Caption  = telsummA;
    Form1->QRLabel32->Caption  = vaksummA;
    Form1->QRLabel33->Caption  = ennakonpiD;
    Form1->QRLabel38->Caption  = maksetaan;
    Form1->QRLabel78->Caption  = maksetaan;
    Form1->QRLabel42->Caption  = lisayhT;
    Form1->QRLabel67->Caption  = vahennykset;
    // <------------ Palkkalaskelmatietojen muutos ja laskenta loppuu ---

    //ja liitetään raporttiin
    Form1->QRLabel13->Caption  = PaycumulTax6;     //Ansio verok.al
    Form1->QRLabel14->Caption  = TaxDays6;         //Veropvt verok.al
    Form1->QRLabel15->Caption  = PayrolltaxCum6;   //enn.pid verok.al  (?!?)
    Form1->QRLabel39->Caption  = kkpalkkayhT;      //Rahapalkka/kk
    Form1->QRLabel46->Caption  = SalaryMonth6;     //Rahaplkka/kk yht.
    Form1->QRLabel41->Caption  = kkpalkkayhT;      //Veronal. ansio/kk = rahapalkka/kk
    Form1->QRLabel48->Caption  = TaxableIncome6;   //veronal. ansio/kk yht.
    Form1->QRLabel49->Caption  = Lisat6;           //(Ylityo)/lisat yht.
    Form1->QRLabel73->Caption  = Vahennykset6;     //vahennykset/kk yht.

    //And Shot the values in pay slip
    Form1->QuickRep1->Preview();
//QuickReport1->Preview();
}
//---------------------------------------------------------------------------

