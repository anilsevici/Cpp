#ifndef OGRENCI_H
#define OGRENCI_H

#include "String.h"
#include "Tarih.h"
#include "Bilgisayar.h"

using std::ostream;

class Ogrenci
{
public:
    Ogrenci(int,String,String,Tarih,Tarih,Bilgisayar,int=1,float=0);
    ~Ogrenci();
    void sinifAyarla(int);
    void notortAyarla(float);
    int noOku()const;
    String adOku()const;
    String soyadOku()const;
    Tarih dogum_tarihOku()const;
    Tarih kayit_tarihOku()const;
    Bilgisayar bilgisayarOku()const;
    int sinifOku()const;
    float ortalamaOku()const;

private:
    const int ogr_no;
    const String ad;
    const String soyad;
    const Tarih dogum_tarihi;
    const Tarih kayit_tarihi;
    const Bilgisayar tasinabilir_bilgisayar;
    int sinif;
    float not_ort;

};

ostream &operator<<(ostream &,const  Ogrenci *);

#endif // OGRENCI_H
