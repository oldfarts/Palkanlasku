//---------------------------------------------------------------------------
#ifndef PersonH
#define PersonH

//-----------------------------------------------------------------------
//Henkilöiden salasanat ja oikeudet käyttää ohjelmaa
//Luokan operaatiot on määriteltynä "LoginOperations.cpp ja h"
class PersonRights
{
public:
    AnsiString LName;                //Sukunimi
    AnsiString FName;                //Etunimi
    AnsiString UserName;             //Käyttäjätunnus
    AnsiString PassWord;             //Salasana
    AnsiString UserRights;           //Käyttöoikeudet
};
//-----------------------------------------------------------------------

//Henkilötietojen luokka
//Luokan jäösenmuuttujia käytetään "FileOperations.cpp ja h"
class Person
{
public:
    AnsiString PersonNumber;    //Henkilön numero (tunnistus nro.)
    AnsiString LastName;        //Sukunimi
    AnsiString FirstName;       //Etunimi (et)
    AnsiString SocialCode;      //Henkilö tunnus
    AnsiString AddTime;         //aloitus pvm
    AnsiString Add2Time;        //Yksikön aloitus pvm
    AnsiString EndTime;         //lopetus pvm
    AnsiString Address;         //Lähiosoite
    AnsiString PostalCode;      //Postiosoite
    AnsiString City;            //Kaupunki
    AnsiString Land;            //Maa
    AnsiString HomeNumber;      //Kotinumero
    AnsiString MobileNumber;    //Kännykkä
    AnsiString HomeEmail;       //Email-osoite
};
//-----------------------------------------------------------------------

//Henkilön tilitietojen luokka
//Luokan jäsenmuuttujia käytetään "FileOperations.cpp ja h"
/*class PersonAccount
{
public:

};*/
//-----------------------------------------------------------------------

//Henkilön verokortin luokka
//Luokan muuttujia käytetään hyväksi "FileOperations.cpp ja h"
class PersonTaxrate /*: Person*/
{
public:
    AnsiString PersonNumber;
    AnsiString LastName;
    AnsiString FirstName;
    AnsiString TiliNumero;            //Henkilön tilinumero
    AnsiString PerusProsentti;        //Perusveroprosentti  (13,5%)
    AnsiString LisaProsentti;         //Lisäveroprosentti   (33,5%)
    AnsiString VVTuloraja;            //Perustuloraja / vv  (10000e)
    AnsiString KKTuloraja;            //Perustuloraha / kk  (833,33e)
    AnsiString KahdenVKTuloraja;      //Perustuloraja  / 2.vk (384,62e)
    AnsiString VKTuloraja;            //Perustuloraja / 1.vk (192,31e) (kts.ed.)
    AnsiString PVTuloraja;            //Perustuloraja / pv. (27,47e)
};

//-----------------------------------------------------------------------
#endif
