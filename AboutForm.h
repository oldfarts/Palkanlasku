//----------------------------------------------------------------------------
#ifndef AboutFormH
#define AboutFormH
//----------------------------------------------------------------------------
#include <System.hpp>
#include <Windows.hpp>
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Graphics.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//----------------------------------------------------------------------------
class TFormAbout : public TForm
{
__published:
	TPanel *Panel1;
	TImage *ProgramIcon;
	TLabel *ProductName;
	TLabel *Version;
	TLabel *Copyright;
	TLabel *Comments;
	TButton *OKButton;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    void __fastcall OKButtonClick(TObject *Sender);
private:
public:
	virtual __fastcall TFormAbout(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TFormAbout *FormAbout;
//----------------------------------------------------------------------------
#endif
