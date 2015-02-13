#ifndef TARIH_H
#define TARIH_H

using std::ostream;
using std::istream;

class Tarih
{
public:
    Tarih(int=1,int=12,int=31);
    Tarih(const Tarih &);
    int Getay() const;
    void Setay(int);
    int Getgun()const;
    void Setgun(int);
    int Getyil()const;
    void Setyil(int);
    bool operator>(const Tarih &)const;
    bool operator<(const Tarih &)const;

private:
    int ay;
    int gun;
    int yil;
};

ostream &operator<<(ostream &,const Tarih &);
istream &operator>>(istream &,Tarih &);

#endif // TARIH_H
