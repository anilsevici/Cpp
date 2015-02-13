#ifndef STRING_H
#define STRING_H

using std::ostream;
using std::istream;

class String
{
public:
    String(int);
    ~String();
    String(const String &);
    void stringayarla(char *);
    char *stringoku()const;
    void boyayarla(int);
    int boyoku() const;
    bool operator==(const String &)const;
private:
    int boy;
    char *stringptr;
};

ostream &operator<<(ostream &,const String &);
istream &operator>>(istream &,String &);

#endif // STRING_H
