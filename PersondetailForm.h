//---------------------------------------------------------------------------
#ifndef PersondetailFormH
#define PersondetailFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormPersondetail : public TForm
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
    TEdit *Edit10;
    TPanel *Panel2;
    TListView *ListView1;
    TLabel *Label10;
    TLabel *Label11;
    TLabel *Label12;
    TEdit *Edit11;
    TBitBtn *BtCreateNew;
    TButton *btOpenFile;
    TButton *btOpenFromFile;
    TBitBtn *BtNew;
    TButton *btSave;
    TSpeedButton *SBPrevious;
    TSpeedButton *SBNext;
    TButton *BtClearAll;
    TButton *BtClrChosen;
    TBitBtn *BtnOK;
    TLabel *Label13;
    TLabel *Label14;
    TEdit *Edit12;
    TEdit *Edit13;
    TEdit *Edit14;
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
    
    void __fastcall btOpenFileClick(TObject *Sender);
    void __fastcall btOpenFromFileClick(TObject *Sender);
    void __fastcall btSaveClick(TObject *Sender);
    void __fastcall BtCreateNewClick(TObject *Sender);
    void __fastcall BtNewClick(TObject *Sender);
    void __fastcall BtClearAllClick(TObject *Sender);
    void __fastcall BtClrChosenClick(TObject *Sender);
    void __fastcall BtnOKClick(TObject *Sender);
    void __fastcall Edit12KeyPress(TObject *Sender, char &Key);
    void __fastcall Edit13KeyPress(TObject *Sender, char &Key);
    void __fastcall Edit14KeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
    __fastcall TFormPersondetail(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPersondetail *FormPersondetail;
//---------------------------------------------------------------------------
#endif
