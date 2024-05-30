#ifndef STUDENTE_H_
#define STUDENTE_H_

#include <string>
#include <iostream>
using namespace std;

class Studente{

    friend ostream& operator<<(ostream& out, const Studente& s){
        //IMPLEMENTARE
    }
    friend istream& operator>>(istream& out, Studente& s){
        //IMPLEMENTARE
    }

private:
    string matricola;
    unsigned eta;

    string nomi_esami[24];
    unsigned voti_esami[24];
    unsigned cfu_esami[24];

    unsigned esami_sostenuti;

public:

    Studente(){
        matricola = "";
        eta = 0;
        esami_sostenuti = 0;
    }

    Studente(string matricola, unsigned eta){
        this->matricola = matricola;
        this->eta = eta;
        esami_sostenuti = 0;
    }

    string getMatricola() const{ return matricola;}
    unsigned getEta() const{return eta;}
    unsigned getEsamiSostenuti() const{return esami_sostenuti;}

    void setMatricola(string matricola){this->matricola = matricola;}
    void setEta(unsigned eta){this->eta = eta;}
    void setEsamiSostenuti(unsigned e_s){esami_sostenuti = e_s;}

    void aggiungiEsame(string esame, unsigned voto, unsigned cfu){
        if(esami_sostenuti < 24){
            nomi_esami[esami_sostenuti] = esame;
            voti_esami[esami_sostenuti] = voto;
            cfu_esami[esami_sostenuti] = cfu;

            esami_sostenuti++;
        }
    }

    void rimuoviUltimoEsame(){
        if(esami_sostenuti > 0){
            esami_sostenuti --;
        }

    }

    unsigned getVotoPiuBasso() const{
        //IMPLEMENTARE
    }


    unsigned getVotoPiuAlto() const{
        //IMPLEMENTARE
    }

    float getMediaVoti() const{
        //IMPLEMENTARE
    }

    float getMediaPonderata() const{
        if(esami_sostenuti == 0) return 0;

        float somma = 0;
        int sommaCfu = 0;

        for(int i = 0; i < esami_sostenuti; i++){
            somma += voti_esami[i] * cfu_esami[i];
            sommaCfu += cfu_esami[i];
        }

        return somma / sommaCfu;
    }

    unsigned getVotoI(unsigned i) const{
        return voti_esami[i];
    }
};

#endif