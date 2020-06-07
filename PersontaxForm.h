//---------------------------------------------------------------------------
#ifndef PersontaxFormH
#define PersontaxFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormPersontax : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TPanel *Panel2;
    TListView *ListView1;
    TGroupBox *GroupBox1;
    TComboBox *ComboBox1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TEdit *Edit1;
    TEdit *Edit2;
    TGroupBox *GroupBox2;
    TLabel *Label5;
    TLabel *Label4;
    TLabel *Label6;
    TLabel *Label7;
    TLabel *Label8;
    TLabel *Label9;
    TLabel *Label10;
    TLabel *Label11;
    TEdit *Edit3;
    TEdit *Edit4;
    TEdit *Edit5;
    TEdit *Edit6;
    TEdit *Edit7;
    TEdit *Edit8;
    TEdit *Edit9;
    TEdit *Edit10;
    TBitBtn *BtnOK;
    TBitBtn *BitBtn1;
    TEdit *Edit0;
    TLabel *Label12;
    TBitBtn *BitBtn2;
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
    void __fastcall ComboBox1KeyPress(TObject *Sender, char &Key);
    void __fastcall ComboBox1Change(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    
    void __fastcall BtnOKClick(TObject *Sender);
    void __fastcall Edit0KeyPress(TObject *Sender, char &Key);
    
    void __fastcall BitBtn1Click(TObject *Sender);
    void __fastcall BitBtn2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFormPersontax(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPersontax *FormPersontax;
//---------------------------------------------------------------------------
#endif
