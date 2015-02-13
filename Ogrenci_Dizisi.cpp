#include<iostream>
#include<iomanip>

#include "String.h"
#include "Tarih.h"
#include "Bilgisayar.h"
#include "Ogrenci.h"
#include "Ogrenci_Dizisi.h"

using namespace std;

Ogrenci_Dizisi::Ogrenci_Dizisi()
{
    for(int i=0; i<1000; i++)
        ogrencidizisi[i]=NULL;
}

Ogrenci_Dizisi::~Ogrenci_Dizisi()
{
    //dtor
}

void Ogrenci_Dizisi::yeni_ogr_ekle(Ogrenci *yeni_ogrenci)
{
    ogrencidizisi[yeni_ogrenci->noOku()-1]=yeni_ogrenci;
}

Ogrenci *Ogrenci_Dizisi::ara(int ogr_no)const
{
    return ogrencidizisi[ogr_no-1];
}

Ogrenci *Ogrenci_Dizisi::ogrenci_cikar(int ogr_no)
{
    Ogrenci *gecici;
    if(ogrencidizisi[ogr_no-1]==NULL) return NULL;
    else
    {
        gecici=ogrencidizisi[ogr_no-1];
        ogrencidizisi[ogr_no-1]=NULL;
        return gecici;
    }

}

void Ogrenci_Dizisi::sinif_ve_not_guncelle()
{
    int sinif;
    float ort;

    for(int i=0; i<1000; i++)
    {
        if(ogrencidizisi[i]!=NULL)
        {
            cout<<"   "<<i+1<<"nolu ogrencinin yeni sinifini giriniz:";
            cin>>sinif;
            ogrencidizisi[i]->sinifAyarla(sinif);
            cout<<"Bu ogrencinin yeni not ortalamasini giriniz:";
            cin>>ort;
            ogrencidizisi[i]->notortAyarla(ort);
            cout<<"Ogrencinin sinifi ve ortalamasi basariyla guncellendi"<<endl;
        }
    }
}

void Ogrenci_Dizisi::sinif_listele(int ogr_sinif)
{
    int sinif_sayac=0;
    for(int i=0; i<1000; i++)
    {
        if(ogrencidizisi[i]!=NULL && ogrencidizisi[i]->sinifOku()==ogr_sinif)
        {
            cout<<ogrencidizisi[i];
            sinif_sayac++;
        }

    }
    cout<<"Sinifin ogrenci sayisi:"<<sinif_sayac<<endl;
}

void Ogrenci_Dizisi::ada_gore_listele(String ogr_ad)
{
    for(int i=0; i<1000; i++)
    {
        if(ogrencidizisi[i]!=NULL && ogrencidizisi[i]->adOku()==ogr_ad)
            cout<<ogrencidizisi[i];
    }
}

void Ogrenci_Dizisi::tarihe_gore_listele(Tarih ogr_dogum_tarih)
{
    for(int i=0; i<1000; i++)
    {
        if(ogrencidizisi[i]!=NULL && ogrencidizisi[i]->dogum_tarihOku()<ogr_dogum_tarih)
            cout<<ogrencidizisi[i];
    }
}

void Ogrenci_Dizisi::yila_gore_listele(Tarih kayit_yil)
{
    for(int i=0; i<1000; i++)
    {
        if(ogrencidizisi[i]!=NULL && ogrencidizisi[i]->kayit_tarihOku()>kayit_yil)
            cout<<ogrencidizisi[i];
    }
}

void Ogrenci_Dizisi::seri_noya_gore_listele(String pc_seri_no)
{
    for(int i=0; i<1000; i++)
    {
        if(ogrencidizisi[i]!=NULL && ogrencidizisi[i]->bilgisayarOku().getserinumara()==pc_seri_no)
            cout<<ogrencidizisi[i];
    }
}

void Ogrenci_Dizisi::marka_modele_gore_listele(String pc_marka,String pc_model)
{
    for(int i=0; i<1000; i++)
    {
        if(ogrencidizisi[i]!=NULL && ogrencidizisi[i]->bilgisayarOku().getmarka()==pc_marka && ogrencidizisi[i]->bilgisayarOku().getmodel()==pc_model)
            cout<<ogrencidizisi[i];
    }
}

ostream &operator<<(ostream &output,const Ogrenci_Dizisi &obj)
{
    for(int i=1; i<=1000; i++)
    {
        if(obj.ara(i)!=NULL)
            output<<obj.ara(i);
    }

    return output;
}
