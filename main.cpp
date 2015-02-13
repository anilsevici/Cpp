#include <iostream>

#include "String.h"
#include "Tarih.h"
#include "Bilgisayar.h"
#include "Ogrenci.h"
#include "Ogrenci_Dizisi.h"

using namespace std;

int menu_secim(void);
void baslik_yazdir();

int main()
{
    int ogr_no,sinif,yil;
    float ort;
    String ad(16),soyad(21),seri_no(13),marka(11),model(11);
    Tarih dogum,kayit;
    Bilgisayar tasinabilir_bilgisayar;
    Ogrenci *bir_ogrenci;
    Ogrenci_Dizisi ogrenciler;

    int secenek;

    do
    {
        secenek=menu_secim();
        switch(secenek)
        {
        case 1:
            cout<<"Yeni kazanan ogrencinin numarasini giriniz:";
            cin>>ogr_no;
            if(ogrenciler.ara(ogr_no)==NULL)
            {
                cout<<"Ogrencinin adini ve soyadini bosluk birakarak giriniz:";
                cin>>ad>>soyad;

                cout<<"Dogum tarihini (GG.AA.YYYY) seklinde giriniz:";
                cin>>dogum;
                cout<<"Kayit tarihini (GG.AA.YYYY) seklinde giriniz:";
                cin>>kayit;

                cout<<"Tasinabilir bilgisayar icin verileri seri numara marka model sirasinda bosluk birakarak giriniz:";
                cin>>tasinabilir_bilgisayar;

                bir_ogrenci=new Ogrenci(ogr_no,ad,soyad,dogum,kayit,tasinabilir_bilgisayar);
                ogrenciler.yeni_ogr_ekle(bir_ogrenci);
                cout<<"Yeni ogrenci basariyla kaydedildi"<<endl;
            }
            else cout<<"Bu ogrenci numarasina sahip ogrenci bulunmaktadir"<<endl;
            break;
        case 2:
            cout<<"Yatay gecisle gelen ogrencinin numarasini giriniz:";
            cin>>ogr_no;
            if(ogrenciler.ara(ogr_no)==NULL)
            {
                cout<<"Ogrencinin adini ve soyadini bosluk birakarak giriniz:";
                cin>>ad>>soyad;

                cout<<"Dogum tarihini (GG.AA.YYYY) seklinde giriniz:";
                cin>>dogum;
                cout<<"Kayit tarihini (GG.AA.YYYY) seklinde giriniz:";
                cin>>kayit;

                cout<<"Tasinabilir bilgisayar icin verileri seri numara marka model sirasinda bosluk birakarak giriniz:";
                cin>>tasinabilir_bilgisayar;

                cout<<"Ogrencinin sinifini giriniz:";
                cin>>sinif;
                cout<<"Ogrencinin ortalamasini giriniz:";
                cin>>ort;

                bir_ogrenci=new Ogrenci(ogr_no,ad,soyad,dogum,kayit,tasinabilir_bilgisayar,sinif,ort);
                ogrenciler.yeni_ogr_ekle(bir_ogrenci);
                cout<<"Yeni ogrenci basariyla kaydedildi"<<endl;
            }
            else cout<<"Bu ogrenci numarasina sahip ogrenci bulunmaktadir"<<endl;

            break;
        case 3:
            ogrenciler.sinif_ve_not_guncelle();
            break;
        case 4:
            cout<<"Silmek istediginiz ogrencinin numarasini giriniz:";
            cin>>ogr_no;
            bir_ogrenci=ogrenciler.ogrenci_cikar(ogr_no);
            if(bir_ogrenci)
                delete bir_ogrenci;
            else cout<<"Bu ogrenci numarasina sahip ogrenci yoktur";
            break;
        case 5:
            cout<<"Goruntulemek istediginiz ogrencinin numarasini giriniz:";
            cin>>ogr_no;
            bir_ogrenci=ogrenciler.ara(ogr_no);
            if(bir_ogrenci==NULL)
                cout<<"Boyle bir ogrenci bulunmamaktadir."<<endl;
            else
            {
                baslik_yazdir();
                cout<<bir_ogrenci<<endl;
                cout<<"Verilen Bilgisayar:"<<endl;
                cout<<"Seri Numarasi   Marka   Model"<<endl;
                cout<<"-------------   -----   -----"<<endl;
                cout<<bir_ogrenci->bilgisayarOku();
            }
            break;
        case 6:
            baslik_yazdir();
            cout<<ogrenciler;
            break;
        case 7:
            cout<<"Ogrencilerini gormek istediginiz sinifi giriniz:";
            cin>>sinif;
            baslik_yazdir();
            ogrenciler.sinif_listele(sinif);
            break;
        case 8:
            cout<<"Girdiginiz ada gore listelemek icin bir ad giriniz:";
            cin>>ad;
            baslik_yazdir();
            ogrenciler.ada_gore_listele(ad);
            break;
        case 9:
            cout<<"Girdiginiz tarihten once dogan ogrencileri listelemek icin tarihi (GG.AA.YYYY) seklinde giriniz:";
            cin>>dogum;
            baslik_yazdir();
            ogrenciler.tarihe_gore_listele(dogum);
            break;
        case 10:
            cout<<"Girdiginiz yildan sonra bolume kaydedilmis ogrencileri listelemek icin yil giriniz:";
            cin>>yil;
            kayit=Tarih(yil);
            baslik_yazdir();
            ogrenciler.yila_gore_listele(kayit);
            break;
        case 11:
            cout<<"Verilmis bilgisayarin seri numarasina sahip ogrencileri listelemek icin seri numarasi giriniz:";
            cin>>seri_no;
            baslik_yazdir();
            ogrenciler.seri_noya_gore_listele(seri_no);
            break;
        case 12:
            cout<<"Verilmis bilgisayarin marka ve modeline sahip ogrencileri listelemek icin verileri marka model sirasinda bosluk birakarak giriniz:";
            cin>>marka>>model;
            baslik_yazdir();
            ogrenciler.marka_modele_gore_listele(marka,model);
            break;
        }
    }
    while (secenek!=13);

    return 0;
}

