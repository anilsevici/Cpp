#include<iostream>
#include<iomanip>

#include<cstdlib>
#include<cassert>
#include<cstring>

#include "String.h"

using namespace std;

String::String(int stringboy)
{
    boyayarla(stringboy);
    stringptr=new char[boyoku()];
    assert(stringptr!=0);

}

String::~String()
{
    delete [] stringptr;
}

String::String(const String &copy):boy(copy.boy)
{
    stringptr=new char[boyoku()];
    assert(stringptr!=0);

    for(int i=0; i<boy; i++)
        stringptr[i]=copy.stringptr[i];
}

void String::stringayarla(char *st)
{
    strcpy(stringptr,st);
}

char *String::stringoku()const
{
    return stringptr;
}

void String::boyayarla(int b)
{
    boy=b;
}

int String::boyoku() const
{
    return boy;
}

bool String::operator==(const String &karsilastirilan)const
{
    if(strcmp(strupr(stringptr),strupr(karsilastirilan.stringptr))==0)
        return true;

    return false;
}

istream &operator>>(istream &input,String &obj)
{
    char *st;
    st=new char[obj.boyoku()];

    input>>st;
    obj.stringayarla(st);

    return input;
}

ostream &operator<<(ostream &output,const String &obj)
{
    output<<obj.stringoku();

    return output;
}
