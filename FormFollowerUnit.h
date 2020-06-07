//---------------------------------------------------------------------------
#ifndef FormFollowerUnitH
#define FormFollowerUnitH

//Lomakkeiden Tilojen m‰‰rittelyt
#define USE 0
#define NOTUSE 1

//Luokkaa k‰ytet‰‰n valvomaan alilomakkeiden tiloja
class Observer
{
private:
    int Forms[6];  //Lomakkeiden numerot [lomake[0] = lomake1]
public:
    Observer();     //Konstruktori
    int GetState(int &formID);
    void SetState(int &formID);
};

extern Observer *observer;
//---------------------------------------------------------------------------
#endif
 