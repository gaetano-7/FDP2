#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
using namespace std;

class Persona{
    friend istream &operator>>(istream &in, Persona &v){
        in>>v.nome;
        in>>v.cognome;
        return in;
    }
    friend ostream &operator<<(ostream &out, const Persona &v){
        out<<v.nome;
        out<<v.cognome;
        return out;
    }
    private:
        string nome;
        string cognome;
    public:
        string getNome() const {return nome;}
        string getCognome() const {return cognome;}

        bool operator==(const Persona &v) const {
            return v.nome == nome && v.cognome == v.cognome;
        }
};

#endif