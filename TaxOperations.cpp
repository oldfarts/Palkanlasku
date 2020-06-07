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
//Funktiota k�ytet��n lis��m��n tietoja
void TaxOperations::AddEntry(AnsiString &tel, AnsiString &vak)
{
    taxes.TEL  = tel;
    taxes.VAKU = vak;
}
//--------------------------------------------------------------------------
//Funktiota k�ytet��n hakemaan tietoja
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
//Funktiota k�ytet��n tallettamaan henkil�tietoja
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
        //Pakko tarkastaa ett� on <1, sill� muuten lukee tyhj�n
        //rivin ja asettaa tyhj�n rivin tiedot muuttujiin!!!!!!!!!!!
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
//Tiedoston sis�ll�n tuhoaminen
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
//Funktiota k�ytet��n p�ivitt�m��n henkil�tietoja
void TaxOperations::UpdateEntry(AnsiString &tel, AnsiString &vak)
{
    taxes.TEL  = tel;
    taxes.VAKU = vak;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
