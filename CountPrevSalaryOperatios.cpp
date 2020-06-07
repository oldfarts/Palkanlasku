//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <fstream.h>

#include "CountPrevSalaryOperatios.h"

SalaryPreviousOperations *salaryprevOperations = new SalaryPreviousOperations;
SalaryPreviousOperations::SalaryPreviousOperations()
{
    howMany = 0;
    counter=0;
    apu=0;
}
//--------------------------------------------------------------------------
int SalaryPreviousOperations::GetSize()
{
    return howMany;
}
//--------------------------------------------------------------------------
int SalaryPreviousOperations::GetCounter()
{
    return counter;
}
void SalaryPreviousOperations::SetCounter()
{
    counter = 0;
}
//--------------------------------------------------------------------------
int SalaryPreviousOperations::GetApu()
{
    return apu;
}
//--------------------------------------------------------------------------
//Funktiota k‰ytet‰‰n lis‰‰m‰‰n tietoja
void SalaryPreviousOperations::AddEntry(
    AnsiString &pNumber,         AnsiString &lName, AnsiString &fName,
    AnsiString &payslipStart,    AnsiString &payslipEnd,
    AnsiString &periodtimeLimit, AnsiString &paycumulTax,
    AnsiString &taxDays,         AnsiString &payrolltaxCum,
    AnsiString &salaryMonth,     AnsiString &taxableIncome,
    AnsiString &lisat,           AnsiString &vahennykset)
    {
    if (howMany < MAXPERSONS)
    {
        salaryPrevious[howMany].PersonNumber    = pNumber;
        salaryPrevious[howMany].LastName        = lName;
        salaryPrevious[howMany].FirstName       = fName;
        salaryPrevious[howMany].PayslipStart    = payslipStart;
        salaryPrevious[howMany].PayslipEnd      = payslipEnd;
        salaryPrevious[howMany].PeriodtimeLimit = periodtimeLimit;
        salaryPrevious[howMany].PaycumulTax     = paycumulTax;
        salaryPrevious[howMany].TaxDays         = taxDays;
        salaryPrevious[howMany].PayrolltaxCum   = payrolltaxCum;
        salaryPrevious[howMany].SalaryMonth     = salaryMonth;
        salaryPrevious[howMany].TaxableIncome   = taxableIncome;
        salaryPrevious[howMany].Lisat           = lisat;
        salaryPrevious[howMany].Vahennykset     = vahennykset;
        howMany++;
    }
}
//--------------------------------------------------------------------------
//Funktiota k‰ytet‰‰n hakemaan tietoja
void SalaryPreviousOperations::GetEntry(int index,
    AnsiString &pNumber,         AnsiString &lName, AnsiString &fName,
    AnsiString &payslipStart,    AnsiString &payslipEnd,
    AnsiString &periodtimeLimit, AnsiString &paycumulTax,
    AnsiString &taxDays,         AnsiString &payrolltaxCum,
    AnsiString &salaryMonth,     AnsiString &taxableIncome,
    AnsiString &lisat,           AnsiString &vahennykset)
    {
    if (index >= 0 && index < howMany)
    {
        pNumber         = salaryPrevious[index].PersonNumber;
        lName           = salaryPrevious[index].LastName;
        fName           = salaryPrevious[index].FirstName;
        payslipStart    = salaryPrevious[index].PayslipStart;
        payslipEnd      = salaryPrevious[index].PayslipEnd;
        periodtimeLimit = salaryPrevious[index].PeriodtimeLimit;
        paycumulTax     = salaryPrevious[index].PaycumulTax;
        taxDays         = salaryPrevious[index].TaxDays;
        payrolltaxCum   = salaryPrevious[index].PayrolltaxCum;
        salaryMonth     = salaryPrevious[index].SalaryMonth;
        taxableIncome   = salaryPrevious[index].TaxableIncome;
        lisat           = salaryPrevious[index].Lisat;
        vahennykset     = salaryPrevious[index].Vahennykset;
    }
}
//--------------------------------------------------------------------------
//Funktiolla haetaan tietoja verokorttia varten (PersontaxForm)
void SalaryPreviousOperations::GetEntry2(int index,
        AnsiString &pNumber,AnsiString &lName,AnsiString &fName)
{
    if (index >= 0 && index < howMany)
    {
        pNumber    = salaryPrevious[index].PersonNumber;
        lName      = salaryPrevious[index].LastName;
        fName      = salaryPrevious[index].FirstName;
    }
}
//--------------------------------------------------------------------------
//Funktiota k‰ytet‰‰n hakemaan tietoja
void SalaryPreviousOperations::DeleteEntry(int index)
{
    if (index >= 0)
    {
        for (int i=index; i<howMany-1;i++)
            salaryPrevious[i] = salaryPrevious[i+1];
        howMany--;

        apu=0;     //Set own strings for NULL
        counter=0;
    }
}
//---------------------------------------------------------------------------
//Funktiota k‰ytet‰‰n nollaamaan kaikki olion tiedot..
void SalaryPreviousOperations::DeleteAllEntries(void)
{
    for (int i=0; i<howMany;i++)
    {
        salaryPrevious[i].PersonNumber    = "";
        salaryPrevious[i].LastName        = "";
        salaryPrevious[i].FirstName       = "";
        salaryPrevious[i].PayslipStart    = "";
        salaryPrevious[i].PayslipEnd      = "";
        salaryPrevious[i].PeriodtimeLimit = "";
        salaryPrevious[i].PaycumulTax     = "";
        salaryPrevious[i].TaxDays         = "";
        salaryPrevious[i].PayrolltaxCum   = "";
        salaryPrevious[i].SalaryMonth     = "";
        salaryPrevious[i].TaxableIncome   = "";
        salaryPrevious[i].Lisat           = "";
        salaryPrevious[i].Vahennykset     = "";
    }
    howMany = 0;
    counter = 0;
}
//---------------------------------------------------------------------------
//Tietojen tallennus tiedostoon
void SalaryPreviousOperations::SaveToFile(char *fileName)
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
            fout << salaryPrevious[i].PersonNumber.c_str() << endl;
            fout << salaryPrevious[i].LastName.c_str() << endl;
            fout << salaryPrevious[i].FirstName.c_str() << endl;
            fout << salaryPrevious[i].PayslipStart.c_str() << endl;
            fout << salaryPrevious[i].PayslipEnd.c_str() << endl;
            fout << salaryPrevious[i].PeriodtimeLimit.c_str() << endl;
            fout << salaryPrevious[i].PaycumulTax.c_str() << endl;
            fout << salaryPrevious[i].TaxDays.c_str() << endl;
            fout << salaryPrevious[i].PayrolltaxCum.c_str() << endl;
            fout << salaryPrevious[i].SalaryMonth.c_str() << endl;
            fout << salaryPrevious[i].TaxableIncome.c_str() << endl;
            fout << salaryPrevious[i].Lisat.c_str() << endl;
            fout << salaryPrevious[i].Vahennykset.c_str() << endl;
        }
        fout.close();
        //Application->MessageBox("Tiedot talletettu.", "Sanoma", MB_OK);
    }
}
//------------------------------------------------------------------------------
//Funktiota k‰ytet‰‰n tallettamaan henkilˆtietoja
void SalaryPreviousOperations::LoadFromFile(char *fileName)
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
            salaryPrevious[i].PersonNumber = row;
            fin.getline(row, 120, '\n');
            salaryPrevious[i].LastName = row;
            fin.getline(row, 120, '\n');
            salaryPrevious[i].FirstName = row;
            fin.getline(row, 120, '\n');
            salaryPrevious[i].PayslipStart =row;
            fin.getline(row, 120, '\n');
            salaryPrevious[i].PayslipEnd =row;
            fin.getline(row, 120, '\n');
            salaryPrevious[i].PeriodtimeLimit =row;
            fin.getline(row, 120, '\n');
            salaryPrevious[i].PaycumulTax =row;
            fin.getline(row, 120, '\n');
            salaryPrevious[i].TaxDays =row;
            fin.getline(row, 120, '\n');
            salaryPrevious[i].PayrolltaxCum = row;
            fin.getline(row, 120, '\n');
            salaryPrevious[i].SalaryMonth = row;
            fin.getline(row, 120, '\n');
            salaryPrevious[i].TaxableIncome = row;
            fin.getline(row, 120, '\n');
            salaryPrevious[i].Lisat = row;
            fin.getline(row, 120, '\n');
            salaryPrevious[i].Vahennykset = row;
            i++;
        }
        fin.close();
        howMany = i-1;    //indexointi?!?
        //howMany  = i;
    }
}
//---------------------------------------------------------------------------
//Tiedoston sis‰llˆn tuhoaminen
void SalaryPreviousOperations::DeleteFile(char *fileName)
{
    ofstream fout;
    fout.open(fileName); // avataan tiedosto
    if (!fout)
    {
        //Application->MessageBox("Tiedoston avaus ei onnistu.", "Virheilmoitus", MB_OK);
    }
    else
    {
        for (int i=0;i<howMany;i++) // kirjoitetaan tiedot
        {
            fout << salaryPrevious[i].PersonNumber.c_str() << endl;
            fout << salaryPrevious[i].LastName.c_str() << endl;
            fout << salaryPrevious[i].FirstName.c_str() << endl;
            fout << salaryPrevious[i].PayslipStart.c_str() << endl;
            fout << salaryPrevious[i].PayslipEnd.c_str() << endl;
            fout << salaryPrevious[i].PeriodtimeLimit.c_str() << endl;
            fout << salaryPrevious[i].PaycumulTax.c_str() << endl;
            fout << salaryPrevious[i].TaxDays.c_str() << endl;
            fout << salaryPrevious[i].PayrolltaxCum.c_str() << endl;
            fout << salaryPrevious[i].SalaryMonth.c_str() << endl;
            fout << salaryPrevious[i].TaxableIncome.c_str() << endl;
            fout << salaryPrevious[i].Lisat.c_str() << endl;
            fout << salaryPrevious[i].Vahennykset.c_str() << endl;
        }
        fout.close();
    }
}
//---------------------------------------------------------------------------
void SalaryPreviousOperations::GetForReport(
    AnsiString &pNum, AnsiString &lNa, AnsiString &fNa,
    AnsiString &pNumber,         AnsiString &lName, AnsiString &fName,
    AnsiString &payslipStart,    AnsiString &payslipEnd,
    AnsiString &periodtimeLimit, AnsiString &paycumulTax,
    AnsiString &taxDays,         AnsiString &payrolltaxCum,
    AnsiString &salaryMonth,     AnsiString &taxableIncome,
    AnsiString &lisat,           AnsiString &vahennykset)
    {
    if (0 < howMany)
    {
        //K‰yd‰‰n l‰pi tiedosto ja etsit‰‰n vastaavta tiedot
        for(int i=0; i<howMany; i++)
        {
            if((pNum == salaryPrevious[i].PersonNumber )&&
                (lNa == salaryPrevious[i].LastName )&&
                (fNa == salaryPrevious[i].FirstName ))
                {
                pNumber          = salaryPrevious[i].PersonNumber;
                lName            = salaryPrevious[i].LastName;
                fName            = salaryPrevious[i].FirstName;
                payslipStart     = salaryPrevious[i].PayslipStart;
                payslipEnd       = salaryPrevious[i].PayslipEnd;
                periodtimeLimit  = salaryPrevious[i].PeriodtimeLimit;
                paycumulTax      = salaryPrevious[i].PaycumulTax;
                taxDays          = salaryPrevious[i].TaxDays;
                payrolltaxCum    = salaryPrevious[i].PayrolltaxCum;
                salaryMonth      = salaryPrevious[i].SalaryMonth;
                taxableIncome    = salaryPrevious[i].TaxableIncome;
                lisat            = salaryPrevious[i].Lisat;
                vahennykset      = salaryPrevious[i].Vahennykset;
                }
        }
    }

}
//---------------------------------------------------------------------------
bool SalaryPreviousOperations::CheckSalary(AnsiString &pNum, AnsiString &lNa, AnsiString &fNa)
{
    //K‰yd‰‰n l‰pi tiedosto ja etsit‰‰n vastaavta tiedot
    for(int i=0; i<howMany; i++)
    {
    if((pNum == salaryPrevious[i].PersonNumber )&&
       (lNa == salaryPrevious[i].LastName )&&
       (fNa == salaryPrevious[i].FirstName ))
       {
        return true;
       }
    }
    return false;
}
//---------------------------------------------------------------------------
void SalaryPreviousOperations::UpdateEntry(AnsiString &pNum, AnsiString &lNa, AnsiString &fNa,
    AnsiString &payslipStart,    AnsiString &payslipEnd,
    AnsiString &periodtimeLimit, AnsiString &paycumulTax,
    AnsiString &taxDays,         AnsiString &payrolltaxCum,
    AnsiString &salaryMonth,     AnsiString &taxableIncome,
    AnsiString &lisat,           AnsiString &vahennykset)
{
        //K‰yd‰‰n l‰pi tiedosto ja etsit‰‰n vastaavta tiedot
        for(int i=0; i<howMany; i++)
        {
            if((pNum == salaryPrevious[i].PersonNumber )&&
                (lNa == salaryPrevious[i].LastName )&&
                (fNa == salaryPrevious[i].FirstName ))
                {
                salaryPrevious[i].PersonNumber   = pNum;
                salaryPrevious[i].LastName       = lNa;
                salaryPrevious[i].FirstName      = fNa;
                salaryPrevious[i].PayslipStart   = payslipStart;
                salaryPrevious[i].PayslipEnd     = payslipEnd;
                salaryPrevious[i].PeriodtimeLimit=periodtimeLimit;
                salaryPrevious[i].PaycumulTax    = paycumulTax;
                salaryPrevious[i].TaxDays        = taxDays;
                salaryPrevious[i].PayrolltaxCum  = payrolltaxCum;
                salaryPrevious[i].SalaryMonth    = salaryMonth;
                salaryPrevious[i].TaxableIncome  = taxableIncome;
                salaryPrevious[i].Lisat          = lisat;
                salaryPrevious[i].Vahennykset    = vahennykset;
                }

        }

}
//---------------------------------------------------------------------------
#pragma package(smart_init)
