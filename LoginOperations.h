//---------------------------------------------------------------------------
#ifndef LoginOperationsH
#define LoginOperationsH
#define MAXLOGINUSERS 30
#include "Person.h"
class LoginOperations
{
private:
    PersonRights persons[MAXLOGINUSERS];
    int howMany; // talletettujen lukum‰‰r‰

    int counter; //P‰ivitys ja tarakastelutietoja varten
    int apu;
public:
    LoginOperations();
    ~LoginOperations();

    int OpenFileAndFindUsers(AnsiString &userName, AnsiString &passWord);
    void LoadFromFile(char *);
    void SaveToFile(char *);
    void DeleteFile(char *);

    void AddEntry(AnsiString &lName, AnsiString &fName,
    AnsiString &userName, AnsiString &passWord, AnsiString &userRights);
    void GetEntry(int index, AnsiString &lName, AnsiString &fName,
    AnsiString &userName, AnsiString &passWord, AnsiString &userRights);
    void UpdateEntry(AnsiString &lName, AnsiString &fName,
    AnsiString &userName, AnsiString &passWord, AnsiString &userRights);

    void DeleteEntry(int index);
    void DeleteAllEntries(void); //Nollataan kaikki tiedot
    int GetSize();

    int GetApu();
    int GetCounter();
    void SetCounter();
    void IncInput(); //Editointia varten (++)
    void DecInput(); //Editointia varten (--)

    //ListView-oliota varten  ..
    int GetUsers(AnsiString &lName,int &userindex);
};
extern LoginOperations *logins;
//---------------------------------------------------------------------------
#endif
