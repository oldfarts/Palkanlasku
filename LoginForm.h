//---------------------------------------------------------------------------
#ifndef LoginFormH
#define LoginFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormLogin : public TForm
{
__published:	// IDE-managed Components
    TPanel *PanelLogin;
    TEdit *txtPassword;
    TEdit *txtUserId;
    TLabel *lblPassword;
    TLabel *lblUserId;
    TBitBtn *btOk;
    void __fastcall btOkClick(TObject *Sender);
    void __fastcall btHelpClick(TObject *Sender);
    
    void __fastcall NameKeyPress(TObject *Sender, char &Key);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);

    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
   private:	// User declarations
public:		// User declarations
    __fastcall TFormLogin(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormLogin *FormLogin;
//---------------------------------------------------------------------------
#endif
