//---------------------------------------------------------------------------
#ifndef CorporationOperationsH
#define CorporationOperationsH
#include "Corporation.h"
class CorporationOperations
{
private:
    Corporation corporation;
public:
    CorporationOperations();
    ~CorporationOperations();

    void LoadFromFile(char *);
    void SaveToFile(char *);
    void DeleteFile(char *);

    void AddEntry(
    AnsiString &name, AnsiString &address, AnsiString &postalCode,
    AnsiString &city,  AnsiString &land,AnsiString &phoneNumber,
    AnsiString &fax,   AnsiString &email, AnsiString &homePages);
    void GetEntry(
    AnsiString &name, AnsiString &address, AnsiString &postalCode,
    AnsiString &city,  AnsiString &land,AnsiString &phoneNumber,
    AnsiString &fax,   AnsiString &email, AnsiString &homePages);
    void UpdateEntry(
    AnsiString &name, AnsiString &address, AnsiString &postalCode,
    AnsiString &city,  AnsiString &land,AnsiString &phoneNumber,
    AnsiString &fax,   AnsiString &email, AnsiString &homePages);
    void DeleteAllEntries(void); //Nollataan kaikki tiedot

};
extern CorporationOperations *corporationOperations;
//---------------------------------------------------------------------------
#endif
 