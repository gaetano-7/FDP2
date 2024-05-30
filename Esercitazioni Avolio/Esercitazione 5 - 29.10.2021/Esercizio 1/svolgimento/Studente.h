#ifndef STUDENTE_H_
#define STUDENTE_H_

#include <string>
#include <iostream>
using namespace std;

class Studente{

    friend ostream& operator<<(ostream& out, const Studente& s){
        out << "Matricola: " << s.matricola << "\nEta: " << s.eta <<"\nEsami sostenuti: " << s.esami_sostenuti;
        
        for(int i = 0; i < s.esami_sostenuti; i++)
            out << "Esame: " << s.nomi_esami[i]<< " "<<s.voti_esami[i]<< " " << s.cfu_esami[i] << endl;

        return out;

    }

    friend istream& operator>>(istream& in, Studente& s){
        cout << "Inserisci matricola --> "; string matricola; in >> matricola; s.setMatricola(matricola);
        cout << "Inserisci eta --> "; unsigned eta; in >> eta; s.setEta(eta);
        cout << "Inserisci n. esami sostenuti --> "; unsigned esami_sostenuti; in >> esami_sostenuti;

        for(int i = 0; i < esami_sostenuti; i++)
        {
            string nome;
            unsigned voto;
            unsigned cfu;
            
            cout << "Inserisci nome esame " << (i+1) << endl;
            in >> nome;
            
            cout << "Inserisci voto esame " << (i+1) << endl;
            in >> voto;

            cout << "Inserisci cfu esame " << (i+1) << endl;
            in >> cfu;

            s.aggiungiEsame(nome, voto, cfu);
        }

        return in;
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
        if(esami_sostenuti == 0) return 0;

        unsigned voto_piu_basso = voti_esami[0];

        for(int i = 1; i < esami_sostenuti; i++)
            if(voti_esami[i] < voto_piu_basso)
                voto_piu_basso = voti_esami[i];
        
        return voto_piu_basso;
    }


    unsigned getVotoPiuAlto() const{
        if(esami_sostenuti == 0) return 0;

        unsigned voto_piu_alto = voti_esami[0];

        for(int i = 1; i < esami_sostenuti; i++)
            if(voti_esami[i] > voto_piu_alto)
                voto_piu_alto = voti_esami[i];
        
        return voto_piu_alto;
    }

    float getMediaVoti() const{
        if(esami_sostenuti == 0) return 0;

        float somma = 0;
        for(int i = 0; i < esami_sostenuti; i++)
            somma += voti_esami[i];
        
        return somma / esami_sostenuti;
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