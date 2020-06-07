//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "LoginForm.h"
//#include "Help.h"
#include "MainForm.h"
//#include "Register.h"
#include "LoginOperations.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormLogin *FormLogin;
//---------------------------------------------------------------------------
__fastcall TFormLogin::TFormLogin(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
//Default kun ("Enter") nappia painetaan->seuraavalle riville(TabOrder!!!)
void __fastcall TFormLogin::NameKeyPress(TObject *Sender, char &Key)
{
    if (Key == VK_RETURN) // onko Enter painettu?
    {
        Key = 0; // poistetaan napin painallus
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0); //l�hetet��n Windosille viesti siirty� seuraavaan input-kontrolliin
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormLogin::btOkClick(TObject *Sender)
{
    /*AnsiString userName;
    AnsiString passWord;

    userName=txtUserId->Text;
    passWord=txtPassword->Text;

    int result = logins->FindUsers(userName, passWord);
    //ShowMessage(result);
    //Check reults
    switch(result){
    case 0:
        FormLogin->Close();
        ShowMessage("Tarkista k�ytt�j�tunnus ja salasana");
        FormMain->Close();
        break;
    case 1:
        FormLogin->Close();
        //ShowMessage("Tervetuloa");
        break;
    default:
        FormLogin->Close();
        FormMain->Close();
        break;
    }   */
    /*FormLogin->*/Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormLogin::btHelpClick(TObject *Sender)
{
    //Create help form
    /*THelpForm *HelpForm = new THelpForm(this);
    //Show hints
    HelpForm->ShowModal();*/
}
//---------------------------------------------------------------------------
void __fastcall TFormLogin::FormCreate(TObject *Sender)
{
    txtUserId->SetFocus();    
}
//---------------------------------------------------------------------------
void __fastcall TFormLogin::FormActivate(TObject *Sender)
{
    txtUserId->SetFocus();    
}
//---------------------------------------------------------------------------
void __fastcall TFormLogin::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    AnsiString userName;
    AnsiString passWord;

    userName=txtUserId->Text;
    passWord=txtPassword->Text;

    //Avataan k�ytt�j�tiedosto ja luetaan muistiin k�ytt�j�tiedot
    //joita voidaan jatkossa k�ytt�� hyv�ksi
    int result = logins->OpenFileAndFindUsers(userName, passWord);
    //ShowMessage(result);
   
    switch(result){
    case 0:
        FormLogin->Close();
        ShowMessage("Tarkista k�ytt�j�tunnus ja salasana");
        FormMain->Close();
        break;
    case 1:
        FormLogin->Close();
        //ShowMessage("Tervetuloa");
        break;
    default:
        FormLogin->Close();
        FormMain->Close();
        break;
    }
}
//---------------------------------------------------------------------------

