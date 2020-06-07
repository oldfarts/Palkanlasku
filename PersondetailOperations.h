//---------------------------------------------------------------------------
#ifndef PersondetailOperationsH
#define PersondetailOperationsH
#define MAXPERSONS 30
#include "Person.h"
class PersondetailOperations
{
private:
    Person persons[MAXPERSONS];
    int howMany; // talletettujen lukumäärä

    int counter; //Päivitys ja tarakastelutietoja varten
    int apu;
public:
    PersondetailOperations();

    void LoadFromFile(char *);
    void SaveToFile(char *);
    void DeleteFile(char *);

    void AddEntry(
    AnsiString &pNumber,    AnsiString &lName, AnsiString &fName,
    AnsiString &socCode,    AnsiString &date, AnsiString &date2,
    AnsiString &date3,      AnsiString &address,
    AnsiString &postalCode, AnsiString &city,  AnsiString &land,
    AnsiString &homeNumber, AnsiString &gsm,   AnsiString &email);
    void GetEntry(int index,
    AnsiString &pNumber,    AnsiString &lName, AnsiString &fName,
    AnsiString &socCode,    AnsiString &date,  AnsiString &date2,
    AnsiString &date3,      AnsiString &address,
    AnsiString &postalCode, AnsiString &city,  AnsiString &land,
    AnsiString &homeNumber, AnsiString &gsm,   AnsiString &email);
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

    //Henkilön verotietoja varten (PersontaxForm)
    void GetEntry2(int index,
        AnsiString &pNumber,    AnsiString &lName, AnsiString &fName);

    //Raporttien tulostusta varten
    void GetForReport(AnsiString &pNum, AnsiString &lNa, AnsiString &fNa,
    AnsiString &pNumber,    AnsiString &lName, AnsiString &fName,
    AnsiString &socCode,    AnsiString &date,  AnsiString &date2,
    AnsiString &date3,      AnsiString &address,
    AnsiString &postalCode, AnsiString &city,  AnsiString &land,
    AnsiString &homeNumber, AnsiString &gsm,   AnsiString &email);

};
extern PersondetailOperations *personOperations;
//---------------------------------------------------------------------------
#endif
