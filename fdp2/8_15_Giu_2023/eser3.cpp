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

        struct Arco{
            int u;
            int v;
        };

        void esercizio3(const Grafo& g){
            vector<int> w = {1,2,9,5}; // peso nodi
            vector<int> delta; //grado nodi
            int n = g.n();
            float maxP;
            int maxU, maxV;

            // grado dei nodi
            for(int u = 0; u < n; u++){
                int cont = 0;
                for(int v = 0; v < n; v++){
                    if(u != v && archi[u][v]){
                        cont++;
                    }
                }
                delta.push_back(cont);
            }

            for(int u = 0; u < n; u++){
                for(int v = 0; v < n; v++){
                    if(u != v && archi[u][v]){
                        float P = float(w[u] * w[v]) / float(delta[v] + delta[u]);
                        cout<<u<<" "<<v<<" "<<P<<endl;
                        cout<<w[u]<<" "<<w[v]<<" "<<endl;
                        cout<<delta[u]<<" "<<delta[v]<<" "<<endl;
                        cout<<endl;
                        if(P > maxP){
                            maxP = P;
                            maxU = u;
                            maxV = v;
                        }
                    }
                }
            }
            cout<<maxU<<" "<<maxV<<endl;
        } 
};

int main(){
    Grafo g(4); // crea un oggetto Grafo con 5 nodi

    g(0, 1, true);
    g(0, 2, true);
    g(1, 2, true);
    g(2, 3, true);

    g.stampaGrafo(g);
    g.stampaMatriceAdiacenza();

    g.esercizio3(g);

    return 0;

}