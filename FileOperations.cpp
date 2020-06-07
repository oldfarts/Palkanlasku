//---------------------------------------------------------------------------
#include <vcl.h>
#include <iostream.h>
#include <fstream.h>
#pragma hdrstop

//#include "InputF.h"
#include "FileOperations.h"
//FileOperations *FileOperations = new FileOperations;
FileOperations::FileOperations()
{
    howMany = 0;
    counter=0;
    apu=0;
}
int FileOperations::GetSize()
{
    return howMany;
}
int FileOperations::GetCounter()
{
    return counter;
}
int FileOperations::GetApu()
{
    return apu;
}
//--------------------------------------------------------------------------
void FileOperations::AddEntry(AnsiString &firstName, AnsiString &lastName,
     AnsiString &address, AnsiString &postalCode, AnsiString &city,
     AnsiString &land, AnsiString &homeNumber, AnsiString &mobileNumber,
     AnsiString &homeEmail)
{
    if (howMany < MAXPERSONS)
    {
        persons[howMany].FirstName = firstName;
        persons[howMany].LastName = lastName;
        persons[howMany].Address = address;
        persons[howMany].PostalCode = postalCode;
        persons[howMany].City = city;
        persons[howMany].Land = land;
        persons[howMany].HomeNumber = homeNumber;
        persons[howMany].MobileNumber = mobileNumber;
        persons[howMany].HomeEmail = homeEmail;
        howMany++;
    }
}
void FileOperations::GetEntry(int index, AnsiString &firstName, AnsiString &lastName,
     AnsiString &address, AnsiString &postalCode, AnsiString &city, AnsiString &land,
     AnsiString &homeNumber, AnsiString &mobileNumber, AnsiString &homeEmail)
{
    if (index >= 0 && index < howMany)
    {
        firstName = persons[index].FirstName;
        lastName = persons[index].FirstName;
        address = persons[index].Address;
        postalCode = persons[index].PostalCode;
        city = persons[index].City;
        land = persons[index].Land;
        homeNumber = persons[index].HomeNumber;
        mobileNumber = persons[index].MobileNumber;
        homeEmail = persons[index].HomeEmail;
    }
}
void FileOperations::DeleteEntry(int index)
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
void FileOperations::SaveToFile(char *fileName)
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
            fout << persons[i].FirstName.c_str() << endl;
            fout << persons[i].LastName.c_str() << endl;
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
void FileOperations::LoadFromFile(char *fileName)
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
            persons[i].FirstName = row;
            fin.getline(row, 120, '\n');
            persons[i].LastName = row;
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
        howMany = i-1;
    }
}
void FileOperations::IncInput()
{
   /* AnsiString Na;
    AnsiString Addres;
    AnsiString HomeNumbe;
    AnsiString MobileNumbe;

    if(counter==howMany)
    {
        ShowMessage("Loppu");
    }
    else
    {
        int joo = FileOperations->GetSize();
        for (int i=0; i< joo; i++)
         {
            if(counter==i)
            {
            apu=i;
            phoneBook->GetEntry(i, Na, Addres, HomeNumbe, MobileNumbe);
            InputForm->Name->Text=Na;
            InputForm->Address->Text=Addres;
            InputForm->HomeNumber->Text=HomeNumbe;
            InputForm->MobileNumber->Text=MobileNumbe;
            }
        }
        //Increase counter
        counter++;
    }*/
}

void FileOperations::DecInput()
{
    /*AnsiString Na;
    AnsiString Addres;
    AnsiString HomeNumbe;
    AnsiString MobileNumbe;

    if(counter==0)
    {
        ShowMessage("Alku");
    }
    else
    {
        //Decrease counter
        counter--;
        int joo = phoneBook->GetSize();
        for (int i=0; i< joo; i++)
         {
            if(counter==i)
            {
            apu=i;
            phoneBook->GetEntry(i, Na, Addres, HomeNumbe, MobileNumbe);
            InputForm->Name->Text=Na;
            InputForm->Address->Text=Addres;
            InputForm->HomeNumber->Text=HomeNumbe;
            InputForm->MobileNumber->Text=MobileNumbe;
            }
        }
      }*/
}

void FileOperations::UpdateEntry(AnsiString &firstName, AnsiString &lastName,
     AnsiString &address, AnsiString &postalCode, AnsiString &city, AnsiString &land,
     AnsiString &homeNumber, AnsiString &mobileNumber, AnsiString &homeEmail)
{
    /*AnsiString FirstName;
    AnsiString LastName;
    AnsiString Address;
    AnsiString PostalCode;
    AnsiString City;
    AnsiString Land;
    AnsiString HomeNumber;
    AnsiString MobileNumber;
    AnsiString HomeEmail;*/

    persons[apu].FirstName = firstName;
    persons[apu].LastName = lastName;
    persons[apu].Address = address;
    persons[apu].PostalCode = postalCode;
    persons[apu].City = city;
    persons[apu].Land = land;
    persons[apu].HomeNumber = homeNumber;
    persons[apu].MobileNumber = mobileNumber;
    persons[apu].HomeEmail = homeEmail;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
