#include <iostream>
using namespace std;

int main(){
    int voti[6] = {2,2,0,6,6,6};
    //1. La seguente istruzione è corretta? Se sì, cosa stampa?
    //cout << *voti[0];
    // non è corretta, per stampare il valore dell'elemento con indice 0 si fa cout<<*(voti + 0); : 

    //2. La seguente istruzione è corretta? Se sì, cosa stampa?
    cout << voti[0] + *(voti+2); // stampa l'elemento con indice 0 e l'elemento con indice 2 : (2+0) : 2
    cout<<endl;

    //3. Cosa stampa la seguente porzione di codice? Qual è il significato di tale porzione di codice?
    double s = 0; // inizializza una variabile double a 0

    for(int i = 0; i < 6; i++) // scandisce tutti gli elementi dell'array voti
        s += *(voti+i); // somma tutti i voti
    if(s/6 > 20) // se la media dei voti è maggiore di 20
        cout << "OK"; // stampa OK
    else // altrimenti
        cout <<"NO"; // stampa NO
    cout<<endl;
    
    //4. Cosa stampa la seguente porzione di codice?
    int a = voti[1]; // a assume il valore dell'elemento con indice 1, quindi a=2
    --a; // decrementa a, a=1
    cout << voti[1]; //siccome a non è un alias, le modifiche fatte su a non vengono fatte su voti[1], quindi resta invariato e stampa 2
}