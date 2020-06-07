//---------------------------------------------------------------------------
#ifndef CountSalaryFormH
#define CountSalaryFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormCountSalary : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TPanel *Panel2;
    TGroupBox *GroupBox1;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label7;
    TEdit *Edit4;
    TLabel *Label8;
    TLabel *Label9;
    TEdit *Edit5;
    TGroupBox *GroupBox2;
    TLabel *Label10;
    TLabel *Label11;
    TLabel *Label12;
    TEdit *Edit9;
    TLabel *Label13;
    TGroupBox *GroupBox3;
    TLabel *Label14;
    TLabel *Label15;
    TLabel *Label16;
    TLabel *Label17;
    TEdit *Edit13;
    TEdit *Edit14;
    TLabel *Label18;
    TEdit *Edit15;
    TLabel *Label19;
    TEdit *Edit16;
    TLabel *Label20;
    TGroupBox *GroupBox4;
    TLabel *Label1;
    TComboBox *ComboBox1;
    TLabel *Label2;
    TEdit *Edit1;
    TLabel *Label3;
    TEdit *Edit2;
    TLabel *Label4;
    TEdit *Edit3;
    TListView *ListView1;
    TBitBtn *BtnOK;
    TEdit *Edit6;
    TEdit *Edit7;
    TEdit *Edit8;
    TEdit *Edit10;
    TEdit *Edit11;
    TEdit *Edit12;
    TEdit *Edit17;
    TEdit *Edit18;
    TEdit *Edit19;
    TButton *btSave;
    TBitBtn *BitBtn1;
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
    void __fastcall Edit10KeyPress(TObject *Sender, char &Key);
    void __fastcall Edit11KeyPress(TObject *Sender, char &Key);
    void __fastcall Edit12KeyPress(TObject *Sender, char &Key);
    void __fastcall Edit13KeyPress(TObject *Sender, char &Key);
    void __fastcall Edit14KeyPress(TObject *Sender, char &Key);
    void __fastcall Edit15KeyPress(TObject *Sender, char &Key);
    void __fastcall Edit16KeyPress(TObject *Sender, char &Key);
    
    void __fastcall BtnOKClick(TObject *Sender);
    void __fastcall btSaveClick(TObject *Sender);
    void __fastcall BitBtn1Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall ComboBox1KeyPress(TObject *Sender, char &Key);
    void __fastcall ComboBox1Change(TObject *Sender);
    
    void __fastcall ListView1Click(TObject *Sender);
    void __fastcall ListView1DblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFormCountSalary(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormCountSalary *FormCountSalary;
//---------------------------------------------------------------------------
#endif
