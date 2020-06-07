//----------------------------------------------------------------------------
#ifndef OCBH
#define OCBH
//----------------------------------------------------------------------------
#include <System.hpp>
#include <Windows.hpp>
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Graphics.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//----------------------------------------------------------------------------
class TPaySlipDialog : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
    TLabel *Label1;
    TComboBox *ComboBox1;
    TEdit *Edit2;
    TEdit *Edit3;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TEdit *Edit1;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall CancelBtnClick(TObject *Sender);
    void __fastcall OKBtnClick(TObject *Sender);
    void __fastcall ComboBox1KeyPress(TObject *Sender, char &Key);
    void __fastcall ComboBox1Change(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:
public:
	virtual __fastcall TPaySlipDialog(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TPaySlipDialog *PaySlipDialog;
//----------------------------------------------------------------------------
#endif
