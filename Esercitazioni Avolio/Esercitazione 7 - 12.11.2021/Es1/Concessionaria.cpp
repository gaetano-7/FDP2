#include "Concessionaria.h"

bool Concessionaria::aggiungi(Veicolo* v){
    for(auto it = veicoli.begin(); it!=veicoli.end(); it++)
        if((**it).getTarga() == (*v).getTarga())
            return false;

    veicoli.push_back(v);
    return true;
}

bool Concessionaria::rimuovi(string targa){
    for(auto it = veicoli.begin(); it!=veicoli.end(); it++)
        if((**it).getTarga() == targa){
            veicoli.erase(it);
            return true;
        }
    return false;
}

void Concessionaria::stampaPrezzo(string targa)const{
    for(auto it = veicoli.begin(); it!=veicoli.end(); it++)
        if((**it).getTarga() == targa){
            cout << "Il prezzo è pari a " << (**it).getPrezzo() << endl;
            return;
        }
    cout << "Veicolo non trovato" << endl;
}

void Concessionaria::stampa() const{
    for(auto it = veicoli.begin(); it!=veicoli.end(); it++)
        cout << (**it) << endl;
}