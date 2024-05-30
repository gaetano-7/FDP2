
#ifndef Gioielleria_H
#define Gioielleria_H

#include "Gioiello.h"

#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*

    Questa classe contiene una lista di gioielli. Ogni gioiello e` caratterizzato dalle seguenti informazioni:

    - descrizione: descrizione del gioiello (stringa);

    - prezzo: il prezzo del gioiello (int);

    - tipo: il tipo del gioiello (ANELLO, BRACCIALE, COLLANA, ORECCHINI, OROLOGIO, ALTRO_TIPO);
    
    - materiale: il materiale del gioiello (ACCIAI0, ARGENTO, ORO_BIANCO, ORO_GIALLO, ORO_ROSA, ALTRO_MATERIALE);
    
    Implementare nel file Gioielleria.cpp i metodi della classe Gioielleria.
    
*/
class Gioielleria   // questa riga e` corretta NON MODIFICARE
{
private:
    list<Gioiello> gioielli;

public:
    // DESCRIZIONE NEL FILE .cpp
    Tipo metodo1();

    // DESCRIZIONE NEL FILE .cpp
    int metodo2();

    // DESCRIZIONE NEL FILE .cpp
    string metodo3();

    // DESCRIZIONE NEL FILE .cpp
    int metodo4();

    
    
    inline bool aggiungi(Gioiello g) {gioielli.push_back(g); return true;}
    
    
    inline list<Gioiello>& getContent() { return gioielli; }
};
#endif
