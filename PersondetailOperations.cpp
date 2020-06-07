//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <fstream.h>

#include "PersondetailOperations.h"

PersondetailOperations *personOperations = new PersondetailOperations;
PersondetailOperations::PersondetailOperations()
{
    howMany = 0;
    counter=0;
    apu=0;
}
//--------------------------------------------------------------------------
int PersondetailOperations::GetSize()
{
    return howMany;
}
//--------------------------------------------------------------------------
int PersondetailOperations::GetCounter()
{
    return counter;
}
void PersondetailOperations::SetCounter()
{
    counter = 0;
}
//--------------------------------------------------------------------------
int PersondetailOperations::GetApu()
{
    return apu;
}
//--------------------------------------------------------------------------
//Funktiota k‰ytet‰‰n lis‰‰m‰‰n tietoja
void PersondetailOperations::AddEntry(    AnsiString &pNumber,    AnsiString &lName, AnsiString &fName,
    AnsiString &socCode,    AnsiString &date, AnsiString &date2,
    AnsiString &date3,      AnsiString &address,
    AnsiString &postalCode, AnsiString &city,  AnsiString &land,
    AnsiString &homeNumber, AnsiString &gsm,   AnsiString &email)
    {
    if (howMany < MAXPERSONS)
    {
        persons[howMany].PersonNumber = pNumber;
        persons[howMany].LastName = lName;
        persons[howMany].FirstName = fName;
        persons[howMany].SocialCode = socCode;
        persons[howMany].AddTime = date;
        persons[howMany].Add2Time = date2;
        persons[howMany].EndTime = date3;
        persons[howMany].Address = address;
        persons[howMany].PostalCode = postalCode;
        persons[howMany].City = city;
        persons[howMany].Land = land;
        persons[howMany].HomeNumber = homeNumber;
        persons[howMany].MobileNumber = gsm;
        persons[howMany].HomeEmail = email;
        howMany++;
    }
}
//--------------------------------------------------------------------------
//Funktiota k‰ytet‰‰n hakemaan tietoja
void PersondetailOperations::GetEntry(int index, AnsiString &pNumber,    AnsiString &lName, AnsiString &fName,
    AnsiString &socCode,    AnsiString &date,  AnsiString &date2,
    AnsiString &date3,      AnsiString &address,
    AnsiString &postalCode, AnsiString &city,  AnsiString &land,
    AnsiString &homeNumber, AnsiString &gsm,   AnsiString &email)
    {
    if (index >= 0 && index < howMany)
    {
        pNumber    = persons[index].PersonNumber;
        lName      = persons[index].LastName;
        fName      = persons[index].FirstName;
        socCode    = persons[index].SocialCode;
        date       = persons[index].AddTime;
        date2      = persons[index].Add2Time;
        date3      = persons[index].EndTime;
        address    = persons[index].Address;
        postalCode = persons[index].PostalCode;
        city       = persons[index].City;
        land       = persons[index].Land;
        homeNumber = persons[index].HomeNumber;
        gsm        = persons[index].MobileNumber;
        email      = persons[index].HomeEmail;
    }
}