void baslik_yazdir()
{
    cout<<"Ogr No  Ad      Soyad        Sinif    Not Ort   Dogum Tar      Kayit Tar"<<endl;
    cout<<"------  ------- ------------ -----    -------   ---------      ---------"<<endl;
}

int menu_secim(void)
{
    int secim;

    cout << endl;
    cout << "********************MENU************************************" << endl;
    cout << "1. Yeni kazanan bir ogrencinin okula kaydedilmesi" << endl;
    cout << "2. Yatay gecisle gelen bir ogrencinin okula kaydedilmesi" << endl;
    cout << "3. Yil sonunda tum ogrencilerin siniflarinin ve not ortalamalarinin guncellenmesi" << endl;
    cout << "4. Bir ogrencinin okuldan kaydinin silinmesi" << endl;
    cout << "5. Bir ogrencinin bilgilerinin goruntulenmesi" << endl;
    cout << "6. Okula kayitli tum ogrencilerin listelenmesi" << endl;
    cout << "7. Bir sinifta okuyan ogrencilerin listelenmesi" << endl;
    cout << "8. Belirli bir ada sahip ogrencilerin listelenmesi" << endl;
    cout << "9. Belirli bir tarihten once dogan ogrencilerin listelenmesi" << endl;
    cout << "10.Belirli bir yildan sonra bolume kaydedilmis ogrencilerin listelenmesi" << endl;
    cout << "11.Bir tasinabilir bilgisayarin verilmis oldugu ogrencinin bilgilerinin goruntulenmesi" << endl;
    cout << "12.Belirli bir marka ve model bilgisayarin verilmis oldugu ogrencilerin listelenmesi" << endl;
    cout << "13.Cikis" << endl;
    do
    {
        cout << "Seciminizi Giriniz:";
        cin >> secim;
    }
    while(secim<1 || secim>13);

    return secim;
}
