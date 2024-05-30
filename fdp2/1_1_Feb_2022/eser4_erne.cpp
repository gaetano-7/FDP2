#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <stack>
#include <map>
#include <iostream>
#include <vector>
#include <cassert>
#include <utility>

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
            this->init(n);
        }

        unsigned grado(unsigned x) const{
            unsigned g = 0;
            for(int i = 0; i < n(); i++){
                if(archi[i][x]){
                    g++;
                }
            }

            return g;
        }

        vector<unsigned> gradi() const{
            vector<unsigned> gs(n(),0);
            for(int i = 0; i < n(); i++){
                for(int j = 0; j < n(); j++){
                    if(archi[i][j]){
                        gs[j]++;
                    }
                }
            }

            return gs;
        }

        //inserisce o elimina l'arco (i,j) (a seconda del valore di b)
        void operator() (unsigned i, unsigned j, bool b){
            assert(i >= 0 && i < this->n() && j >= 0 && j < this->n());
            bool esisteArco = this->archi[i][j];
            if((!esisteArco && b) or (esisteArco && !b)){
                this->archi[i][j] = b; //arco i->j
                this->archi[j][i] = b; //arco j->i (rende il grafo non orientato)
                if(b){
                    vm++;
                }
                else{
                    vm--;
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

        // Funzione backtraking per trovare sottoinsieme
        bool backtrack(const Grafo& g, int k1, int k2, int val, vector<int>& sottoinsiemi) {
            if (sottoinsiemi.size() >= k1 && sottoinsiemi.size() <= k2) {
                return true;
            }

            for (int i = val; i < g.n(); i++) {
                for (int j = 0; j < g.n(); j++) {
                    if (g(i, j) && find(sottoinsiemi.begin(), sottoinsiemi.end(), j) != sottoinsiemi.end()) {
                        return false;
                    }

                    sottoinsiemi.push_back(i);  // aggiunta nodo i al sottoinsieme

                    if (backtrack(g, k1, k2, i+1, sottoinsiemi)) {
                        return true;
                    }
                    
                    sottoinsiemi.pop_back();    // rimuove nodo i dal sottoinsieme
                }
            }

            return false;
        }


        bool esercizio4(const Grafo& g, int k1, int k2) {
            vector<int> sottoinsiemi;
            return backtrack(g, k1, k2, 0, sottoinsiemi);
        }
};

int main() {
    Grafo g(4);

    g(1,0,true);
    g(2,0,true);
    g(1,3,true);
    g(2,3,true);

    int k1 = 2;
    int k2 = 3;

    g.esercizio4(g, k1, k2);
    return 0;
}