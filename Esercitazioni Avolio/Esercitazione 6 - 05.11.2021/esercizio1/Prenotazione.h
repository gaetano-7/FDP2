#ifndef PRENOTAZIONE_H
#define PRENOTAZIONE_H

#include <iostream>
using namespace std;

class Prenotazione{

    friend ostream& operator<<(ostream& o, const Prenotazione& p){
        o << "[pre. " << p.getNumero() << " ] per" << p.getCodice() << ":" << p.getPosti()<< " posti" << endl;
        return o;
    }

    private:
        int numero;
        int posti;
        string codice;

    public:
        Prenotazione(int n, int p, string c) : numero(n), posti(p), codice(c){};
        int getNumero()const{return numero;}
        int getPosti()const{return posti;}
        string getCodice()const{return codice;}
        
};

#endif