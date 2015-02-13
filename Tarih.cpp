#include<iostream>
#include<iomanip>

#include "Tarih.h"

using namespace std;

Tarih::Tarih(int y,int a,int g)
{
    Setgun(g);
    Setay(a);
    Setyil(y);
}

Tarih::Tarih(const Tarih &copy):ay(copy.ay),gun(copy.gun),yil(copy.yil)
{

}

int Tarih::Getay()const
{
    return ay;
}

void Tarih::Setay(int val)
{
    ay = val;
}

int Tarih::Getgun()const
{
    return gun;
}

void Tarih::Setgun(int val)
{
    gun = val;
}

int Tarih::Getyil()const
{
    return yil;
}

void Tarih::Setyil(int val)
{
    yil = val;
}

bool Tarih::operator>(const Tarih &karsilastirilan)const
{
    if(yil>karsilastirilan.yil)
        return true;
    else if(yil<karsilastirilan.yil)
        return false;//Yila gore karsilastirma
    else if(ay>karsilastirilan.ay)
        return true;
    else if(ay<karsilastirilan.ay)
        return false;//Aya gore karsilastirma
    else if(gun>karsilastirilan.gun)
        return true;
    else if(gun<karsilastirilan.gun)
        return false;
    else return false;
}

bool Tarih::operator<(const Tarih &karsilastirilan)const
{
    if(yil<karsilastirilan.yil)
        return true;
    else if(yil>karsilastirilan.yil)
        return false;//Yila gore karsilastirma
    else if(ay<karsilastirilan.ay)
        return true;
    else if(ay>karsilastirilan.ay)
        return false;//Aya gore karsilastirma
    else if(gun<karsilastirilan.gun)
        return true;
    else if(gun>karsilastirilan.gun)
        return false;
    else return false;
}

istream &operator>>(istream &input,Tarih &obj)
{
    int g,a,y;

    input>>setw(3)>>g;
    obj.Setgun(g);
    input.ignore();

    input>>setw(3)>>a;
    obj.Setay(a);
    input.ignore();

    input>>setw(5)>>y;
    obj.Setyil(y);

    return input;
}

ostream &operator<<(ostream &output,const Tarih &obj)
{
    output<<obj.Getgun()<<"."<<obj.Getay()<<"."<<obj.Getyil();

    return output;
}
