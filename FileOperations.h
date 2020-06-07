//---------------------------------------------------------------------------
#ifndef FileOperationsH
#define FileOperationsH
#define MAXPERSONS 30
#include "Person.h"
class FileOperations
{
private:
    Person persons[MAXPERSONS];
    int howMany; // talletettujen lukum‰‰r‰

    int counter; //P‰ivitys ja tarakastelutietoja varten
    int apu;
public:
    FileOperations();
    void LoadFromFile(char *);
    void SaveToFile(char *);
    void AddEntry(AnsiString &firstName, AnsiString &lastName,
    AnsiString &address, AnsiString &postalCode, AnsiString &city,
    AnsiString &land, AnsiString &homeNumber, AnsiString &mobileNumber,
    AnsiString &homeEmail);
    void GetEntry(int index, AnsiString &firstName, AnsiString &lastName,
    AnsiString &address, AnsiString &postalCode, AnsiString &city,
    AnsiString &land, AnsiString &homeNumber, AnsiString &mobileNumber,
    AnsiString &homeEmail);
    void DeleteEntry(int index);
    int GetSize();

    int GetApu();
    int GetCounter();
    void IncInput(); //Editointia varten (++)
    void DecInput(); //Editointia varten (--)
    void UpdateEntry(AnsiString &firstName, AnsiString &lastName,
     AnsiString &address, AnsiString &postalCode, AnsiString &city, AnsiString &land,
     AnsiString &homeNumber, AnsiString &mobileNumber, AnsiString &homeEmail);
};
//extern FileOperations *FileOperations;
//---------------------------------------------------------------------------
#endif
