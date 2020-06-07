//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <fstream.h>

#include "CorporationOperations.h"
CorporationOperations *corporationOperations = new CorporationOperations;
//--------------------------------------------------------------------------
CorporationOperations::CorporationOperations()
{
}
//--------------------------------------------------------------------------
CorporationOperations::~CorporationOperations()
{
}
//--------------------------------------------------------------------------
//Funktiota käytetään lisäämään tietoja
void CorporationOperations::AddEntry(AnsiString &name, AnsiString &address,
    AnsiString &postalCode, AnsiString &city,  AnsiString &land,
    AnsiString &phoneNumber,AnsiString &fax,   AnsiString &email, AnsiString &homePages)
{
        corporation.Name       = name;
        corporation.Address    = address;
        corporation.PostalCode = postalCode;
        corporation.City       = city;
        corporation.Land       = land;
        corporation.PhoneNumber= phoneNumber;
        corporation.Fax        = fax;
        corporation.Email      = email;
        corporation.HomePages  = homePages;
}
//--------------------------------------------------------------------------
//Funktiota käytetään hakemaan tietoja
void CorporationOperations::GetEntry(
    AnsiString &name, AnsiString &address, AnsiString &postalCode,
    AnsiString &city,  AnsiString &land,AnsiString &phoneNumber,
    AnsiString &fax,   AnsiString &email, AnsiString &homePages)
    {
        name       = corporation.Name;
        address    = corporation.Address;
        postalCode = corporation.PostalCode;
        city       = corporation.City;
        land       = corporation.Land;
        phoneNumber= corporation.PhoneNumber;
        fax        = corporation.Fax;
        email      = corporation.Email;
        homePages  = corporation.HomePages;
}
//---------------------------------------------------------------------------
//Funktiota käytetään nollaamaan kaikki olion tiedot..
void CorporationOperations::DeleteAllEntries(void)
{
        corporation.Name        = "";
        corporation.Address     = "";
        corporation.PostalCode  = "";
        corporation.City        = "";
        corporation.Land        = "";
        corporation.PhoneNumber = "";
        corporation.Fax         = "";
        corporation.Email       = "";
        corporation.HomePages   = "";
}
//---------------------------------------------------------------------------
//Tietojen tallennus tiedostoon
void CorporationOperations::SaveToFile(char *fileName)
{
    ofstream fout;
    fout.open(fileName); // avataan tiedosto
    if (!fout)
    {
        Application->MessageBox("Tiedoston avaus ei onnistu.", "Virheilmoitus", MB_OK);
    }
    else
    {
        fout << corporation.Name.c_str() << endl;
        fout << corporation.Address.c_str() << endl;
        fout << corporation.PostalCode.c_str() << endl;
        fout << corporation.City.c_str() << endl;
        fout << corporation.Land.c_str() << endl;
        fout << corporation.PhoneNumber.c_str() << endl;
        fout << corporation.Fax.c_str() << endl;
        fout << corporation.Email.c_str() << endl;
        fout << corporation.HomePages.c_str() << endl;
    }
    fout.close();
    Application->MessageBox("Tiedot talletettu.", "Tietojen talletus", MB_OK);
}
//------------------------------------------------------------------------------
//Funktiota käytetään tallettamaan henkilötietoja
void CorporationOperations::LoadFromFile(char *fileName)
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
        while (!fin.eof() && (i<1))
        {
            fin.getline(row, 120, '\n');
            corporation.Name = row;
            fin.getline(row, 120, '\n');
            corporation.Address = row;
            fin.getline(row, 120, '\n');
            corporation.PostalCode = row;
            fin.getline(row, 120, '\n');
            corporation.City =row;
            fin.getline(row, 120, '\n');
            corporation.Land =row;
            fin.getline(row, 120, '\n');
            corporation.PhoneNumber =row;
            fin.getline(row, 120, '\n');
            corporation.Fax = row;
            fin.getline(row, 120, '\n');
            corporation.Email = row;
            fin.getline(row, 120, '\n');
            corporation.HomePages = row;
            i++;
        }
        fin.close();
    }
}
//---------------------------------------------------------------------------
//Tiedoston sisällön tuhoaminen
void CorporationOperations::DeleteFile(char *fileName)
{
    ofstream fout;
    fout.open(fileName); // avataan tiedosto
    if (!fout)
    {
        Application->MessageBox("Tiedoston avaus ei onnistu.", "Virheilmoitus", MB_OK);
    }
    else
    {
        fout << corporation.Name.c_str() << endl;
        fout << corporation.Address.c_str() << endl;
        fout << corporation.PostalCode.c_str() << endl;
        fout << corporation.City.c_str() << endl;
        fout << corporation.Land.c_str() << endl;
        fout << corporation.PhoneNumber.c_str() << endl;
        fout << corporation.Fax.c_str() << endl;
        fout << corporation.Email.c_str() << endl;
        fout << corporation.HomePages.c_str() << endl;
    }
    fout.close();
}
//------------------------------------------------------------------------------
//Funktiota käytetään päivittämään henkilötietoja
void CorporationOperations::UpdateEntry(
    AnsiString &name, AnsiString &address, AnsiString &postalCode,
    AnsiString &city,  AnsiString &land,AnsiString &phoneNumber,
    AnsiString &fax,   AnsiString &email, AnsiString &homePages)
{

    corporation.Name         = name;
    corporation.Address      = address;
    corporation.PostalCode   = postalCode;
    corporation.City         = city;
    corporation.Land         = land;
    corporation.PhoneNumber  = phoneNumber;
    corporation.Fax          = fax;
    corporation.Email        = email;
    corporation.HomePages    = homePages;
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
