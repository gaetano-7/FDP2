#include <iostream>
using namespace std;

int somma(int x,int y){
    int risultato;
    risultato=x+y;
    return risultato;
}

int prodotto(int risultato,int c){
    int cont;
    int prod;
    cont=0;
    while(cont<c){
        prod+=risultato;
        cont++;
    }
    return prod;
}

int main(){;
    int x;
    int y;
    int c;
    cout<<"inserisci primo numero: ";
    cin>>x;
    cout<<"inserisci secondo numero: ";
    cin>>y;
    cout<<"la somma e': "<<somma(x,y)<<endl;
    cout<<"per quale numero vuoi moltiplicare: ";
    cin>>c;
    cout<<"il prodotto e': "<<prodotto(somma(x,y),c);
    return 0;
}