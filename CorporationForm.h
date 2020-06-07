//---------------------------------------------------------------------------
#ifndef CorporationFormH
#define CorporationFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormCorporation : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label7;
    TLabel *Label8;
    TLabel *Label9;
    TEdit *Edit1;
    TEdit *Edit2;
    TEdit *Edit3;
    TEdit *Edit4;
    TEdit *Edit5;
    TEdit *Edit6;
    TEdit *Edit7;
    TEdit *Edit8;
    TEdit *Edit9;
    TBitBtn *BtnOK;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
    void __fastcall Edit2KeyPress(TObject *Sender, char &Key);
    void __fastcall Edit3KeyPress(TObject *Sender, char &Key);
    void __fastcall Edit4KeyPress(TObject *Sender, char &Key);
    void __fastcall Edit5KeyPress(TObject *Sender, char &Key);
    void __fastcall Edit6KeyPress(TObject *Sender, char &Key);
    void __fastcall Edit7KeyPress(TObject *Sender, char &Key);
    void __fastcall Edit8KeyPress(TObject *Sender, char &Key);
    void __fastcall Edit9KeyPress(TObject *Sender, char &Key);
    void __fastcall BtnOKClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFormCorporation(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormCorporation *FormCorporation;
//---------------------------------------------------------------------------
#endif
