//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USEFORM("MainForm.cpp", FormMain);
USEFORM("AboutForm.cpp", FormAbout);
USEFORM("UserrightsForm.cpp", FormUserrights);
USEFORM("LoginForm.cpp", FormLogin);
USEFORM("PersondetailForm.cpp", FormPersondetail);
USEFORM("PersontaxForm.cpp", FormPersontax);
USEFORM("CorporationForm.cpp", FormCorporation);
USEFORM("TaxesForm.cpp", FormTaxes);
USEFORM("CountSalaryForm.cpp", FormCountSalary);
USEFORM("PaySlipDialogi.cpp", PaySlipDialog);
USEFORM("PaySlipReport.cpp", QuickReport1);
USEFORM("compositeReport.cpp", Form1);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->Title = "Palkanlasku Ohjelma";
                 Application->CreateForm(__classid(TFormMain), &FormMain);
                 Application->CreateForm(__classid(TFormAbout), &FormAbout);
                 Application->CreateForm(__classid(TFormLogin), &FormLogin);
                 Application->CreateForm(__classid(TPaySlipDialog), &PaySlipDialog);
                 Application->CreateForm(__classid(TQuickReport1), &QuickReport1);
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
