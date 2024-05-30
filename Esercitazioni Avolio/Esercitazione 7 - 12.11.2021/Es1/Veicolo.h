#ifndef VEICOLO_H
#define VEICOLO_H
#include <iostream>
#include <string>
using namespace std;

class Veicolo{

    friend ostream& operator <<(ostream& out, const Veicolo& v){
        return v.print(out);
    }

    public: 
        Veicolo(string t, float p, string c, string n): targa(t), prezzo(p), casaProduttrice(c), nomeVeicolo(n){};

        string getTarga() const {return targa;}
        string getCasaProduttrice() const {return casaProduttrice;}
        string getNomeVeicolo() const { return nomeVeicolo;}
        virtual float getPrezzo() const {return prezzo;}
        
        virtual Veicolo* clone() const{ return new Veicolo(*this); }

    protected:
        ostream& print(ostream& out) const{
            out << "[" << targa << "] - " << casaProduttrice << " " << nomeVeicolo << ", " << getPrezzo() << " euro"; 
            return out;
        }

    private:
        string targa;
        float prezzo;
        string casaProduttrice;
        string nomeVeicolo;
};

#endif