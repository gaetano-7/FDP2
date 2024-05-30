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

        void esercizio3(const Grafo& g) {
            vector<int> potenziale = {5,3,6,1,2};

            vector<int> media;
            for(int i = 0; i < n(); i++){
                int somma=0;
                int cont=0;
                for(int j = 0; j < n(); j++){
                    if(archi[i][j]==1){
                        cont++;
                        somma+=potenziale[j];
                    }
                }
                media.push_back(somma / 2);
            }

            vector<int> stato;
            for(int i = 0; i < media.size(); i++){
                if(potenziale[i] > media[i]){
                    stato.push_back(1);
                } else stato.push_back(0);
            }

            int max = 0;
            for(int i = 0; i < stato.size(); i++){
                if(stato[i]==1){
                    if(potenziale[i] > max){
                        max = i;
                    }
                }
            }
            cout<<max;
        }    
};

int main(){
    Grafo g(5); // crea un oggetto Grafo con 5 nodi

    g(1, 2, true);
    g(2, 0, true);
    g(0, 3, true);
    g(0, 4, true);

    g.stampaGrafo(g);
    g.stampaMatriceAdiacenza();

    g.esercizio3(g);

}