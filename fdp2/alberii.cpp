#include <iostream>
using namespace std;

int main(){
    a.nullo() // -> radice non ha figli
    a.foglia() // -> nodo senza figli, cioè l'ultimo
    svuota() // -> cancella tutti i nodi
    annulla() //svuota l'albero senza cancellare i nodi
    a.radice() // valore dentro il nodo
    padre() // restituisce il padre

    //  restituisci il cammino dal nodo radice dell’albero
    // al nodo foglia contenente il valore informativo x.
    vector<int> esercizio3(const AlberoB<int>&a, int x, vector<int> lista){
        if(a.nullo()){
            return {-1};
        }
        if(a.foglia()){
            if(a.radice()==x){
                lista.push_back(a.radice());
                return lista;
            }
        }
        else{
            lista.push_back(a.radice());
        }
        auto risultato_sin = esercizio3(a.figlio(SIN),x,lista);
        if(risultato_sin[0] != -1){
            return risultato_sin;
        }
        auto risultato_des = esercizio3(a.figlio(DES),x,lista);
        if(risultato_des[0] != -1){
            return risultato_des;
        }
        return {-1};
    }


    // restituisca true se almeno un nodo foglia x tale che la somma dei valori 
    // informativi dei nodi sul percorso dalla radice di T a x è pari a zero
    bool esercizio3(const AlberoB<int>&a, int somma){
        if(a.nullo()){
            return false; // albero nullo
        }
        if(a.foglia()){
            somma+=a.radice();
            if(somma==0){
                return true;
            }
        }
        else{
            somma+=a.radice();
        }
        bool risultato_sin = esercizio3(a.figlio(SIN),somma);
        if(risultato_sin){
            return risultato_sin;
        }
        auto risultato_des = esercizio3(a.figlio(DES),somma);
        if(risultato_des){
            return risultato_des;
        }
        return true;
    }
}