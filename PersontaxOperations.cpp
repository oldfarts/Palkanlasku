//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "PersontaxOperations.h"
#include <iostream.h>
#include <fstream.h>

PersontaxOperations *persontaxOperations = new PersontaxOperations;
//--------------------------------------------------------------------------
PersontaxOperations::PersontaxOperations()
{
    howMany = 0;
    counter=0;
    apu=0;
}
PersontaxOperations::~PersontaxOperations()
{
}
//--------------------------------------------------------------------------
int PersontaxOperations::GetSize()
{
    return howMany;
}
//--------------------------------------------------------------------------
int PersontaxOperations::GetCounter()
{
    return counter;
}
void PersontaxOperations::SetCounter()
{
    counter = 0;
}
//--------------------------------------------------------------------------
int PersontaxOperations::GetApu()
{
    return apu;
}
//--------------------------------------------------------------------------
//Funktiota k‰ytet‰‰n lis‰‰m‰‰n tietoja
void PersontaxOperations::AddEntry(AnsiString &pNumber, AnsiString &lName,
    AnsiString &fName, AnsiString &tiliNum,AnsiString &pPros,AnsiString &lPros,
    AnsiString &vvTuloraja,AnsiString &kkTuloraja, AnsiString &kahdenvkTuloraja,
    AnsiString &vkTuloraja,AnsiString &pvTuloraja)
    {
    if (howMany < MAXPERSONS)
    {
        personTaxrates[howMany].PersonNumber     = pNumber;
        personTaxrates[howMany].LastName         = lName;
        personTaxrates[howMany].FirstName        = fName;
        personTaxrates[howMany].TiliNumero       = tiliNum;
        personTaxrates[howMany].PerusProsentti   = pPros;
        personTaxrates[howMany].LisaProsentti    = lPros;
        personTaxrates[howMany].VVTuloraja       = vvTuloraja;
        personTaxrates[howMany].KKTuloraja       = kkTuloraja;
        personTaxrates[howMany].KahdenVKTuloraja = kahdenvkTuloraja;
        personTaxrates[howMany].VKTuloraja       = vkTuloraja;
        personTaxrates[howMany].PVTuloraja       = pvTuloraja;
        howMany++;
    }
}
//--------------------------------------------------------------------------
//Funktiota k‰ytet‰‰n hakemaan tietoja
void PersontaxOperations::GetEntry(int index,
    AnsiString &pNumber, AnsiString &lName,  AnsiString &fName, AnsiString &tiliNum,
    AnsiString &pPros, AnsiString &lPros, AnsiString &vvTuloraja, AnsiString &kkTuloraja,
    AnsiString &kahdenvkTuloraja, AnsiString &vkTuloraja, AnsiString &pvTuloraja)
    {
    if (index >= 0 && index < howMany)
    {
        pNumber          = personTaxrates[index].PersonNumber;
        lName            = personTaxrates[index].LastName;
        fName            = personTaxrates[index].FirstName;
        tiliNum          = personTaxrates[index].TiliNumero;
        pPros            = personTaxrates[index].PerusProsentti;
        lPros            = personTaxrates[index].LisaProsentti;
        vvTuloraja       = personTaxrates[index].VVTuloraja;
        kkTuloraja       = personTaxrates[index].KKTuloraja;
        kahdenvkTuloraja = personTaxrates[index].KahdenVKTuloraja;
        vkTuloraja       = personTaxrates[index].VKTuloraja;
        pvTuloraja       = personTaxrates[index].PVTuloraja;
    }
}
//--------------------------------------------------------------------------
//Funktiolla haetaan tietoja verokorttia varten (PersontaxForm)
void PersontaxOperations::GetEntry2(int index,
        AnsiString &pNumber,AnsiString &lName,AnsiString &fName)
{
    if (index >= 0 && index < howMany)
    {
        pNumber    = personTaxrates[index].PersonNumber;
        lName      = personTaxrates[index].LastName;
        fName      = personTaxrates[index].FirstName;
    }
}
//--------------------------------------------------------------------------
//Funktiota k‰ytet‰‰n hakemaan tietoja
void PersontaxOperations::DeleteEntry(int index)
{
    if (index >= 0)
    {
        for (int i=index; i<howMany-1;i++)
            personTaxrates[i] = personTaxrates[i+1];
        howMany--;

        apu=0;     //Set own strings for NULL
        counter=0;
    }
}
//---------------------------------------------------------------------------
//Funktiota k‰ytet‰‰n nollaamaan kaikki olion tiedot..
void PersontaxOperations::DeleteAllEntries(void)
{
    for (int i=0; i<howMany;i++)
    {
        personTaxrates[howMany].PersonNumber     = "";
        personTaxrates[howMany].LastName         = "";
        personTaxrates[howMany].FirstName        = "";
        personTaxrates[howMany].TiliNumero       = "";
        personTaxrates[howMany].PerusProsentti   = "";
        personTaxrates[howMany].LisaProsentti    = "";
        personTaxrates[howMany].VVTuloraja       = "";
        personTaxrates[howMany].KKTuloraja       = "";
        personTaxrates[howMany].KahdenVKTuloraja = "";
        personTaxrates[howMany].VKTuloraja       = "";
        personTaxrates[howMany].PVTuloraja       = "";
    }
    howMany = 0;
    counter = 0;
}
//---------------------------------------------------------------------------
//Tietojen tallennus tiedostoon
void PersontaxOperations::SaveToFile(char *fileName)
{
    ofstream fout;
    fout.open(fileName); // avataan tiedosto
    if (!fout)
    {
        Application->MessageBox("Tiedoston avaus ei onnistu.", "Virheilmoitus", MB_OK);
    }
    else
    {
        for (int i=0;i<howMany;i++) // kirjoitetaan tiedot
        {
            fout << personTaxrates[i].PersonNumber.c_str() << endl;
            fout << personTaxrates[i].LastName.c_str() << endl;
            fout << personTaxrates[i].FirstName.c_str() << endl;
            fout << personTaxrates[i].TiliNumero.c_str() << endl;
            fout << personTaxrates[i].PerusProsentti.c_str() << endl;
            fout << personTaxrates[i].LisaProsentti.c_str() << endl;
            fout << personTaxrates[i].VVTuloraja.c_str() << endl;
            fout << personTaxrates[i].KKTuloraja.c_str() << endl;
            fout << personTaxrates[i].KahdenVKTuloraja.c_str() << endl;
            fout << personTaxrates[i].VKTuloraja.c_str() << endl;
            fout << personTaxrates[i].PVTuloraja.c_str() << endl;
        }
        fout.close();
        Application->MessageBox("Tiedot talletettu.", "Sanoma", MB_OK);
    }
}
//------------------------------------------------------------------------------
//Funktiota k‰ytet‰‰n tallettamaan henkilˆtietoja
void PersontaxOperations::LoadFromFile(char *fileName)
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
        while (!fin.eof() && (i<MAXPERSONS))
        {
            fin.getline(row, 120, '\n');
            personTaxrates[i].PersonNumber = row;
            fin.getline(row, 120, '\n');
            personTaxrates[i].LastName = row;
            fin.getline(row, 120, '\n');
            personTaxrates[i].FirstName = row;
            fin.getline(row, 120, '\n');
            personTaxrates[i].TiliNumero = row;
            fin.getline(row, 120, '\n');
            personTaxrates[i].PerusProsentti =row;
            fin.getline(row, 120, '\n');
            personTaxrates[i].LisaProsentti =row;
            fin.getline(row, 120, '\n');
            personTaxrates[i].VVTuloraja =row;
            fin.getline(row, 120, '\n');
            personTaxrates[i].KKTuloraja = row;
            fin.getline(row, 120, '\n');
            personTaxrates[i].KahdenVKTuloraja = row;
            fin.getline(row, 120, '\n');
            personTaxrates[i].VKTuloraja = row;
            fin.getline(row, 120, '\n');
            personTaxrates[i].PVTuloraja = row;
            i++;
        }
        fin.close();
        //howMany = i-1;    //indexointi?!?
        howMany  = i;
    }
}
//---------------------------------------------------------------------------
//Tiedoston sis‰llˆn tuhoaminen
void PersontaxOperations::DeleteFile(char *fileName)
{
    ofstream fout;
    fout.open(fileName); // avataan tiedosto
    if (!fout)
    {
        Application->MessageBox("Tiedoston avaus ei onnistu.", "Virheilmoitus", MB_OK);
    }
    else
    {
        for (int i=0;i<howMany;i++) // kirjoitetaan tiedot
        {
            fout << personTaxrates[i].PersonNumber.c_str() << endl;
            fout << personTaxrates[i].LastName.c_str() << endl;
            fout << personTaxrates[i].FirstName.c_str() << endl;
            fout << personTaxrates[i].TiliNumero.c_str() << endl;
            fout << personTaxrates[i].PerusProsentti.c_str() << endl;
            fout << personTaxrates[i].LisaProsentti.c_str() << endl;
            fout << personTaxrates[i].VVTuloraja.c_str() << endl;
            fout << personTaxrates[i].KKTuloraja.c_str() << endl;
            fout << personTaxrates[i].KahdenVKTuloraja.c_str() << endl;
            fout << personTaxrates[i].VKTuloraja.c_str() << endl;
            fout << personTaxrates[i].PVTuloraja.c_str() << endl;
        }
        fout.close();
    }
}
//------------------------------------------------------------------------------
//Funktiota k‰ytet‰‰n p‰ivitt‰m‰‰n henkilˆtietoja
void PersontaxOperations::UpdateEntry(AnsiString &pNumber, AnsiString &lName,  AnsiString &fName, AnsiString &tiliNum,
    AnsiString &pPros,AnsiString &lPros, AnsiString &vvTuloraja, AnsiString &kkTuloraja,
    AnsiString &kahdenvkTuloraja, AnsiString &vkTuloraja, AnsiString &pvTuloraja)
{
    personTaxrates[apu].PersonNumber     = pNumber;
    personTaxrates[apu].LastName         = lName;
    personTaxrates[apu].FirstName        = fName;
    personTaxrates[apu].TiliNumero       = tiliNum;
    personTaxrates[apu].PerusProsentti   = pPros;
    personTaxrates[apu].LisaProsentti    = lPros;
    personTaxrates[apu].VVTuloraja       = vvTuloraja;
    personTaxrates[apu].KKTuloraja       = kkTuloraja;
    personTaxrates[apu].KahdenVKTuloraja = kahdenvkTuloraja;
    personTaxrates[apu].VKTuloraja       = vkTuloraja;
    personTaxrates[apu].PVTuloraja       = pvTuloraja;
}
//---------------------------------------------------------------------------
void PersontaxOperations::GetForReport(AnsiString &pNum, AnsiString &lNa, AnsiString &fNa,
    AnsiString &pNumber, AnsiString &lName,  AnsiString &fName, AnsiString &tiliNum,
    AnsiString &pPros, AnsiString &lPros, AnsiString &vvTuloraja, AnsiString &kkTuloraja,
    AnsiString &kahdenvkTuloraja, AnsiString &vkTuloraja, AnsiString &pvTuloraja)
    {
    if (0 < howMany)
    {
        //K‰yd‰‰n l‰pi tiedosto ja etsit‰‰n vastaavta tiedot
        for(int i=0; i<howMany; i++)
        {
            if((pNum == personTaxrates[i].PersonNumber)&&
                (lNa ==personTaxrates[i].LastName)&&
                (fNa == personTaxrates[i].FirstName))
                {
                pNumber          = personTaxrates[i].PersonNumber;
                lName            = personTaxrates[i].LastName;
                fName            = personTaxrates[i].FirstName;
                tiliNum          = personTaxrates[i].TiliNumero;
                pPros            = personTaxrates[i].PerusProsentti;
                lPros            = personTaxrates[i].LisaProsentti;
                vvTuloraja       = personTaxrates[i].VVTuloraja;
                kkTuloraja       = personTaxrates[i].KKTuloraja;
                kahdenvkTuloraja = personTaxrates[i].KahdenVKTuloraja;
                vkTuloraja       = personTaxrates[i].VKTuloraja;
                pvTuloraja       = personTaxrates[i].PVTuloraja;
                }
        }
    }

}
//---------------------------------------------------------------------------
#pragma package(smart_init)
