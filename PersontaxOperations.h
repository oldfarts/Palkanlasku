//---------------------------------------------------------------------------
#ifndef PersontaxOperationsH
#define PersontaxOperationsH
#define MAXPERSONS 30
#include "Person.h"
class PersontaxOperations
{
private:
    PersonTaxrate personTaxrates[MAXPERSONS];
    int howMany; // talletettujen lukumäärä

    int counter; //Päivitys ja tarakastelutietoja varten
    int apu;
public:
    PersontaxOperations();
    ~PersontaxOperations();

    void LoadFromFile(char *);
    void SaveToFile(char *);
    void DeleteFile(char *);

    void AddEntry(AnsiString &pNumber, AnsiString &lName,
    AnsiString &fName, AnsiString &tiliNum, AnsiString &pPros,AnsiString &lPros,
    AnsiString &vvTuloraja,AnsiString &kkTuloraja, AnsiString &kahdenvkTuloraja,
    AnsiString &vkTuloraja, AnsiString &pvTuloraja);
    void GetEntry(int index,
    AnsiString &pNumber, AnsiString &lName,  AnsiString &fName, AnsiString &tiliNum,
    AnsiString &pPros, AnsiString &lPros, AnsiString &vvTuloraja, AnsiString &kkTuloraja,
    AnsiString &kahdenvkTuloraja, AnsiString &vkTuloraja, AnsiString &pvTuloraja);
    void UpdateEntry(
    AnsiString &pNumber, AnsiString &lName,  AnsiString &fName, AnsiString &tiliNum,
    AnsiString &pPros,AnsiString &lPros, AnsiString &vvTuloraja, AnsiString &kkTuloraja,
    AnsiString &kahdenvkTuloraja, AnsiString &vkTuloraja, AnsiString &pvTuloraja);

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
    AnsiString &pNumber, AnsiString &lName,  AnsiString &fName, AnsiString &tiliNum,
    AnsiString &pPros, AnsiString &lPros, AnsiString &vvTuloraja, AnsiString &kkTuloraja,
    AnsiString &kahdenvkTuloraja, AnsiString &vkTuloraja, AnsiString &pvTuloraja);
};
extern PersontaxOperations *persontaxOperations;
//---------------------------------------------------------------------------
#endif
