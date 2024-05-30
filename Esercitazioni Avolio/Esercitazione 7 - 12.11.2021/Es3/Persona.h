#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
using namespace std;

class Persona{

    friend istream& operator >>(istream& in, Persona& p){
        cout << "Inserisci il nome -> ";
        in >> p.nome;

        cout << "Inserisci il cognome -> ";
        in >> p.cognome;

        cout << endl;

        return in;
    }

    friend ostream& operator <<(ostream& out, const Persona& p){
        out << "Nome: " << p.nome << endl;
        out << "Cognome: " << p.cognome << endl;

        return out; 
    }

    private:
        string nome;
        string cognome;

    public:

        string getNome() const {return nome;}
        string getCognome() const {return cognome;}

        bool operator==(const Persona& v) const{
            return nome == v.nome && cognome == v.cognome;
        }
};
#endif