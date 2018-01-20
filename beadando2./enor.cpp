#include "enor.h"
#include <iostream>
using namespace std;

void Enor::next()
{
    if( (fin = f.fail()) ) return;
    cur.name = df.name;
    cur.db = 0;
    while( !f.fail() && df.name==cur.name ){
        if(df.faj =="ponty" && df.hossz>=30)
            {

                 cur.db++;
            }
        f >> df.name >> df.faj>> df.hossz;
    }
}

Enor::Enor(const string &str)
{
    f.open(str.c_str());
    if(f.fail()){
        cout << "Nem lehet megnyitni az inputfajlt!\n";
        exit(1);
    }
}
