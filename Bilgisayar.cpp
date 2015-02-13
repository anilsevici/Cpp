#include<iostream>
#include<iomanip>

#include "String.h"
#include "Bilgisayar.h"

using namespace std;

Bilgisayar::Bilgisayar():seri_numara(13),marka(11),model(11)
{

}

Bilgisayar::Bilgisayar(const String &seri,const String &ma,const String &mo):seri_numara(seri),marka(ma),model(mo)
{

}

Bilgisayar::Bilgisayar(const Bilgisayar &copy):seri_numara(copy.seri_numara),marka(copy.marka),model(copy.model)
{

}

void Bilgisayar::setmarka(String m)
{
    marka.stringayarla(m.stringoku());
}

String Bilgisayar::getmarka() const
{
    return marka;
}

void Bilgisayar::set_serinumara(String se)
{
    seri_numara.stringayarla(se.stringoku());
}

String Bilgisayar::getserinumara() const
{
    return seri_numara;
}

void Bilgisayar::setmodel(String mo)
{
    model.stringayarla(mo.stringoku());
}

String Bilgisayar::getmodel() const
{
    return model;
}

istream &operator>>(istream &input ,Bilgisayar &obj)
{
    String se(13),ma(11),mo(11);

    input>>se;
    obj.set_serinumara(se);
    input.ignore();

    input>>ma;
    obj.setmarka(ma);
    input.ignore();

    input>>mo;
    obj.setmodel(mo);

    return input;

}

ostream &operator<<(ostream &output,const Bilgisayar &obj)
{
    output<<obj.getserinumara()<<'\t'<<'\t'<<obj.getmarka()<<'\t'<<obj.getmodel()<<endl;

    return output;
}
