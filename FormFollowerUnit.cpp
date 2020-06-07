//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "FormFollowerUnit.h"

Observer *observer = new Observer;

Observer::Observer()
{
    Forms[0]=0; //Yrityksen tiedot (CorporationForm)
    Forms[1]=0; //Salasanat     (UserrightsForm)
    Forms[2]=0; //Verotustietojen määritys (TaxesForm)
    Forms[3]=0; //Henkilötiedot (PersondetailForm)
    Forms[4]=0; //Verotustiedot (PersontaxForm)
    Forms[5]=0; //Palkan laskeminen (CountSalaryForm)
}
//Tästä eteenpäin on olioiden toimintojen määritykset....
//Ideana on, että asetetaan alkutila, jota voidaan muuttaa
//kutsumalla jäsenfunktiota (LOOGISET TILAT OVAT "1" tai "0"
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
