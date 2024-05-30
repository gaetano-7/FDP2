
#ifndef Atletica_H
#define Atletica_H

#include "Vincitore.h"

#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*

    Questa classe contiene una lista di vincitori. Ogni vincitore e` caratterizzato dalle seguenti informazioni:

    - atleta: il nome di un atleta (string);

    - premio: il premio ricevuto dall'atleta per aver vinto la gara (int);

    - disciplina: la disciplina in cui l'atleta ha vinto (un enumerativo con 3 possibili valori: CENTO, DUECENTO, STAFFETTA).    
    
    Implementare nel file Atletica.cpp i metodi della classe Atletica.
    
*/
class Atletica   // questa riga e` corretta NON MODIFICARE
{
private:
    list<Vincitore> vincitori;

public:
    // DESCRIZIONE NEL FILE .cpp
    string metodo1();

    // DESCRIZIONE NEL FILE .cpp
    int metodo2();

    // DESCRIZIONE NEL FILE .cpp
    string metodo3();

    // DESCRIZIONE NEL FILE .cpp
    int metodo4();

    
    
    inline bool aggiungi(Vincitore v) {vincitori.push_back(v); return true;}
    
    
    inline list<Vincitore>& getContent() { return vincitori; }
};
#endif
