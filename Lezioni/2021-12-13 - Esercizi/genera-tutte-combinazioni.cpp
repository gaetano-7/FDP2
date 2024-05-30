// SCRIVERE UNA FUNZIONE CHE RICEVUTO UN PARAMETRO N GENERI
// UNA LISTA CON TUTTE LE COMBINAZIONI DI VALORI VERO/FALSO DI N VARIABILI


#include <iostream>
#include <vector>
#include <list>
using namespace std;
#include <cassert>

typedef  vector<bool> vectorbool;

void genera_ric(int n, vector<bool>& v, list<vectorbool> & l)
{
    if (n==0) l.push_back(v);
    else{
        v[n-1]=0;
        genera_ric(n-1,v,l);
        v[n-1]=1;
        genera_ric(n-1,v,l);
    }

}

list<vectorbool> genera(int n)
{
    vector<bool> b(n,false);
    list<vectorbool> l;
    genera_ric(n,b,l);
    return l;
}


int main(){

    list<vectorbool> l=genera(5);

    for (auto v : l)
    {
        for(auto e : v)
            cout<<(e)?"1":"0";
        cout<<endl;
    }

}


