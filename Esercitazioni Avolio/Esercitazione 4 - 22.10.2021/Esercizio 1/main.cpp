#include "Programmatore.h"
#include <iostream>
#include <cassert>
using namespace std;

const int numero_programmatori = 5;

int main(){

    Programmatore programmatori[numero_programmatori];

    for(int i = 0; i < numero_programmatori; i++){
        cin >> programmatori[i];
    }


}

/*
che, ricevuto in input l'array di programmatori e uno specifico nome, restituisca il numero di programmatori 
presenti nell'array aventi quel nome.*/
unsigned getNumeroProgrammatoriPerNome(Programmatore programmatori[], string nome) {

    unsigned count = 0;

    for(int i = 0; i < numero_programmatori; i++)
        if(programmatori[i].getNome() == nome)
            count ++;

    return count;
}

// restituire lo stipendio medio dei senior
float getStipendioMedioSenior(Programmatore programmatori[]){
    float somma_stipendi = 0;
    unsigned count_senior = 0;

    for(int i = 0; i < numero_programmatori; i++){
        if(programmatori[i].isSenior()){
            somma_stipendi += programmatori[i].getStipendio();
            count_senior++;
        }
    }

    if(count_senior == 0) return 0;

    return somma_stipendi / count_senior;

}

//restituisce il programmatore, non ancora senior, con più anni di esperienza
const Programmatore& getJuniorPiuEsperto(Programmatore programmatori[]){

    unsigned anni_esperienza_max = 0;
    int indice_programmatore = -1;

    for(int i = 0; i < numero_programmatori; i++){
        if(!programmatori[i].isSenior() && programmatori[i].getAnniEsperienza() >= anni_esperienza_max){
            indice_programmatore = i;
            anni_esperienza_max = programmatori[i].getAnniEsperienza();
        }
    }

    assert(indice_programmatore != -1);

    return programmatori[indice_programmatore];
}

//restituisce la differenza d'età tra il più anziano e il più giovane del gruppo
unsigned maxDifferenzaEta_quadratico(Programmatore programmatori[]){

    int diff_max = -1;

    for(int i = 0; i < numero_programmatori; i++)
        for(int j = 0; j < numero_programmatori; j++)
            if(abs(programmatori[i].getEta()-programmatori[j].getEta()) > diff_max)
                diff_max = abs(programmatori[i].getEta()-programmatori[j].getEta());
    
    return diff_max;
}

unsigned maxDifferenzaEta_lineare(Programmatore programmatori[]){

    unsigned max_eta = programmatori[0].getEta();
    unsigned min_eta = programmatori[0].getEta();

    for(int i = 0; i < numero_programmatori; i++){
        if(programmatori[i].getEta() > max_eta)
            max_eta = programmatori[i].getEta();

        if(programmatori[i].getEta() < min_eta)
            min_eta = programmatori[i].getEta();
    }

    return max_eta - min_eta;
}

//restituisce true se e solo se lo stipendio di tutto il gruppo di programmatori rispetta il criterio 
//dell'anzianita e dunque lo stipendio di un programmatore risulta sempre maggiore di quello di tutti 
//i programmatori più giovani di lui
bool anzianita(Programmatore programmatori[]){

    bool anzianita_violata = false;
    for(int i = 0; i < numero_programmatori && !anzianita_violata; i++)
        for(int j = 0; j < numero_programmatori && !anzianita_violata; j++){
            if(programmatori[i].getEta()>programmatori[j].getEta() && programmatori[i].getStipendio() <= programmatori[j].getStipendio())
                anzianita_violata = true;

        }

    return !anzianita_violata; // if(anzianita_violata) return false;
                               // else return true;
}