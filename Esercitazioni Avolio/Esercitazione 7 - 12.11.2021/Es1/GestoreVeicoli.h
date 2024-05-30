#ifndef GESTORE_VEICOLI_H
#define GESTORE_VEICOLI_H

#include "Veicolo.h"
#include "Automobile.h"
#include "Moto.h"
#include <list>

class GestoreVeicoli{
    public:
        void aggiungiAutomobile(string t, float p, string c, string n){
            Veicolo* a = new Automobile(t, p, c, n);
            aggiungiVeicolo(a);
        }

        void aggiungiMoto(string t, float p, string c, string n){
            Veicolo* m = new Moto(t, p, c, n);
            aggiungiVeicolo(m);
        }

        Veicolo* getVeicolo(string targa){
            for(auto it = veicoli.begin(); it != veicoli.end(); it++)
                if((**it).getTarga() == targa)
                    return *it;

            return nullptr; // il veicolo con targa pari a 'targa' non esiste
        }

        //distruttore
        ~GestoreVeicoli(){
            clear();
        }

        GestoreVeicoli& operator=(const GestoreVeicoli& v){
            if(this != &v){
                clear();
                for(auto it = v.veicoli.begin(); it != v.veicoli.end(); it++){
                    veicoli.push_back((**it).clone());
                }
            }

            return *this;
        }

        GestoreVeicoli(const GestoreVeicoli& v){
            for(auto it = v.veicoli.begin(); it != v.veicoli.end(); it++){
                veicoli.push_back((**it).clone());
            }
        }

    private:
        void aggiungiVeicolo(Veicolo* v){
            for(auto it = veicoli.begin(); it != veicoli.end(); it++)
                if((**it).getTarga() == (*v).getTarga())
                    return;

            veicoli.push_back(v);
        }
       
        void clear(){
            while(!veicoli.empty()){
                delete veicoli.back();
                veicoli.pop_back();
            }
        }

        list<Veicolo*> veicoli;
};

#endif