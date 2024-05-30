#ifndef PROGRAMMATORE_H
#define PROGRAMMATORE_H

#include <iostream>
#include <string>
using namespace std;

class Programmatore{

    friend ostream& operator<<(ostream& out, const Programmatore& p);
    friend istream& operator>>(istream& in, Programmatore& p){
        cout << "Inserisci nome --> "; string nome; in >> nome; p.setNome(nome);
        cout << "Inserisci eta --> "; unsigned eta; in >> eta; p.setEta(eta);
        cout << "Inserisci stipendio --> "; unsigned stipendio; in >> stipendio; p.setStipendio(stipendio);
        cout << "Inserisci anni_esperienza --> "; unsigned a_e; in >> a_e; p.setAnniEsperienza(a_e);
        cout << "Inserisci 0 se è junior, 1 se è senior -->"; int isSenior; in >> isSenior; p.setIsSenior(isSenior);
        return in;
    }

private:
    string nome;
    unsigned eta;
    unsigned stipendio;
    unsigned anni_esperienza;
    bool senior;

public:
    string getNome() const;
    unsigned getEta() const {return eta;}
    unsigned getStipendio() const {return stipendio;}
    unsigned getAnniEsperienza() const{return anni_esperienza;}
    bool isSenior() const {return senior;}

    void setNome(string nome){this->nome = nome;}
    void setEta(unsigned eta){this->eta = eta;}
    void setStipendio(unsigned stipendio){this->stipendio = stipendio;}
    void setAnniEsperienza(unsigned a_e){anni_esperienza = a_e;}
    void setIsSenior(bool isSenior){senior = isSenior;}
};
#endif

string Programmatore:: getNome() const{
    return nome;
}

ostream& operator<<(ostream& out, const Programmatore& p){
    out << "Nome: " << p.nome << endl;
    out << "Eta: " << p.eta << endl;
    out << "Stipendio: " << p.stipendio << endl;
    out << "Esperienza: " << p.anni_esperienza << endl;

    if(p.senior)
        out << "Senior: si" << endl;
    else
        out << "Senior: no" << endl;

    return out;

}