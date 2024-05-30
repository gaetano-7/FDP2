#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H

#include "Veicolo.h"
#include <list>
using namespace std;

class Concessionaria{

    public:
        bool aggiungi(Veicolo*);
        bool rimuovi(string targa);
        void stampaPrezzo(string targa)const;
        void stampa()const;

    private:
        list<Veicolo*> veicoli;
};
#endif