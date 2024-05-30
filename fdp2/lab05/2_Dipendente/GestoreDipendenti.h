#ifndef GESTOREDIPENDENTI_H
#define GESTOREDIPENDENTI_H

#include <iostream>
#include <string>
#include <vector>
#include "Dipendente.h"

class GestoreDipendenti{
public:
    GestoreDipendenti() {};

    bool aggiungiDipendente(Dipendente d);
    bool esisteDipendente(string id) const;
    void rimuoviDipendente(string id);
    void stampa() const;
    float calcolaCostoDipendenti() const;

private:
    vector<Dipendente> dipendenti;
};

#endif