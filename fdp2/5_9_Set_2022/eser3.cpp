#include <iostream>
#include <vector>
#include <cassert>
#include <utility>
using namespace std;

class Grafo{
    public:
        unsigned vn = 0; //numero di nodi
        unsigned vm = 0; //numero di archi

        
        //vector<vector<bool>> (i,j) == true => esiste un arco da i verso j
        vector<vector<bool>> archi; 
        
        void init(unsigned n){ 
            this->vn = n; // assegna il valore n ad vm. cioè il numero di nodi
            this->vm = 0;

            // vettore di bool con n elementi
            this->archi = vector<vector<bool>>(n); 
            for(unsigned i = 0; i < n; i++){
                // inizializza ogni elemento del vettore con 
                // n valori bool impostati a false
                this->archi[i] = vector<bool>(n,false);
            }
        }

        Grafo(unsigned n){
            assert(n>=1);
            this->init(n); // inizializza la classe grafo con n nodi
        }

        void operator()(unsigned i,unsigned j,bool b){
            assert(i >= 0 && i < this->n() && j >= 0 && j < this->n());
            bool esisteArco = this->archi[i][j];
            if((!esisteArco && b) or (esisteArco && !b)){
                this->archi[i][j] = b; // imposta l'arco i->j con il valore b
                //this->archi[j][i] = b; //arco j->i (rende il grafo non orientato)
                if (b){
                    vm++; // se l'arco è stato inserito, incrementa il numero di archi
                }
                else{
                    vm--; // se l'arco è stato eliminato, decrementa il numero di archi
                }
            }
        }

        unsigned n() const {return vn;} // restituisce il numero di nodi del grafo
        unsigned m() const {return vm;} // restituisce il numero di archi del grafo

        //true se l'arco (i,j) esiste, altrimenti false
        bool operator()(unsigned i, unsigned j) const{
            assert(i >= 0 && i < this->n() && j >= 0 && j < this->n());
            return this->archi[i][j];
        }

        void stampaGrafo(const Grafo& G1){
            cout<<"il numero dei nodi del grafo e': "<<n() <<endl;

            cout<<"Il numero di archi del grafo e': "<<m()<<endl;

            cout<<"Gli archi presenti nel grafo sono: "<<endl;
            for(int i = 0; i < n(); i++){
                for(int j = 0; j < n(); j++){
                    if(archi[i][j]==true){ // se l'arco i->j esiste, stampa "{i,j}"
                        cout<<"{"<<i<<","<<j<<"}"<<endl;
                    }
                }
            }
        }

        void stampaMatriceAdiacenza(){
            for(int i = 0; i < n(); i++){
                for(int j = 0; j < n(); j++){
                    cout<<archi[i][j];
                }
                cout<<endl;
            }
        }

        string esercizio3(const Grafo& g) {
            vector<int> deposito = {6,6,6,4};
            vector<vector<int>> transfer = {{0,2,0,0},
                                            {0,0,3,1},
                                            {0,2,0,2},
                                            {0,0,0,0}};
            vector<int> pesi_entr;
            for(int i = 0; i < n(); i++){
                int somma = 0;
                for(int j = 0; j < n(); j++){
                    if (archi[j][i] == 1){
                        somma+=transfer[j][i];
                    }
                }
                pesi_entr.push_back(somma);
            }

            for(int i = 0; i < pesi_entr.size(); i++){
                if(pesi_entr[i] < deposito[i]){
                    continue;
                }
                else return "false";
            }

            for(int i = 0; i < n(); i++){
                for(int j = 0; j < n(); j++){
                    if (archi[j][i] == 1){
                        if(deposito[j] >= deposito[i]){
                            continue;
                        }
                        else return "false";
                    }
                }
            }
            return "true";
        }    
};

int main(){
    Grafo g(4); // crea un oggetto Grafo con 4 nodi

    g(0, 1, true);
    g(1, 2, true);
    g(1, 3, true);
    g(2, 1, true);
    g(2, 3, true);

    g.stampaGrafo(g);
    g.stampaMatriceAdiacenza();

    cout<<g.esercizio3(g);

}