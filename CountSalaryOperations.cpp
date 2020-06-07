//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <fstream.h>

#include "CountSalaryOperations.h"
SalaryOperations *salaryOperations = new SalaryOperations;
SalaryOperations::SalaryOperations()
{
    howMany = 0;
    counter=0;
    apu=0;
}
//--------------------------------------------------------------------------
int SalaryOperations::GetSize()
{
    return howMany;
}
//--------------------------------------------------------------------------
int SalaryOperations::GetCounter()
{
    return counter;
}
void SalaryOperations::SetCounter()
{
    counter = 0;
}
//--------------------------------------------------------------------------
int SalaryOperations::GetApu()
{
    return apu;
}
//--------------------------------------------------------------------------
//Funktiota k‰ytet‰‰n lis‰‰m‰‰n tietoja
void SalaryOperations::AddEntry(AnsiString &pNumber,AnsiString &lName, AnsiString &fName,
    AnsiString &socCode,    AnsiString &date, AnsiString &date2,
    AnsiString &date3,      AnsiString &address,
    AnsiString &postalCode, AnsiString &city,  AnsiString &land,
    AnsiString &homeNumber, AnsiString &gsm,   AnsiString &email,
     AnsiString &jee, AnsiString &kee, AnsiString &lee, AnsiString &mee,
    AnsiString &nee)
    {
    if (howMany < MAXPERSONS)
    {
        salary[howMany].aa = pNumber;
        salary[howMany].bb = lName;
        salary[howMany].cc = fName;
        salary[howMany].dd = socCode;
        salary[howMany].ee = date;
        salary[howMany].ff = date2;
        salary[howMany].gg = date3;
        salary[howMany].hh = address;
        salary[howMany].ii = postalCode;
        salary[howMany].jj = city;
        salary[howMany].kk = land;
        salary[howMany].ll = homeNumber;
        salary[howMany].mm = gsm;
        salary[howMany].nn = email;

        salary[howMany].oo = email;
        salary[howMany].pp = email;
        salary[howMany].qq = email;
        salary[howMany].xx = email;
        salary[howMany].yy = email;
        howMany++;
    }
}
//--------------------------------------------------------------------------
//Funktiota k‰ytet‰‰n hakemaan tietoja
void SalaryOperations::GetEntry(int index, AnsiString &pNumber,AnsiString &lName, AnsiString &fName,
    AnsiString &socCode,    AnsiString &date,  AnsiString &date2,
    AnsiString &date3,      AnsiString &address,
    AnsiString &postalCode, AnsiString &city,  AnsiString &land,
    AnsiString &homeNumber, AnsiString &gsm,   AnsiString &email,
    AnsiString &jee, AnsiString &kee, AnsiString &lee, AnsiString &mee,
    AnsiString &nee)
    {
    if (index >= 0 && index < howMany)
    {
        pNumber    = salary[index].aa;
        lName      = salary[index].bb;
        fName      = salary[index].cc;
        socCode    = salary[index].dd;
        date       = salary[index].ee;
        date2      = salary[index].ff;
        date3      = salary[index].gg;
        address    = salary[index].hh;
        postalCode = salary[index].ii;
        city       = salary[index].jj;
        land       = salary[index].kk;
        homeNumber = salary[index].ll;
        gsm        = salary[index].mm;
        email      = salary[index].nn;

        jee      = salary[index].oo;
        kee      = salary[index].pp;
        lee      = salary[index].qq;
        mee      = salary[index].xx;
        nee      = salary[index].yy;

    }
}
//--------------------------------------------------------------------------
//Funktiolla haetaan tietoja verokorttia varten (PersontaxForm)
void SalaryOperations::GetEntry2(int index,
        AnsiString &pNumber,AnsiString &lName,AnsiString &fName)
{
    if (index >= 0 && index < howMany)
    {
        pNumber    = salary[index].aa;
        lName      = salary[index].bb;
        fName      = salary[index].cc;
    }
}
//--------------------------------------------------------------------------
//Funktiota k‰ytet‰‰n hakemaan tietoja
void SalaryOperations::DeleteEntry(int index)
{
    if (index >= 0)
    {
        for (int i=index; i<howMany-1;i++)
            salary[i] = salary[i+1];
        howMany--;

        apu=0;     //Set own strings for NULL
        counter=0;
    }
}
//---------------------------------------------------------------------------
//Funktiota k‰ytet‰‰n nollaamaan kaikki olion tiedot..
void SalaryOperations::DeleteAllEntries(void)
{
    for (int i=0; i<howMany;i++)
    {
        salary[i].aa = "";
        salary[i].bb = "";
        salary[i].cc = "";
        salary[i].dd = "";
        salary[i].ee = "";
        salary[i].ff = "";
        salary[i].gg = "";
        salary[i].hh = "";
        salary[i].ii = "";
        salary[i].jj = "";
        salary[i].kk = "";
        salary[i].ll = "";
        salary[i].ll = "";
        salary[i].mm = "";
    }
    howMany = 0;
    counter = 0;
}
//---------------------------------------------------------------------------
//Tietojen tallennus tiedostoon
void SalaryOperations::SaveToFile(char *fileName)
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
            fout << salary[i].aa.c_str() << endl;
            fout << salary[i].bb.c_str() << endl;
            fout << salary[i].cc.c_str() << endl;
            fout << salary[i].dd.c_str() << endl;
            fout << salary[i].ee.c_str() << endl;
            fout << salary[i].ff.c_str() << endl;
            fout << salary[i].gg.c_str() << endl;
            fout << salary[i].hh.c_str() << endl;
            fout << salary[i].ii.c_str() << endl;
            fout << salary[i].jj.c_str() << endl;
            fout << salary[i].kk.c_str() << endl;
            fout << salary[i].ll.c_str() << endl;
            fout << salary[i].mm.c_str() << endl;
            fout << salary[i].nn.c_str() << endl;

            /*fout << salary[i].oo.c_str() << endl;
            fout << salary[i].pp.c_str() << endl;
            fout << salary[i].qq.c_str() << endl;
            fout << salary[i].xx.c_str() << endl;
            fout << salary[i].yy.c_str() << endl;*/
        }
        fout.close();
        Application->MessageBox("Tiedot talletettu.", "Sanoma", MB_OK);
    }
}
//------------------------------------------------------------------------------
//Funktiota k‰ytet‰‰n tallettamaan henkilˆtietoja
void SalaryOperations::LoadFromFile(char *fileName)
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
            salary[i].aa = row;
            fin.getline(row, 120, '\n');
            salary[i].bb = row;
            fin.getline(row, 120, '\n');
            salary[i].cc = row;
            fin.getline(row, 120, '\n');
            salary[i].dd =row;
            fin.getline(row, 120, '\n');
            salary[i].ee =row;
            fin.getline(row, 120, '\n');
            salary[i].ff =row;
            fin.getline(row, 120, '\n');
            salary[i].gg =row;
            fin.getline(row, 120, '\n');
            salary[i].hh =row;
            fin.getline(row, 120, '\n');
            salary[i].ii = row;
            fin.getline(row, 120, '\n');
            salary[i].jj = row;
            fin.getline(row, 120, '\n');
            salary[i].kk = row;
            fin.getline(row, 120, '\n');
            salary[i].ll = row;
            fin.getline(row, 120, '\n');
            salary[i].mm = row;
            fin.getline(row, 120, '\n');
            salary[i].nn = row;
            i++;
        }
        fin.close();
        //howMany = i-1;    //indexointi?!?
        howMany  = i;
    }
}
//---------------------------------------------------------------------------
//Tiedoston sis‰llˆn tuhoaminen
void SalaryOperations::DeleteFile(char *fileName)
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
            fout << salary[i].aa.c_str() << endl;
            fout << salary[i].bb.c_str() << endl;
            fout << salary[i].cc.c_str() << endl;
            fout << salary[i].dd.c_str() << endl;
            fout << salary[i].ee.c_str() << endl;
            fout << salary[i].ff.c_str() << endl;
            fout << salary[i].gg.c_str() << endl;
            fout << salary[i].hh.c_str() << endl;
            fout << salary[i].ii.c_str() << endl;
            fout << salary[i].jj.c_str() << endl;
            fout << salary[i].kk.c_str() << endl;
            fout << salary[i].ll.c_str() << endl;
            fout << salary[i].mm.c_str() << endl;
            fout << salary[i].nn.c_str() << endl;
        }
        fout.close();
    }
}
//------------------------------------------------------------------------------
//Funktiota k‰ytet‰‰n p‰ivitt‰m‰‰n henkilˆtietoja
void SalaryOperations::UpdateEntry(AnsiString &pNumber,AnsiString &lName, AnsiString &fName,
    AnsiString &socCode,    AnsiString &date,  AnsiString &date2,
    AnsiString &date3,      AnsiString &address,
    AnsiString &postalCode, AnsiString &city,  AnsiString &land,
    AnsiString &homeNumber, AnsiString &gsm,   AnsiString &email)
{

    salary[apu].aa  = pNumber;
    salary[apu].bb      = lName;
    salary[apu].cc     = fName;
    salary[apu].dd    = socCode;
    salary[apu].ee       = date;
    salary[apu].ff       = date2;
    salary[apu].gg       = date3;
    salary[apu].hh       = address;
    salary[apu].ii    = postalCode;
    salary[apu].jj          = city;
    salary[apu].kk          = land;
    salary[apu].ll    = homeNumber;
    salary[apu].mm  = gsm;
    salary[apu].nn     = email;
}
//---------------------------------------------------------------------------
void SalaryOperations::GetForReport(AnsiString &pNum, AnsiString &lNa, AnsiString &fNa,
    AnsiString &pNumber, AnsiString &lName,  AnsiString &fName, AnsiString &startDate,
    AnsiString &endDate, AnsiString &ustartDate, AnsiString &days, AnsiString &hours,
    AnsiString &salar, AnsiString &ylityo, AnsiString &ytuntihinta,AnsiString &yhteensa,
    AnsiString &lomaraha, AnsiString &lomakorvaus)
    {
    if (0 < howMany)
    {
        //K‰yd‰‰n l‰pi tiedosto ja etsit‰‰n vastaavta tiedot
        for(int i=0; i<howMany; i++)
        {
            if((pNum == salary[i].aa )&&
                (lNa == salary[i].bb )&&
                (fNa == salary[i].cc ))
                {
                pNumber          = salary[i].aa;
                lName            = salary[i].bb;
                fName            = salary[i].cc;
                startDate        = salary[i].dd;
                endDate          = salary[i].ee;
                ustartDate       = salary[i].ff;
                days             = salary[i].gg;
                hours            = salary[i].hh;
                salar            = salary[i].ii;
                ylityo           = salary[i].jj;
                ytuntihinta      = salary[i].kk;
                yhteensa         = salary[i].ll;
                lomaraha         = salary[i].mm;
                lomakorvaus      = salary[i].nn;
                }

        }
    }

}
//---------------------------------------------------------------------------
int SalaryOperations::GetPerson(AnsiString &lName, int &userindex)
{
     int numberofrecord=0;
    for(int i=0; i<howMany;i++)
    {
        if(lName==salary[i].bb && userindex==i)
        {
            return numberofrecord;
        }
        numberofrecord++;
    }
    return numberofrecord;

}
//---------------------------------------------------------------------------
#pragma package(smart_init)
