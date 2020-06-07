//---------------------------------------------------------------------------
#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TMenuItem *File1;
    TMenuItem *Tulosta1;
    TMenuItem *Tulostimenasetukset1;
    TMenuItem *N1;
    TMenuItem *Poistuohjelmasta1;
    TMenuItem *Ikkunat1;
    TMenuItem *Help1;
    TMenuItem *N2;
    TMenuItem *About1;
    TMenuItem *Ikkunat2;
    TMenuItem *Tile1;
    TMenuItem *Cascade1;
    TMenuItem *Arrangeall1;
    TMenuItem *Kirjautuminen1;
    TPrintDialog *PrintDialog1;
    TPrinterSetupDialog *PrinterSetupDialog1;
    TStatusBar *StatusBar1;
    TMenuItem *Raportit1;
    TMenuItem *N7;
    TSaveDialog *SaveDialog;
    TOpenDialog *OpenDialog;
    TMenuItem *Lomakkeet1;
    TMenuItem *Henkiltiedot1;
    TMenuItem *Verotustiedot2;
    TMenuItem *N3;
    TMenuItem *Verotustietojenmritys1;
    TMenuItem *Salasanat1;
    TMenuItem *N4;
    TMenuItem *N6;
    TMenuItem *Yrityksentiedot1;
    TMenuItem *N8;
    TMenuItem *Palkanlaskeminen1;
    TMenuItem *Palkkalaskelma1;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Tulostimenasetukset1Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall Poistuohjelmasta1Click(TObject *Sender);
    void __fastcall Kirjautuminen1Click(TObject *Sender);
    
    void __fastcall About1Click(TObject *Sender);
    void __fastcall Henkiltiedot1Click(TObject *Sender);
    void __fastcall Tile1Click(TObject *Sender);
    void __fastcall Cascade1Click(TObject *Sender);
    void __fastcall Arrangeall1Click(TObject *Sender);
    void __fastcall Tulosta1Click(TObject *Sender);
    void __fastcall Salasanat1Click(TObject *Sender);
    void __fastcall Yrityksentiedot1Click(TObject *Sender);
    void __fastcall Verotustietojenmritys1Click(TObject *Sender);
    void __fastcall Verotustiedot2Click(TObject *Sender);
    void __fastcall Palkanlaskeminen1Click(TObject *Sender);
    
    
    void __fastcall Palkkalaskelma1Click(TObject *Sender);
private:	// User declarations
     //Satusbaarin vihejeiden käsittelijä
     void __fastcall OnHint(TObject *Sender);

     //Tulostuksen poikkeuskäsittelijät alkavat tästä...
     void TFormMain::PrintCorporation();      //(1)Yritys lomakkeen tulostus
     void TFormMain::PrintUserrights();       //(2)Käyttäjätieto lomakkeen tulostus
     void TFormMain::PrintTaxes();            //(3)Yl. verotustieto lomakkeen tulostus
     void TFormMain::PrintPersondetail();     //(4)Henkilötieto lomakkeen tulostus
     void TFormMain::PrintPersontaxForm();    //(5)Henkilön verotustieto lomakkeen tulostus
     void TFormMain::PrintCountSalaryForm();  //(6)Palkanlasku lomakkeen tulostus
public:		// User declarations
    __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
