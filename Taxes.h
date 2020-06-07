//---------------------------------------------------------------------------
#ifndef TaxesH
#define TaxesH
//-----------------------------------------------------------------------
//Henkilöiden salasanat ja oikeudet käyttää ohjelmaa
//Luokan operaatiot on määriteltynä "LoginOperations.cpp ja h"
class Taxes
{
public:
    AnsiString TEL;                  //TEL-maksu
    AnsiString VAKU;
};

class Salary
{
public:
    AnsiString aa;
    AnsiString bb;
    AnsiString cc;
    AnsiString dd;
    AnsiString ee;
    AnsiString ff;
    AnsiString gg;
    AnsiString hh;
    AnsiString ii;
    AnsiString jj;
    AnsiString kk;
    AnsiString ll;
    AnsiString mm;
    AnsiString nn;

    AnsiString oo;
    AnsiString pp;
    AnsiString qq;
    AnsiString xx;
    AnsiString yy;
};

class SalaryPrevious
{
public:
    //Henkilön tunnistusta varten...
    AnsiString PersonNumber;    //Henkilön numero (tunnistus nro.)
    AnsiString LastName;        //Sukunimi
    AnsiString FirstName;       //Etunimi (et)
    
    AnsiString PayslipStart;    //Palkkakausi (alku)
    AnsiString PayslipEnd;      //Palkkakausi (loppu)

    AnsiString PeriodtimeLimit;  //Tuloraja/ka
    AnsiString PaycumulTax;      //Ansio verok.al
    AnsiString TaxDays;          //veropvt. verok. al
    AnsiString PayrolltaxCum;    //Enn.pid. Verok. al.

    AnsiString SalaryMonth;     //Palkka/kk yhteensä
    AnsiString TaxableIncome;   //Veronal. ansio
    AnsiString Lisat;           // Lisat
    AnsiString Vahennykset;     //Vähennykset

};
//---------------------------------------------------------------------------
#endif
