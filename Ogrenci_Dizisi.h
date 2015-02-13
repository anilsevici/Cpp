#ifndef OGRENCI_DIZISI_H
#define OGRENCI_DIZISI_H

#include "String.h"
#include "Tarih.h"
#include "Bilgisayar.h"
#include "Ogrenci.h"

using std::ostream;

class Ogrenci_Dizisi
{
public:
    Ogrenci_Dizisi();
    ~Ogrenci_Dizisi();
    Ogrenci *ara(int)const;
    void yeni_ogr_ekle(Ogrenci *);
    Ogrenci *ogrenci_cikar(int);
    void sinif_ve_not_guncelle();
    void sinif_listele(int);
    void ada_gore_listele(String);
    void tarihe_gore_listele(Tarih);
    void seri_noya_gore_listele(String);
    void marka_modele_gore_listele(String,String);
    void yila_gore_listele(Tarih);

private:
    Ogrenci *ogrencidizisi[1000];
};

ostream &operator<<(ostream &,const  Ogrenci_Dizisi &);

#endif // OGRENCI_DIZISI_H
