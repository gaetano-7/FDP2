#include <iostream>
using namespace std;

int main(){
    int* matricola = new int[6]{2,2,0,6,6,6}; //scrivi sul foglio la tua matricola
    //1. La seguente istruzione è corretta? Se sì, cosa stampa?
    cout << *(matricola + 3) << *(matricola + 2) << endl;
    // stampa l'elemento con indice 3 + l'elemento con indice 2 dell'array matricola : 6 0

    // //2. La seguente istruzione è corretta? Se sì, cosa stampa?
    //cout << *(matricola[0]) << endl;
    // non è corretta, se si vuole stampare l'elemento con indice 0 si scrive cout<<*(matricola + 0)

    // //3. Cosa viene stampato dalla seguente porzione di codice?
    int& a = matricola[4]; // '&' crea un alias per matricola[4], quindi ora ogni modifica fatta ad a viene fatta anche a matricola[4]
    int b = matricola[5]; // qui invece viene solo copiato il valore di matricola[5]
    --a; // decrementa il valore di a e quindi anche di matricola[4], da 6 ora passa a 5
    b += 1; // incrementa il valore di b ma non di matricola[5] perchè non è un alias
    cout << matricola[4] << " " << matricola[5] << endl; // stampa 5 6

    //4. Come andrebbe deallocata la memoria dinamica allocata inizialmente?
    //A
    //for(int i = 0; i < 6; i++)
    //delete matricola[i];
    //B
    //for(int i = 0; i < 6; i++)
    //delete *matricola[i];
    //C
    //Nel main non serve deallocare la memoria dinamica.
    //D
    //delete [] matricola;
    // corretta D
}