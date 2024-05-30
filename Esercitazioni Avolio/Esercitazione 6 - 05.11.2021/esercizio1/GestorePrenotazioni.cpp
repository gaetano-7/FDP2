#include "GestorePrenotazioni.h"
#include <ctime>

GestorePrenotazioni::GestorePrenotazioni(){
    srand(time(0)); // time(0) restituisce il timestamp attuale
}

bool GestorePrenotazioni::esistePrenotazione(int numero){
    for(list<Prenotazione*>::iterator it = prenotazioni.begin(); it != prenotazioni.end(); it++)
    {
        if((**it).getNumero() == numero)
            return true;
    }
    return false;
}

bool GestorePrenotazioni::aggiungiPrenotazione(int posti, string codice){
    for(int i = 0; i < 10; ++i){
        if(codici[i] == codice)
        {
            if(postiTotali[i] >= posti){
                int numeroPrenotazione = rand()%10000;

                while(esistePrenotazione(numeroPrenotazione))
                    numeroPrenotazione = rand()%10000;
                
                Prenotazione* p = new Prenotazione(numeroPrenotazione, posti, codice);
                prenotazioni.push_back(p);
                postiTotali[i] -= posti;
                return true;
            
            } else{
                return false;
            }
        }
    }

    return false;

}

bool GestorePrenotazioni::rimuoviPrenotazione(int numero){
    for(auto it = prenotazioni.begin(); it != prenotazioni.end(); ++it){
        if((**it).getNumero() == numero)
        {
            string codice = (**it).getCodice(); //b0002 -> 1 c0003->2 a0001->0
            int pos = codice[codice.length()-1] - '1';
            if(pos == -1)
                pos = 9;

            postiTotali[pos]+=(**it).getPosti();

            delete *it; //delete-> Passo il puntatore alla prenotazione che voglio eliminare

            prenotazioni.erase(it);
            return true;

        }
    }
    return false;

}

void GestorePrenotazioni::stampaPrenotazioni(string codice)const{
    for(auto it = prenotazioni.begin(); it != prenotazioni.end(); ++it)
        if((**it).getCodice() == codice)
            cout << **it;
  
}

//restituisce true se p1 precede p2
//false altrimenti
bool ordinamento(Prenotazione* p1, Prenotazione* p2){
    if(p1->getCodice()[0] == 'a')
        return true;

    if(p2->getCodice()[0] == 'a')
        return false;
    
    if(p1->getCodice()[0] == 'b')
        return true;
    
    if(p2->getCodice()[0] == 'b')  
        return false;
    
    if(p1->getCodice()[0] == 'c')
        return true;

    if(p2->getCodice()[0] == 'c')
        return false;
    
    return p1->getNumero() < p2->getNumero();

}

void GestorePrenotazioni::ordinaPrenotazioni(){
    prenotazioni.sort(ordinamento);
}

GestorePrenotazioni::~GestorePrenotazioni(){
    for(auto it = prenotazioni.begin(); it != prenotazioni.end(); it++)
        delete *it;
}

GestorePrenotazioni& GestorePrenotazioni::operator=(const GestorePrenotazioni& g){
    if(this != &g){
        for(auto it = prenotazioni.begin(); it != prenotazioni.end(); it++)
            delete *it;
        
        prenotazioni.clear();

        for(auto it = g.prenotazioni.begin(); it != g.prenotazioni.end(); it++)
        {
            Prenotazione* p1 = new Prenotazione((**it).getNumero(), (**it).getPosti(), ((**it).getCodice()));
            prenotazioni.push_back(p1);
        }

        postiTotali = g.postiTotali;
    }

    return *this;
}

GestorePrenotazioni::GestorePrenotazioni(const GestorePrenotazioni& g){
    srand(time(0));
    for(auto it = g.prenotazioni.begin(); it != g.prenotazioni.end(); it++)
    {
        Prenotazione* p1 = new Prenotazione((**it).getNumero(), (**it).getPosti(), ((**it).getCodice()));
        prenotazioni.push_back(p1);
    }

    postiTotali = g.postiTotali;
}




