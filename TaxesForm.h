//---------------------------------------------------------------------------
#ifndef TaxesFormH
#define TaxesFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormTaxes : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TLabel *Label1;
    TEdit *Edit1;
    TBitBtn *BtnOK;
    TLabel *Label2;
    TEdit *Edit2;
    TPanel *Panel2;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
    void __fastcall BtnOKClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall Edit2KeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
    __fastcall TFormTaxes(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormTaxes *FormTaxes;
//---------------------------------------------------------------------------
#endif
