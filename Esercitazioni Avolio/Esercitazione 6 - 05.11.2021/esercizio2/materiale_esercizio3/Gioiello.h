
#ifndef Gioiello_H_
#define Gioiello_H_

#include <iostream>
#include <string>

using namespace std;


    #include <algorithm>
    #include <cmath>
    #include <climits>
    enum Tipo { ANELLO = 0, BRACCIALE, COLLANA, ORECCHINI, OROLOGIO, ALTRO_TIPO };
    enum Materiale { ACCIAIO = 0, ARGENTO, ORO_BIANCO, ORO_GIALLO, ORO_ROSA, ALTRO_MATERIALE };

    

class Gioiello
{
private:
    string descrizione;
    int prezzo;
    Tipo tipo;
    Materiale materiale;
    
public:
    Gioiello(string _descrizione = "", int _prezzo = 20, Tipo _tipo = ALTRO_TIPO, Materiale _materiale = ALTRO_MATERIALE) : descrizione(_descrizione), prezzo(_prezzo), tipo(_tipo), materiale(_materiale) {}

    string getDescrizione() const { return descrizione; }
    void setDescrizione(string v) { descrizione = v; }

    int getPrezzo() const { return prezzo; }
    void setPrezzo(int v) { prezzo = v; }

    Tipo getTipo() const { return tipo; }
    void setTipo(Tipo v) { tipo = v; }

    Materiale getMateriale() const { return materiale; }
    void setMateriale(Materiale v) { materiale = v; }

    

    bool operator==(const Gioiello& right) const { return descrizione == right.descrizione && prezzo == right.prezzo && tipo == right.tipo && materiale == right.materiale; }

friend ostream& operator<<(ostream& out, const Gioiello& x) { return out << "[" << x.descrizione << ", " << x.prezzo << ", " << x.tipo << ", " << x.materiale << "]"; }
};

#endif
