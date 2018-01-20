//Geszti Bence WXNDSZ
/*Feladat:      3. Egy horgászversenyen valahányszor egy versenyző halat fog,
 feljegyzik egy szöveges állomány soron következő sorába a versenyző azonosítóját (négyjegyű szám),
 a hal fajtájának nevét (ponty, keszeg, süllő, stb.) és a hal méretét. Feltehetjük, hogy a szöveges
  állomány helyesen van kitöltve: minden sorában három adat van (azonosító, halfajta, méret) szóközökkel
   vagy tabulátorjelekkel elválasztva. A verseny végén a szöveges állomány sorait azonosító szerint sorba rendezik.
    Adjuk meg annak az azonosítóját, aki a legtöbb 30 cm-nél hosszabb pontyot fogta?*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "enor.h"

using namespace std;


int main()
{
    Enor t("/Users/gesztibence/Desktop/egyetem/2.felev/programozas/beadando2./1.txt");
    int max;
    bool l=false;
    string azon;
    for( t.first(); !t.end(); t.next()){
       if(l && t.current().db!=0)
       {
           if(t.current().db>max)
           {
                max=t.current().db;
           azon=t.current().name;
           }

       }
       if(!l && t.current().db!=0)
           {
               l=true;
               max=t.current().db;
                azon=t.current().name;
           }

               if(t.current().db==0)
               {

               }


    }
    if(l)
    {
         cout << azon;
    }
    else
    {
        cout << "nem volt ilyen versenyzo";
    }

    return 0;
}
