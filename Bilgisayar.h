#ifndef BILGISAYAR_H
#define BILGISAYAR_H

using std::ostream;
using std::istream;

#include "String.h"

class Bilgisayar
{
public:
    Bilgisayar();
    Bilgisayar(const String &,const String &,const String &);
    Bilgisayar(const Bilgisayar &);
    void setmarka(String);
    String getmarka() const;
    void set_serinumara(String);
    String getserinumara() const;
    void setmodel(String);
    String getmodel() const;

private:
    String seri_numara;
    String marka;
    String model;
};

ostream &operator<<(ostream &,const  Bilgisayar &);
istream &operator>>(istream &,Bilgisayar &);

#endif // BILGISAYAR_H
