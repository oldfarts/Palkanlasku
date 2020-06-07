//---------------------------------------------------------------------------
#ifndef PersonH
#define PersonH

//-----------------------------------------------------------------------
//Henkil�iden salasanat ja oikeudet k�ytt�� ohjelmaa
//Luokan operaatiot on m��riteltyn� "LoginOperations.cpp ja h"
class PersonRights
{
public:
    AnsiString LName;                //Sukunimi
    AnsiString FName;                //Etunimi
    AnsiString UserName;             //K�ytt�j�tunnus
    AnsiString PassWord;             //Salasana
    AnsiString UserRights;           //K�ytt�oikeudet
};
//-----------------------------------------------------------------------

//Henkil�tietojen luokka
//Luokan j��senmuuttujia k�ytet��n "FileOperations.cpp ja h"
class Person
{
public:
    AnsiString PersonNumber;    //Henkil�n numero (tunnistus nro.)
    AnsiString LastName;        //Sukunimi
    AnsiString FirstName;       //Etunimi (et)
    AnsiString SocialCode;      //Henkil� tunnus
    AnsiString AddTime;         //aloitus pvm
    AnsiString Add2Time;        //Yksik�n aloitus pvm
    AnsiString EndTime;         //lopetus pvm
    AnsiString Address;         //L�hiosoite
    AnsiString PostalCode;      //Postiosoite
    AnsiString City;            //Kaupunki
    AnsiString Land;            //Maa
    AnsiString HomeNumber;      //Kotinumero
    AnsiString MobileNumber;    //K�nnykk�
    AnsiString HomeEmail;       //Email-osoite
};
//-----------------------------------------------------------------------

//Henkil�n tilitietojen luokka
//Luokan j�senmuuttujia k�ytet��n "FileOperations.cpp ja h"
/*class PersonAccount
{
public:

};*/
//-----------------------------------------------------------------------

//Henkil�n verokortin luokka
//Luokan muuttujia k�ytet��n hyv�ksi "FileOperations.cpp ja h"
class PersonTaxrate /*: Person*/
{
public:
    AnsiString PersonNumber;
    AnsiString LastName;
    AnsiString FirstName;
    AnsiString TiliNumero;            //Henkil�n tilinumero
    AnsiString PerusProsentti;        //Perusveroprosentti  (13,5%)
    AnsiString LisaProsentti;         //Lis�veroprosentti   (33,5%)
    AnsiString VVTuloraja;            //Perustuloraja / vv  (10000e)
    AnsiString KKTuloraja;            //Perustuloraha / kk  (833,33e)
    AnsiString KahdenVKTuloraja;      //Perustuloraja  / 2.vk (384,62e)
    AnsiString VKTuloraja;            //Perustuloraja / 1.vk (192,31e) (kts.ed.)
    AnsiString PVTuloraja;            //Perustuloraja / pv. (27,47e)
};

//-----------------------------------------------------------------------
#endif
