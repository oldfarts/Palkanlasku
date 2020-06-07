//---------------------------------------------------------------------------
#ifndef TaxOperationsH
#define TaxOperationsH
#define MAXONE 1
#include "Taxes.h"
class TaxOperations
{
private:
    Taxes taxes;       //Yleisten verotustieojen luokka (kts. 'Taxes.h')
    int howMany;
public:
    TaxOperations();
    ~TaxOperations();

    void LoadFromFile(char *);
    void SaveToFile(char *);
    void DeleteFile(char *);

    void AddEntry(AnsiString &tel,AnsiString &vak);
    void GetEntry(AnsiString &tel,AnsiString &vak);
    void UpdateEntry(AnsiString &tel,AnsiString &vak);
    int CheckSize(void);
};

extern TaxOperations *taxOperations;
//---------------------------------------------------------------------------
#endif
