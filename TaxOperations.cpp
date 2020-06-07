//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TaxOperations.h"
#include <iostream.h>
#include <fstream.h>

TaxOperations *taxOperations = new TaxOperations;
//--------------------------------------------------------------------------
TaxOperations::TaxOperations()
{
    howMany = 0;
}
TaxOperations::~TaxOperations(){}
//--------------------------------------------------------------------------
int TaxOperations::CheckSize(void)
{
    return howMany;
}
//--------------------------------------------------------------------------
//Funktiota käytetään lisäämään tietoja
void TaxOperations::AddEntry(AnsiString &tel, AnsiString &vak)
{
    taxes.TEL  = tel;
    taxes.VAKU = vak;
}
//--------------------------------------------------------------------------
//Funktiota käytetään hakemaan tietoja
void TaxOperations::GetEntry(AnsiString &tel, AnsiString &vak)
{
    tel = taxes.TEL;
    vak = taxes.VAKU;
}
//---------------------------------------------------------------------------
//Tietojen tallennus tiedostoon
void TaxOperations::SaveToFile(char *fileName)
{
    ofstream fout;
    fout.open(fileName); // avataan tiedosto
    if (!fout)
    {
        Application->MessageBox("Tiedoston avaus ei onnistu.", "Virheilmoitus", MB_OK);
    }
    else
    {
        fout << taxes.TEL.c_str() << endl;
        fout << taxes.VAKU.c_str() << endl;
        fout.close();
        Application->MessageBox("Tiedot talletettu.", "Sanoma", MB_OK);
    }
}
//------------------------------------------------------------------------------
//Funktiota käytetään tallettamaan henkilötietoja
void TaxOperations::LoadFromFile(char *fileName)
{
    ifstream fin;
    fin.open(fileName);  // tiedoston avaus
    if (!fin)
    {
        Application->MessageBox("Tiedoston avaus ei onnistu.", "Virheilmoitus", MB_OK);
    }
    else // luetaan tiedosto taulukkoon
    {
        int i=0;
        char row[121];
        //Pakko tarkastaa että on <1, sillä muuten lukee tyhjän
        //rivin ja asettaa tyhjän rivin tiedot muuttujiin!!!!!!!!!!!
        while (!fin.eof()&&i<1)
        {
            fin.getline(row, 120, '\n');
            taxes.TEL = row;
            fin.getline(row, 120, '\n');
            taxes.VAKU = row;
            i++;
        }
        fin.close();
        howMany = 1;
    }
}
//---------------------------------------------------------------------------
//Tiedoston sisällön tuhoaminen
void TaxOperations::DeleteFile(char *fileName)
{
    ofstream fout;
    fout.open(fileName); // avataan tiedosto
    if (!fout)
    {
        Application->MessageBox("Tiedoston avaus ei onnistu.", "Virheilmoitus", MB_OK);
    }
    else
    {
        fout << taxes.TEL.c_str() << endl;
        fout << taxes.VAKU.c_str() << endl;
        fout.close();
    }
}
//------------------------------------------------------------------------------
//Funktiota käytetään päivittämään henkilötietoja
void TaxOperations::UpdateEntry(AnsiString &tel, AnsiString &vak)
{
    taxes.TEL  = tel;
    taxes.VAKU = vak;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
