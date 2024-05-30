
//https://en.cppreference.com/w/cpp/container/unordered_map
#include <iostream>
#include <unordered_map>
using namespace std;
#include "Persona.h"

struct Hash_Persona{
    size_t operator()(const Persona& p) const{
       size_t h1 = hash<string>{}(p.getNome()); 
       size_t h2 = hash<string>{}(p.getCognome());
       return h1 ^ (h2 << 1);

    }
};

int main(){
    unordered_map<Persona, string, Hash_Persona> rubrica;
    char scelta;
    do{
        stampaMenu();
        cin >> scelta;

        switch (scelta)
        {
            case '1':
            {
                Persona p; cin >> p;
                cout << "Inserisci n. di telefono -> ";
                string n_di_telefono; cin >> n_di_telefono;
                rubrica.insert( {p, n_di_telefono} );
                break;
            }
            case '2':
            {
                Persona p; cin >> p;
                /*
                auto it = rubrica.find(p);
                if(it != rubrica.end())
                    cout << it -> second;
                */

                if(rubrica.find(p) != rubrica.end())
                    cout << "Il numero di telefono di " << p <<  " è " << rubrica[p];
                else
                    cout << "Contatto non presente" << endl;
                break;
            }
            case '3':
            {
                //eliminare contatto
            }
            case '4':
            {
                Persona p; cin >> p;
                
                if(rubrica.find(p) == rubrica.end())
                {
                    cout <<  "Contatto non presente" << endl;
                    break;
                }

                cout << "Inserisci il nuovo numero -> ";
                string n_di_telefono; cin >> n_di_telefono;
                rubrica[p] = n_di_telefono;

                break;
            }
            case '5':
            {
                Persona p; cin >> p;
                if(rubrica.find(p) == rubrica.end()){
                    cout << "Contatto non presente " << endl;
                    break;
                }

                string n_di_telefono = rubrica[p];
                rubrica.erase(p);

                cout << "Inserisci i nuovi dati" << endl;
                cin >> p;
                rubrica.insert( {p, n_di_telefono} );
                break;
            }
            case '6':
            {
                //stampare i contatti
                for(auto it = rubrica.begin(); it!=rubrica.end(); it++){
                    cout << it -> first; // stampa la chiave
                    cout << "Numero di telefono: " << it->second << endl;
                }
            }
            case '7':
            {
                //svuotare rubrica
            }
        default:
            break;
        }

    }while(scelta != '9');

    return 0;
}

void stampaMenu(){

}






