//---------------------------------------------------------------------------
#ifndef CountPrevSalaryOperatiosH
#define CountPrevSalaryOperatiosH
#define MAXPERSONS 30
#include "Taxes.h"              //Palkanlaskenta-luokka
class SalaryPreviousOperations
{
private:
    SalaryPrevious salaryPrevious[MAXPERSONS];
    int howMany; // talletettujen lukumäärä

    int counter; //Päivitys ja tarakastelutietoja varten
    int apu;
public:
    SalaryPreviousOperations();

    void LoadFromFile(char *);
    void SaveToFile(char *);
    void DeleteFile(char *);

    void AddEntry(
    AnsiString &pNumber,         AnsiString &lName, AnsiString &fName,
    AnsiString &payslipStart,    AnsiString &payslipEnd,
    AnsiString &periodtimeLimit, AnsiString &paycumulTax,
    AnsiString &taxDays,         AnsiString &payrolltaxCum,
    AnsiString &salaryMonth,     AnsiString &taxableIncome,
    AnsiString &lisat,           AnsiString &vahennykset);
    void UpdateEntry(AnsiString &pNum, AnsiString &lNa, AnsiString &fNa,
    AnsiString &payslipStart,    AnsiString &payslipEnd,
    AnsiString &periodtimeLimit, AnsiString &paycumulTax,
    AnsiString &taxDays,         AnsiString &payrolltaxCum,
    AnsiString &salaryMonth,     AnsiString &taxableIncome,
    AnsiString &lisat,           AnsiString &vahennykset);

    void GetEntry(int index,
    AnsiString &pNumber,         AnsiString &lName, AnsiString &fName,
    AnsiString &payslipStart,    AnsiString &payslipEnd,
    AnsiString &periodtimeLimit, AnsiString &paycumulTax,
    AnsiString &taxDays,         AnsiString &payrolltaxCum,
    AnsiString &salaryMonth,     AnsiString &taxableIncome,
    AnsiString &lisat,           AnsiString &vahennykset);

    void DeleteEntry(int index);
    void DeleteAllEntries(void); //Nollataan kaikki tiedot

    int GetSize();
    int GetApu();
    int GetCounter();
    void SetCounter();

    //ListView-oliota varten  ..
    int GetUsers(AnsiString &lName,int &userindex);

    //Henkilön verotietoja varten (PersontaxForm)
    void GetEntry2(int index,
        AnsiString &pNumber,    AnsiString &lName, AnsiString &fName);

    //Raporttia varten
    void GetForReport(AnsiString &pNum, AnsiString &lNa, AnsiString &fNa,
    AnsiString &pNumber,         AnsiString &lName, AnsiString &fName,
    AnsiString &payslipStart,    AnsiString &payslipEnd,
    AnsiString &periodtimeLimit, AnsiString &paycumulTax,
    AnsiString &taxDays,         AnsiString &payrolltaxCum,
    AnsiString &salaryMonth,     AnsiString &taxableIncome,
    AnsiString &lisat,           AnsiString &vahennykset);
    bool CheckSalary(AnsiString &pNum, AnsiString &lNa, AnsiString &fNa);
};
extern SalaryPreviousOperations *salaryprevOperations;
//---------------------------------------------------------------------------
#endif
