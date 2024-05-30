#include<iostream>
using namespace std;
int main() {

    int v[] = {2,2,0,6,6,6}; 
    int *x = v + 2; // x punta all'elemento con indice 2
    int *y = v + 4; // y punta all'elemento con indice 4
    *(x+1) = *x; // l'elemento dopo x ora è uguale a *x, quindi v[3]=v[2] 
    *(y+1) = *y; // l'elemento dopo y ora è uguale a *y, quindi v[5]=v[4]
    // 2,2,0,0,6,6

    // A: Cosa stampa la seguente istruzione?
    for (int i = 0; i < 6; ++i) cout << v[i]; // scandisce gli elementi di v e li stampa : 2,2,0,0,6,6
    cout << endl;

    // B: Cosa stampa la seguente istruzione?
    cout << (y - x) + (*y + *x) << endl; // la prima stampa la distanza tra y e x, tra 4 2 la distanza è 2, la seconda stampa 6+0=6, quindi 2+6=8
    
    int *p, *q = new int[10];
    // C: Qual è il modo corretto di deallocare la memoria dinamica?
    // /* 1 */ for (int i = 0; i < 10; ++i) { delete q[i]; delete p[i]; }
    // /* 2 */ delete[] q; delete[] p; // corretto
    // /* 3 */ delete p; delete q;
    // /* 4 */ delete[] q;


    int &a = v[1]; // a è un alias di v[1]
    int b = v[0]; // b=2
    b = *y; // b=v[4]
    a = *y; // essendo a un alias, a=v[4] ma anche v[1]=v[4]
    // D: Cosa stampa la seguente istruzione?
    for (int i = 0; i < 6; ++i) cout << v[i]; // scandisce gli elementi in v e li stampa: 2,6,0,0,6,6
    cout << endl;
}