#include <iostream>
#include <queue>
using namespace std;

#include "Cliente.h"

void stampaMenu();
void stampa(queue<Cliente> c);

int main(){
    queue<Cliente> coda;
    char scelta;

    unsigned incasso_attuale = 0;
    unsigned tempo_trascorso = 0;
    unsigned tempo_attesa = 0;

    do{
        stampaMenu();
        cin >> scelta;
        switch (scelta){
            case '1':
            {
                Cliente c;
                cin >> c;
                coda.push(c);
                tempo_attesa += c.getDurataTrattamento();

                cout << "Cliente inserito" << endl;
                break;
            }
            case '2':
            {
                if(coda.size() > 0){
                    Cliente c = coda.front();
                    cout << "E' stato servito il cliente " << c << endl;
                    coda.pop();

                    incasso_attuale += c.getPrezzo();
                    tempo_trascorso += c.getDurataTrattamento();
                    tempo_attesa -= c.getDurataTrattamento();
                }
                else
                    cout << "Non ci sono clienti in fila" << endl;
                
                break;
            }
            case '3':
            {
                cout << "Orario attuale: "<< ...;
                cout << "Tempo di attesa: " << ...;
                cout << "Prossimo orario disponibile:" << ...;
                break;
            }
            case '4':
            {
                stampa(coda);
                break;
            }
            case '5':
            {
               cout << "Orario attuale: "<< ...; 
               break;
            }
            case '6':
            {
                cout << "Incasso attuale: " << incasso_attuale << " euro" << endl;
                break;
            }
            default:
                cout << "Valore inserito non valido" << endl;
                break;
        }
          
    }while(scelta != '0');

}

string getOrario(int minuti){
    string orario = "";
    /*implementare conversione*/
    //to_string(int)->string 
    return orario;
}

void stampa(queue<Cliente> c){
    if(c.size() > 0){
        while(!c.empty()){
            cout << c.front() << endl;
            c.pop();
        }
    }
    else
        cout << "Non ci sono clienti in coda " << endl;
}

void stampaMenu(){
    cout << "Benvenuti dal parrucchiere. Orario di apertura ore 8:00" << endl;
    cout << "Inserisci 1 per inserire un nuovo cliente" << endl;
    cout << "Inserisci 2 per eseguire il trattamento del prossimo cliente" << endl;
    cout << "Inserisci 3 per chiedere il prossimo orario disponibile" << endl;
    cout << "Inserisci 4 per stampare tutti i clienti in fila" << endl;

    cout << "Inserisci 0 per uscire." << endl;

    cout << "Valore inserito -> ";
}