//--------------------------------------------------------------------------
//Funktiota k‰ytet‰‰n hakemaan tietoja
void PersondetailOperations::DeleteEntry(int index)
{
    if (index >= 0)
    {
        for (int i=index; i<howMany-1;i++)
            persons[i] = persons[i+1];
        howMany--;

        apu=0;     //Set own strings for NULL
        counter=0;
    }
}
//---------------------------------------------------------------------------
//Funktiota k‰ytet‰‰n nollaamaan kaikki olion tiedot..
void PersondetailOperations::DeleteAllEntries(void)
{
    for (int i=0; i<howMany;i++)
    {
        persons[i].PersonNumber = "";
        persons[i].LastName = "";
        persons[i].FirstName = "";
        persons[i].SocialCode = "";
        persons[i].AddTime = "";
        persons[i].Add2Time = "";
        persons[i].EndTime = "";
        persons[i].Address = "";
        persons[i].PostalCode = "";
        persons[i].City = "";
        persons[i].Land = "";
        persons[i].HomeNumber = "";
        persons[i].MobileNumber = "";
        persons[i].HomeEmail = "";
    }
    howMany = 0;
    counter = 0;
}
//---------------------------------------------------------------------------
//Tietojen tallennus tiedostoon
void PersondetailOperations::SaveToFile(char *fileName)
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
            fout << persons[i].PersonNumber.c_str() << endl;
            fout << persons[i].LastName.c_str() << endl;
            fout << persons[i].FirstName.c_str() << endl;
            fout << persons[i].SocialCode.c_str() << endl;
            fout << persons[i].AddTime.c_str() << endl;
            fout << persons[i].Add2Time.c_str() << endl;
            fout << persons[i].EndTime.c_str() << endl;
            fout << persons[i].Address.c_str() << endl;
            fout << persons[i].PostalCode.c_str() << endl;
            fout << persons[i].City.c_str() << endl;
            fout << persons[i].Land.c_str() << endl;
            fout << persons[i].HomeNumber.c_str() << endl;
            fout << persons[i].MobileNumber.c_str() << endl;
            fout << persons[i].HomeEmail.c_str() << endl;
        }
        fout.close();
        Application->MessageBox("Tiedot talletettu.", "Sanoma", MB_OK);
    }
}
//------------------------------------------------------------------------------
//Funktiota k‰ytet‰‰n tallettamaan henkilˆtietoja
void PersondetailOperations::LoadFromFile(char *fileName)
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
            persons[i].PersonNumber = row;
            fin.getline(row, 120, '\n');
            persons[i].LastName = row;
            fin.getline(row, 120, '\n');
            persons[i].FirstName = row;
            fin.getline(row, 120, '\n');
            persons[i].SocialCode =row;
            fin.getline(row, 120, '\n');
            persons[i].AddTime =row;
            fin.getline(row, 120, '\n');
            persons[i].Add2Time =row;
            fin.getline(row, 120, '\n');
            persons[i].EndTime =row;
            fin.getline(row, 120, '\n');
            persons[i].Address =row;
            fin.getline(row, 120, '\n');
            persons[i].PostalCode = row;
            fin.getline(row, 120, '\n');
            persons[i].City = row;
            fin.getline(row, 120, '\n');
            persons[i].Land = row;
            fin.getline(row, 120, '\n');
            persons[i].HomeNumber = row;
            fin.getline(row, 120, '\n');
            persons[i].MobileNumber = row;
            fin.getline(row, 120, '\n');
            persons[i].HomeEmail = row;
            i++;
        }
        fin.close();
        howMany = i-1;    //indexointi?!?
        //howMany  = i;
    }
}
//---------------------------------------------------------------------------
//Tiedoston sis‰llˆn tuhoaminen
void PersondetailOperations::DeleteFile(char *fileName)
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
            fout << persons[i].PersonNumber.c_str() << endl;
            fout << persons[i].LastName.c_str() << endl;
            fout << persons[i].FirstName.c_str() << endl;
            fout << persons[i].SocialCode.c_str() << endl;
            fout << persons[i].AddTime.c_str() << endl;
            fout << persons[i].Add2Time.c_str() << endl;
            fout << persons[i].EndTime.c_str() << endl;
            fout << persons[i].Address.c_str() << endl;
            fout << persons[i].PostalCode.c_str() << endl;
            fout << persons[i].City.c_str() << endl;
            fout << persons[i].Land.c_str() << endl;
            fout << persons[i].HomeNumber.c_str() << endl;
            fout << persons[i].MobileNumber.c_str() << endl;
            fout << persons[i].HomeEmail.c_str() << endl;
        }
        fout.close();
    }
}
//------------------------------------------------------------------------------
//Funktiota k‰ytet‰‰n p‰ivitt‰m‰‰n henkilˆtietoja
void PersondetailOperations::UpdateEntry(AnsiString &pNumber,AnsiString &lName, AnsiString &fName,
    AnsiString &socCode,    AnsiString &date,  AnsiString &date2,
    AnsiString &date3,      AnsiString &address,
    AnsiString &postalCode, AnsiString &city,  AnsiString &land,
    AnsiString &homeNumber, AnsiString &gsm,   AnsiString &email)
{

    persons[apu].PersonNumber  = pNumber;
    persons[apu].LastName      = lName;
    persons[apu].FirstName     = fName;
    persons[apu].SocialCode    = socCode;
    persons[apu].AddTime       = date;
    persons[apu].Add2Time       = date2;
    persons[apu].EndTime       = date3;
    persons[apu].Address       = address;
    persons[apu].PostalCode    = postalCode;
    persons[apu].City          = city;
    persons[apu].Land          = land;
    persons[apu].HomeNumber    = homeNumber;
    persons[apu].MobileNumber  = gsm;
    persons[apu].HomeEmail     = email;
}
//--------------------------------------------------------------------------
//Funktiolla haetaan tietoja verokorttia varten (PersontaxForm)
void PersondetailOperations::GetEntry2(int index,
        AnsiString &pNumber,AnsiString &lName,AnsiString &fName)
{
    if (index >= 0 && index < howMany)
    {
        pNumber    = persons[index].PersonNumber;
        lName      = persons[index].LastName;
        fName      = persons[index].FirstName;
    }
}
//---------------------------------------------------------------------------
//Raporttien tulostusta varten
void PersondetailOperations::GetForReport(AnsiString &pNum, AnsiString &lNa, AnsiString &fNa,
    AnsiString &pNumber,    AnsiString &lName, AnsiString &fName,
    AnsiString &socCode,    AnsiString &date,  AnsiString &date2,
    AnsiString &date3,      AnsiString &address,
    AnsiString &postalCode, AnsiString &city,  AnsiString &land,
    AnsiString &homeNumber, AnsiString &gsm,   AnsiString &email)
    {
    if (0 < howMany)
    {
        //K‰yd‰‰n l‰pi tiedosto ja etsit‰‰n vastaavta tiedot
        for(int i=0; i<howMany; i++)
        {
            if((pNum == persons[i].PersonNumber)&&
                (lNa ==persons[i].LastName)&&
                (fNa == persons[i].FirstName))
                {
                pNumber    = persons[i].PersonNumber;
                lName      = persons[i].LastName;
                fName      = persons[i].FirstName;
                socCode    = persons[i].SocialCode;
                date       = persons[i].AddTime;
                date2      = persons[i].Add2Time;
                date3      = persons[i].EndTime;
                address    = persons[i].Address;
                postalCode = persons[i].PostalCode;
                city       = persons[i].City;
                land       = persons[i].Land;
                homeNumber = persons[i].HomeNumber;
                gsm        = persons[i].MobileNumber;
                email      = persons[i].HomeEmail;
                }
        }
    }
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
