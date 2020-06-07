//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "FormFollowerUnit.h"

Observer *observer = new Observer;

Observer::Observer()
{
    Forms[0]=0; //Yrityksen tiedot (CorporationForm)
    Forms[1]=0; //Salasanat     (UserrightsForm)
    Forms[2]=0; //Verotustietojen m��ritys (TaxesForm)
    Forms[3]=0; //Henkil�tiedot (PersondetailForm)
    Forms[4]=0; //Verotustiedot (PersontaxForm)
    Forms[5]=0; //Palkan laskeminen (CountSalaryForm)
}
//T�st� eteenp�in on olioiden toimintojen m��ritykset....
//Ideana on, ett� asetetaan alkutila, jota voidaan muuttaa
//kutsumalla j�senfunktiota (LOOGISET TILAT OVAT "1" tai "0"
//Paluuarvona palautetaan jokin (#define..) integer arvo.
//--------------------------------------------------------------------------
void Observer::SetState(int &formID)
{
    if(Forms[formID]==NOTUSE){
        Forms[formID]=USE;
    }
    else{
        Forms[formID] = NOTUSE;
    }
}

int Observer::GetState(int &formID)
{
    return Forms[formID];
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
