#include<iostream>
#include<iomanip>

#include "String.h"
#include "Tarih.h"
#include "Bilgisayar.h"
#include "Ogrenci.h"

using namespace std;

Ogrenci::Ogrenci(int no,String ogr_ad,String ogr_soyad,Tarih ogr_dogum,Tarih ogr_kayit,
                 Bilgisayar tasinabilir,int ogr_sinif,float ogrenci_ort):ogr_no(no),ad(ogr_ad),soyad(ogr_soyad),dogum_tarihi(ogr_dogum),kayit_tarihi(ogr_kayit),tasinabilir_bilgisayar(tasinabilir)
{
    sinifAyarla(ogr_sinif);
    notortAyarla(ogrenci_ort);

}

Ogrenci::~Ogrenci()
{
    //dtor
}

void Ogrenci::sinifAyarla(int sinifval)
{
    sinif=sinifval;
}

void Ogrenci::notortAyarla(float notval)
{
    not_ort=notval;
}

int Ogrenci::noOku()const
{
    return ogr_no;
}

String Ogrenci::adOku()const
{
    return ad;
}

String Ogrenci::soyadOku()const
{
    return soyad;
}

Tarih Ogrenci::dogum_tarihOku()const
{
    return dogum_tarihi;
}

Tarih Ogrenci::kayit_tarihOku()const
{
    return kayit_tarihi;
}

Bilgisayar Ogrenci::bilgisayarOku()const
{
    return tasinabilir_bilgisayar;
}

int Ogrenci::sinifOku()const
{
    return sinif;
}

float Ogrenci::ortalamaOku()const
{
    return not_ort;
}

ostream &operator<<(ostream &output,const Ogrenci *obj)
{
    output<<obj->noOku()<<'\t'<<obj->adOku()<<'\t'<<obj->soyadOku()<<'\t'<<'\t'<<obj->sinifOku()<<'\t'<<obj->ortalamaOku()<<'\t'<<obj->dogum_tarihOku()<<'\t'<<obj->kayit_tarihOku()<<endl;

    return output;
}
