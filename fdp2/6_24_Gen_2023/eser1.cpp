#include<iostream>
using namespace std;
int main() {
    int v[] = {2,2,0,6,6,6};
    int *p1; // puntatore a intero
    int *p2; // puntatore a intero
    int a; // variabile intera
    int b; //variabile intera
    a = v[0]; // viene assegnata alla variabile a il valore dell'elemento con indice 0, a=2
    b = v[1]; // viene assegnata alla variabile a il valore dell'elemento con indice 1, a=2
    cout<<b<<endl;
    p1 = &a;  // p1 punta l'indirizzo di memoria della variabile a
    p2 = &b;  // p2 punta l'indirizzo di memoria della variabile b
    p1 = p2;  // p1 ora punta lo stesso indirizzo di p2, quindi p1 punta all'indirizzo di memoria di b
    *p2 = v[2]; // il valore puntato da p2 viene sovrascritto dall'elemento con indice 2, quindi ora v[1]=v[2]
    a = v[3];  // viene assegnata alla variabile a il valore dell'elemento con indice 3, a=6
    // 2,0,0,6,6,6
    // a = 6
    // b = 0 

    // 1. Cosa stampa la seguente istruzione?
    cout << *p1 << *p2 << a << b << endl; // 0 0 6 0

    // 2. Data la seguente istruzione, indicare qual è
    // il modo corretto (A, B, C o D) di gestire la memoria dinamica
    // int* q1 = new int(20);
    // 2A:
    // delete q1[0];
    // 2B: Non c'è bisogno di alcuna delete
    // 2C:
    // for (int i = 0; i < 20; ++i) { delete[] q1[i] }
    // delete q1;
    // 2D:
    // delete q1; // corretta

    int *ptr = &v[0]; // ptr punta l'indirizzo di memoria dell'elemento con indice 0
    int *qtr = &v[3]; // qtr punta l'indirizzo di memoria dell'elemento con indice 0

    // 3. Cosa stampa la seguente istruzione?
    cout << qtr - ptr << endl; // stampa la distanza tra l'elemento puntato da qtr e l'elemento puntato da ptr : da 3 a 0 la distanza è 3

    // 4. Cosa stampa la seguente istruzione?
    int &f = v[2]; // f è un alias di v[2]
    f = 7; // f e v[2] ora hanno come valore 7
    for (int i = 0; i < 5; ++i) { // scandisce gli elementi di v tranne l'ultimo
        cout << *(v+i); // stampa tutti gli elementi di v : 2,2,7,6,6
    }
    cout << endl;
}