//---------------------------------------------------------------------------
#include <vcl.h>
#include <iostream.h>
#include <fstream.h>
#pragma hdrstop

#include "Person.h"
#include "LoginOperations.h"
#include "UserrightsForm.h"
//Luodaan dynaaminen olio, joka on olemassa koko ohjelman toiminnan ajan
LoginOperations *logins = new LoginOperations;
//---------------------------------------------------------------------------
//Konstruktori
LoginOperations::LoginOperations()
{
    howMany = 0;  //Olio laskuri (kuinka monta k‰ytt‰j‰‰ (tiedostoa)
    counter=0;
    apu=0;
}
//---------------------------------------------------------------------------
//Destruktori
LoginOperations::~LoginOperations()
{
}
//---------------------------------------------------------------------------
//Palauttaa olioiden (k‰ytt‰jien) m‰‰r‰n
int LoginOperations::GetSize()
{
    return howMany;
}
//---------------------------------------------------------------------------
int LoginOperations::GetCounter()
{
    return counter;
}
void LoginOperations::SetCounter()
{
    counter = 0;
}
//---------------------------------------------------------------------------
int LoginOperations::GetApu()
{
    return apu;
}
//--------------------------------------------------------------------------
void LoginOperations::AddEntry(AnsiString &lName, AnsiString &fName,
AnsiString &userName, AnsiString &passWord, AnsiString &userRights)
{
    if (howMany < MAXLOGINUSERS)
    {
        persons[howMany].LName = lName;
        persons[howMany].FName = fName;
        persons[howMany].UserName = userName;
        persons[howMany].PassWord = passWord;
        persons[howMany].UserRights = userRights;
        howMany++;
    }
}
//---------------------------------------------------------------------------
void LoginOperations::GetEntry(int index, AnsiString &lName, AnsiString &fName,
AnsiString &userName, AnsiString &passWord, AnsiString &userRights)
{
    if (index >= 0 && index < howMany)
    {
        lName = persons[index].LName;
        fName = persons[index].FName;
        userName = persons[index].UserName;
        passWord = persons[index].PassWord;
        userRights = persons[index].UserRights;
    }
}
//---------------------------------------------------------------------------
void LoginOperations::DeleteEntry(int index)
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
void LoginOperations::DeleteAllEntries(void)
{
    for (int i=0; i<howMany;i++)
    {
        persons[i].LName = "";
        persons[i].FName = "";
        persons[i].UserName = "";
        persons[i].PassWord = "";
        persons[i].UserRights = "";
    }
    howMany = 0;
    counter = 0;
}
//---------------------------------------------------------------------------
void LoginOperations::SaveToFile(char *fileName)
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
            fout << persons[i].LName.c_str() << endl;
            fout << persons[i].FName.c_str() << endl;
            fout << persons[i].UserName.c_str() << endl;
            fout << persons[i].PassWord.c_str() << endl;
            fout << persons[i].UserRights.c_str() << endl;
        }
        fout.close();
        Application->MessageBox("Tiedot talletettu.", "Sanoma", MB_OK);
    }
}
//---------------------------------------------------------------------------
void LoginOperations::DeleteFile(char *fileName)
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
            fout << persons[i].LName.c_str() << endl;
            fout << persons[i].FName.c_str() << endl;
            fout << persons[i].UserName.c_str() << endl;
            fout << persons[i].PassWord.c_str() << endl;
            fout << persons[i].UserRights.c_str() << endl;
        }
        fout.close();
    }
}
//------------------------------------------------------------------------------
void LoginOperations::LoadFromFile(char *fileName)
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
        while (!fin.eof() && (i<MAXLOGINUSERS))
        {
            fin.getline(row, 120, '\n');
            persons[i].LName = row;
            fin.getline(row, 120, '\n');
            persons[i].FName = row;
            fin.getline(row, 120, '\n');
            persons[i].UserName = row;
            fin.getline(row, 120, '\n');
            persons[i].PassWord = row;
            fin.getline(row, 120, '\n');
            persons[i].UserRights = row;
            i++;
        }
        fin.close();
        howMany = i-1;
    }
}
//---------------------------------------------------------------------------
void LoginOperations::IncInput()
{
    if(counter==(howMany-1)){
        ShowMessage("Listan loppu");
    }
    else{
        //Increase counter
        counter++;
    }
}
//---------------------------------------------------------------------------
void LoginOperations::DecInput()
{
    if(counter==0){
        ShowMessage("Listan alku");
    }
    else{
        //Decrease counter
        counter--;
    }
}
//---------------------------------------------------------------------------
void LoginOperations::UpdateEntry(AnsiString &lName, AnsiString &fName,
AnsiString &userName, AnsiString &passWord, AnsiString &userRights)
{
    persons[apu].FName = lName;
    persons[apu].LName = fName;
    persons[apu].UserName = userName;
    persons[apu].PassWord = passWord;
    persons[apu].UserRights = userRights;
}
//---------------------------------------------------------------------------
//Funktiolla etsit‰‰n k‰ytt‰j‰tunnus ja salasana (ja testataan onko oikein)
//Lis‰ksi funktiolla haetaan 1. kerran tiedot muistiin jatkok‰sittely‰ varte
int LoginOperations::OpenFileAndFindUsers(AnsiString &userName, AnsiString &passWord)
{
    AnsiString uName = userName;
    AnsiString pWD  = passWord;

    logins->LoadFromFile("c:\\Laskutusohjelma\\usrs.txt");
    if(logins->GetSize()!=0){
        for(int cc = 0; cc<howMany; cc++){
            if((persons[cc].UserName == userName) && (persons[cc].PassWord == passWord)){
                return 1;
            }
        }
    }
    return 0;
}
//---------------------------------------------------------------------------
int LoginOperations::GetUsers(AnsiString &lName, int &userindex)
{
    int numberofrecord=0;
    for(int i=0; i<howMany;i++)
    {
        if(lName==persons[i].LName && userindex==i){
            /*if(lName==persons[i+1].LName){
                AnsiString apu =user;
                ShowMessage(apu.AnsiPos(persons[i].FName));

                //ShowMessage(apu.c_str());
                return numberofrecord;
            } */
            return numberofrecord;
        }
        numberofrecord++;
    }
    return numberofrecord;
}
#pragma package(smart_init)
