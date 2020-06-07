//---------------------------------------------------------------------------
#ifndef CountSalaryOperationsH
#define CountSalaryOperationsH
#define MAXPERSONS 30
#include "Taxes.h"              //Palkanlaskenta-luokka
class SalaryOperations
{
private:
    Salary salary[MAXPERSONS];
    int howMany; // talletettujen lukumäärä

    int counter; //Päivitys ja tarakastelutietoja varten
    int apu;
public:
    SalaryOperations();

    void LoadFromFile(char *);
    void SaveToFile(char *);
    void DeleteFile(char *);

    void AddEntry(
    AnsiString &pNumber,    AnsiString &lName, AnsiString &fName,
    AnsiString &socCode,    AnsiString &date, AnsiString &date2,
    AnsiString &date3,      AnsiString &address,
    AnsiString &postalCode, AnsiString &city,  AnsiString &land,
    AnsiString &homeNumber, AnsiString &gsm,   AnsiString &email,
    AnsiString &jee, AnsiString &kee, AnsiString &lee, AnsiString &mee,
    AnsiString &nee);
    void GetEntry(int index,
    AnsiString &pNumber,    AnsiString &lName, AnsiString &fName,
    AnsiString &socCode,    AnsiString &date,  AnsiString &date2,
    AnsiString &date3,      AnsiString &address,
    AnsiString &postalCode, AnsiString &city,  AnsiString &land,
    AnsiString &homeNumber, AnsiString &gsm,   AnsiString &email,
    AnsiString &jee, AnsiString &kee, AnsiString &lee, AnsiString &mee,
    AnsiString &nee);
    void UpdateEntry(
    AnsiString &pNumber,    AnsiString &lName, AnsiString &fName,
    AnsiString &socCode,    AnsiString &date,  AnsiString &date2,
    AnsiString &date3,      AnsiString &address,
    AnsiString &postalCode, AnsiString &city,  AnsiString &land,
    AnsiString &homeNumber, AnsiString &gsm,   AnsiString &email);

    void DeleteEntry(int index);
    void DeleteAllEntries(void); //Nollataan kaikki tiedot

    int GetSize();
    int GetApu();
    int GetCounter();
    void SetCounter();

    //ListView-oliota varten  ..
    int GetUsers(AnsiString &lName,int &userindex);
    int GetPerson(AnsiString &lName, int &userindex);

    //Henkilön verotietoja varten (PersontaxForm)
    void GetEntry2(int index,
        AnsiString &pNumber,    AnsiString &lName, AnsiString &fName);

    //Raporttia varten
    void GetForReport(AnsiString &pNum, AnsiString &lNa, AnsiString &fNa,
    AnsiString &pNumber, AnsiString &lName,  AnsiString &fName, AnsiString &startDate,
    AnsiString &endDate, AnsiString &ustartDate, AnsiString &days, AnsiString &hours,
    AnsiString &salary, AnsiString &ylityo, AnsiString &ytuntihinta,AnsiString &yhteensa,
    AnsiString &lomaraha, AnsiString &lomakorvaus);
};
extern SalaryOperations *salaryOperations;
//---------------------------------------------------------------------------
#endif
