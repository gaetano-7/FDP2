#include <iostream>
using namespace std;

int main(){
    int* matricola = new int[6]{2,2,0,6,6,6};
    // cout << *(matricola + 3); // stampa elemento con indice 3
    // int& a1 = matricola[4]; // a è un alias di matricola[4], se modifichi a modifichi matricola[4]
    // delete [] matricola; // deallocare memoria dinamica
    int* a2 = &matricola[2]; // a2 punta matricola[2]
    cout<<a2<<endl; // stampa indirizzo di memoria puntato da a2 : 0x134aba61438
    cout<<*a2<<endl; // stampa il valore puntato da a2 : 0
    cout << *(a2 - 1) << endl; // stampa il valore puntato da a2 - 1 : indice[1]=2
    cout << matricola[0] + *(matricola+2); // stampa elemento con indice 0 + elemento con indice 2 : 2+0=2
    int s = 0;
    for(int i = 0; i < 6; i++) // scandisce tutti gli elementi dell'array matricola
        s += *(matricola+i); // somma gli elementi di matricola

    string* nc = new string[2]{"Gaetano", "Larocca"};
    cout << nc[0][2]; // stampa il carattere con indice 2 della stringa con indice 0, quindi 'e'
    cout << *(nc + 1)<<endl; // stampa l'elemento con indice 1, quindi "Larocca"
    for (int i = 0; i < nc[0].length();i++) // scandisce i caratteri della stringa con indice 0
        cout << nc[0][nc[0].length() - 1 - i]; // stampa la stringa al contrario, quindi "onateaG"
    cout<<endl;
    
    int *p1; // puntatore a intero
    int *p2; // puntatore a intero
    int a; // variabile intera
    int b; //variabile intera
    p1 = &a;  // p1 punta l'indirizzo di memoria della variabile a
    p2 = &b;  // p2 punta l'indirizzo di memoria della variabile b
    p1 = p2;  // p1 ora punta lo stesso indirizzo di p2, quindi p1 punta all'indirizzo di memoria di b
    *p2 = matricola[2]; // il valore puntato da p2 viene sovrascritto dall'elemento con indice 2, quindi ora v[1]=v[2]
    a = matricola[3];  // viene assegnata alla variabile a il valore dell'elemento con indice 3, a=6
    // 2,0,0,6,6,6
    // a = 6
    // b = 0 
    // 1. Cosa stampa la seguente istruzione?
    cout << *p1 << *p2 << a << b << endl; // 0 0 6 0

    int* q1 = new int(20); // -> delete q1;

    int *ptr = &matricola[0]; // ptr punta l'indirizzo di memoria dell'elemento con indice 0
    int *qtr = &matricola[3]; // qtr punta l'indirizzo di memoria dell'elemento con indice 3

    // 3. Cosa stampa la seguente istruzione?
    cout << qtr - ptr << endl; 
    // stampa la distanza tra l'elemento puntato da qtr e l'elemento puntato da ptr : da 3 a 0 la distanza è 3

    int v[] = {2,2,0,6,6,6}; 
    int *x = v + 2; // x punta all'elemento con indice 2
    int *y = v + 4; // y punta all'elemento con indice 4
    *(x+1) = *x; // l'elemento dopo x ora è uguale a *x, quindi v[3]=v[2] 
    *(y+1) = *y; // l'elemento dopo y ora è uguale a *y, quindi v[5]=v[4]
    // 2,2,0,0,6,6
    cout << (y - x) + (*y + *x) << endl; // tra y e x, tra 4 2 la distanza è 2 + stampa 6+0=6, quindi 2+6=8

    int *p, *q = new int[10]; // -> delete[] q; delete[] p;
}