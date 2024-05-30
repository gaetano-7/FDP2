#include "Studente.h"

#include <iostream>
using namespace std;
int main(){

    cout << "Inserisci il numero di studenti: ";
    int numero_studenti; cin >> numero_studenti;

    Studente* studenti = new Studente[numero_studenti];

    for(int i = 0; i < numero_studenti; i++)
    {
        cout << "Sto inserendo lo studente numero " << (i+1) << endl;
        cin >> studenti[i];
    }

    //TEST METODI
    delete [] studenti;
    
    return 0;

}