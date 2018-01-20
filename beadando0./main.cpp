#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;
int maxker(vector<int>x, vector<int>y);
void fajl( vector<int> &x, vector<int> &y);
void bill(vector<int> &x, vector<int> &y);
int main()
{
    int u;
    do{
    int n;
    vector<int> x;

    int m=1;
     vector<int> y;
    cout<<"fajbol v billrol (f/b)? ";
    char s;
    cin>>s;
    if(s=='f')
    {
        fajl(x,y);
    }
    else
    {
         bill(x,y);
    }


          cout<<"MAX: "<<maxker(x,y);


    cout<<endl;
    cout<<"ujra futatja a programot? (ha 1 akkor fut ujra) ";
    cin>>u;

    }while(u==1);
    return 0;
}
void fajl(vector<int> &x, vector<int> &y)
{

    string s;
    int n, m;
    bool l=false;
    do{
    cout<<"adja meg a fajl elereset: ";
    cin>>s;
    ifstream f(s.c_str());
    if(f.fail()){
    cout << "Hibas fajl v nem letezik"<<endl;
     }
    f >> n >>m;
    x.resize(n);
    for(int i=0; i<n; ++i){
    f>>x[i];
    }

    y.resize(m);
    for(int i=0; i<m; ++i){
           f>>y[i];
    if(y[i]>=0 && y[i]<x.size())
    {
    l=true;
    }
    else
    {
        l=false;

    }
    }
    if(!l){        cout<<"hibas ertekeket tartalmaz y"<<endl;}
    }while(!l);

    cout<<endl;
     for(int i=0;i<n;i++)
    {
        cout<<x[i]<<" ";
    }

    cout<<endl;

      for(int i=0;i<m;i++)
    {
        cout<<y[i]<<" ";
    }

    cout<<endl;
}
void bill(vector<int> &x, vector<int> &y)
{
    int n, m;
    do{
    cout<<"adja meg az x vektor elemszamat(n>0): ";
    cin>>n;
    }while(!(n>0));
    x.resize(n);

    for (long index=0; index<(long)x.size(); ++index)
    {int a;
    cout << "x[" << index << "]= ";
     cin>>a;
    x.at(index)=a;

    }

     do{
    cout<<"adja meg az y vektor elemszamat(0<m<=n): ";
    cin>>m;
    }while(!(m>0 && m<=x.size()));
    y.resize(m);
   //0<=y<n -re fogja megtalalni a maxot
 for (long index=0; index<(long)y.size(); ++index)
    {int a;
    do{
    cout << "y[" << index << "]= ";
     cin>>a;
      y.at(index)=a;
      if(!(a>=0 && a<x.size()))
      {
          cout<<"0 <= y < "<<x.size()<<endl;
      }
    }while(!(a>=0 && a<x.size()));
    }
}
int maxker(vector<int>x, vector<int>y)
{
int max=x[y[0]];
for(int i=1;i<y.size();i++)
{
if(x[y[i]]>max)
{
    max=x[y[i]];
}
}
return max;

}
