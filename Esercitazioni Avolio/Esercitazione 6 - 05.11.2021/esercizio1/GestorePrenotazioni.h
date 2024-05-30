#ifndef GESTORE_PRENOTAZIONI_H
#define GESTORE_PRENOTAZIONI_H

#include <list>
#include <vector>
using namespace std;

#include "Prenotazione.h"

class GestorePrenotazioni{

    public:
        GestorePrenotazioni();
        bool aggiungiPrenotazione(int posti, string codice);
        bool rimuoviPrenotazione(int numero);
        void stampaPrenotazioni(string codice) const;
        void ordinaPrenotazioni();

        ~GestorePrenotazioni();
        GestorePrenotazioni(const GestorePrenotazioni& p);
        GestorePrenotazioni& operator=(const GestorePrenotazioni& p);
    
    private:
        list<Prenotazione*> prenotazioni;
        bool esistePrenotazione(int n);

        vector<string> codici = {"a0001", "b0002", "c0003", "d0004", "e0005", "f0006", "g0007", "h0008", "i0009", "z0010"};
        vector<int> postiTotali = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

};

#endif