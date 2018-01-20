#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
/* 3. Egy kutyakiallitason n kategoriaban m kutya vesz reszt. Minden kutya minden kategoriaban egy 0 es 10 kozotti pontszamot kap.
 Mekkora pontszambeli kulonbseg az elso es az utolso helyezett kutya kozott? */
using namespace std;
int maxminker(const vector<vector<int> > &t);
bool fajl(vector<vector<int> > &t);
void bill(vector<vector<int> > &t);
int main()
{
    int u;
    string s;
    do{
    vector<vector<int> > t;
    cout<<"fajbol v billrol (f/b)? ";

    cin>>s;
    if(s[0]=='f')
    {
        if(fajl(t))
        {

            cout<<"Az elso helyezett es utolso helyezett kutyak pontszamanak a kulombsege: "<<maxminker(t);
        }

    }
    else
    {
        if(s[0]=='b')
       {
            bill(t);
         cout<<"Az elso helyezett es utolso helyezett kutyak pontszamanak a kulombsege: "<<maxminker(t)<<" pont";

       }
       cout<<"hiba";
    }

    cout<<endl;
    cout<<"ujra futatja a programot? (ha 1 akkor fut ujra) ";
    cin>>u;


    }while(u==1);
    return 0;
}
bool fajl(vector<vector<int> > &t)
{

    string s;
    bool l=false;
    int n, m;
    do{
    cout<<"adja meg a fajl elereset: ";
    cin>>s;
    ifstream f(s.c_str());
    if(f.fail()){
    cout << "Hibas fajl v nem letezik"<<endl;
     }
    f >> n >> m;
    if(!(n>=1 && m>=2)){
        cout<<"a kutyaknak a szama legalabb 2 nek kell lennie es legalabb 1 kategorianak is"<<endl;
        return false;
    }
    t.resize(n);
    for(int i=0; i<n; ++i){
        t[i].resize(m);
        for(int j=0; j<m; ++j){
            f >> t[i][j];
                    if(!(t[i][j]>=0 && t[i][j]<=10)){
                    l=false;
                    cout<<"evenytelen pontokat tartalmaz.(0-10 -ig lehet pontozni)"<<endl;
                    return false;
                    }
                    else{
                    l=true;
                    }
        }
    }

    }while(!l);

    cout<<endl;
    for(int i=0; i<t.size(); ++i){
        for(int j=0; j<t[i].size(); ++j){
            cout<<t[i][j]<<" ";
        }
    cout<<endl;
    }
    cout<<endl;
    return l;
}

void bill(vector<vector<int> > &t)
{
    int n, m;

do{cout << "Kategoriak szama(n>0): "; cin>>n;
        while(cin.fail())
        {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Szamot irjon, kategoriak szama(n>0): ";
        cin >> n;
    }
    }while(!(n>=1));

do{cout << "kutyak szama(m>1): "; cin >>m;
 while(cin.fail())
        {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Szamot irjon, kutyak szama(m>1): ";
        cin >> m;
    }

 }while(!(m>=2));
cin.clear();

t.resize(n);
for(int i=0; i<n; ++i){
    t[i].resize(m);
    for(int j=0; j<m; ++j){
   do{
cout << j+1 << ". kutya " << i+1 << ".kategoriaban elert pontszama: ";
cin >> t[i][j];
while(cin.fail())
        {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Szamot irjon, (1..10): ";
        cin >> t[i][j];
    }
}while(!(t[i][j]>=0 && t[i][j]<=10));

} cout<<endl; }
}

int maxminker(const vector<vector<int> >&t)
{
int maxbolmin=0;
int max;
int min;
bool l=true;
int osszeg=0;

    for(int j=0; j<t[0].size(); ++j){
         for(int i=0; i<t.size(); ++i){
                osszeg+=t[i][j];
         }

//cout<<endl<<endl<<"osszeg: "<<osszeg<<endl;;

    if(l)
    {
        max=osszeg;
        min=osszeg;
        l=false;
    }
    else
    {
         if(osszeg>max){     max=osszeg;   } //Maximum kivalasztas

         if(osszeg<min){     min=osszeg;   } //Minimum kivalasztas
    }


    osszeg=0;
    }
//cout<<endl<<"maximum: "<<max<<" minimum: "<<min<<endl;
maxbolmin=max-min;
return maxbolmin;

}
