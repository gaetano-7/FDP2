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

        string esercizio3(const Grafo& g, int k1, int k2) {
            vector<vector<int>> transfer = {{0,0,3,0},
                                            {1,0,0,0},
                                            {1,0,0,0},
                                            {0,-2,0,0}};

            for (int i = 0; i < n(); i++) {
                for (int j = 0; j < n(); j++) {
                    if(transfer[i][j]>=k1 && transfer[i][j]<=k2){
                        continue;
                    } else {
                        return "NO";
                    }
                }
            }

            vector<int> trans_entr;
            vector<int> trans_usc;
            for (int cont = 0; cont < n(); cont++) {
                int somma_entr = 0;
                for (int i = 0; i < n(); i++) {
                    if (i != cont && transfer[i][cont] != 0) {
                        somma_entr += transfer[i][cont];
                    }
                }
                trans_entr.push_back(somma_entr);

                int somma_usc = 0;
                for (int j = 0; j < n(); j++) {
                    if (j != cont && transfer[cont][j] != 0) {
                        somma_usc += transfer[cont][j];
                    }
                }
                trans_usc.push_back(somma_usc);
            }

            vector<int> gradi_entr;
            for (int cont = 0; cont < n(); cont++) {
                int grado = 0;
                for (int j = 0; j < n(); j++) {
                    if (j != cont && archi[j][cont] == 1) {
                        grado += 1;
                    }
                }
                gradi_entr.push_back(grado);
            }   
        
            for(int i = 0; i < gradi_entr.size(); i++){
                if(gradi_entr[i]%2==0){
                    if(trans_entr[i] <= trans_usc[i]){
                        continue;
                    } 
                    else{
                        return "NO";
                    }
                }
                else {
                    if(trans_entr[i] >= trans_usc[i]){
                        continue;
                    } 
                    else{
                        return "NO";
                    }
                }
            }
            return "YES";
        }    
};

int main(){
    Grafo g(4); // crea un oggetto Grafo con 5 nodi

    g(0, 2, true);
    g(1, 0, true);
    g(1, 3, true);
    g(2, 0, true);
    g(3, 1, true);

    g.stampaGrafo(g);
    g.stampaMatriceAdiacenza();

    cout<<g.esercizio3(g,-3,3);

}