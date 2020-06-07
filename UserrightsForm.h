//---------------------------------------------------------------------------
#ifndef UserrightsFormH
#define UserrightsFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormUserrights : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TEdit *LName;
    TEdit *FName;
    TEdit *UID;
    TEdit *UsrR;
    TEdit *PWD;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TBitBtn *BtnOK;
    TButton *BtClrChosen;
    TButton *BtClearAll;
    TBitBtn *BtNew;
    TSpeedButton *SBPrevious;
    TSpeedButton *SBNext;
    TBitBtn *BtCreateNew;
    TPanel *Panel2;
    TListView *ListView1;
    TBitBtn *BtUpdate;
    TBitBtn *BtGet;
    TBitBtn *BtSave1;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall LNameKeyPress(TObject *Sender, char &Key);
    void __fastcall FNameKeyPress(TObject *Sender, char &Key);
    void __fastcall UIDKeyPress(TObject *Sender, char &Key);
    void __fastcall PWDKeyPress(TObject *Sender, char &Key);
    void __fastcall UsrRKeyPress(TObject *Sender, char &Key);
    void __fastcall BtnOKClick(TObject *Sender);
    void __fastcall BtClearAllClick(TObject *Sender);
    void __fastcall BtClrChosenClick(TObject *Sender);
    void __fastcall BtNewClick(TObject *Sender);
    void __fastcall BtnOKKeyPress(TObject *Sender, char &Key);
    void __fastcall SBPreviousClick(TObject *Sender);
    void __fastcall SBNextClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall BtCreateNewClick(TObject *Sender);
    void __fastcall ListView1DblClick(TObject *Sender);
    
    
    void __fastcall ListView1Click(TObject *Sender);
    void __fastcall BtSave1Click(TObject *Sender);
    void __fastcall BtGetClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFormUserrights(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormUserrights *FormUserrights;
//---------------------------------------------------------------------------
#endif
