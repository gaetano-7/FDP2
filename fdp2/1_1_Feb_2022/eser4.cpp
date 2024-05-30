#include <iostream>
#include <vector>
#include <cassert>
#include <utility>
#include <stack>
#include <algorithm>
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

        bool esercizio4(const Grafo& g, int k1, int k2){
            vector<int> nodi;
            for(int i = 0; i < g.n(); i++){
                nodi.push_back(i);
            }
            
            vector<vector<int>> sottoinsiemi;
            vector<int> stt_insieme;
            stack<pair<int,vector<int>>> s;
            s.push({0,stt_insieme});

            while(!s.empty()){
                pair<int,vector<int>> top = s.top();
                int index = top.first;
                vector<int> stt_insieme = top.second;
                s.pop();
                sottoinsiemi.push_back(stt_insieme);
                for(int i = index; i < nodi.size(); i++){
                    stt_insieme.push_back(nodi[i]);
                    s.push({i+1,stt_insieme});
                    stt_insieme.pop_back();
                }
            }

            int check = 0;
            int att = 0;
            for(int i = 0; i < sottoinsiemi.size(); i++){
                if(k1 <= sottoinsiemi[i].size() && sottoinsiemi[i].size() <= k2){
                    for(int j = 0; j < sottoinsiemi[i].size(); j++){
                        att = sottoinsiemi[i][j];
                        for(int x = 0; x < g.n(); x++){
                            if(archi[att][j] && archi[j][att]){
                                check++;
                            }
                        }
                    }
                    if(check == 0){
                        return true;
                    }
                    check = 0;
                }
            }
            return false;
        }
};

void esercizio4(const Grafo& g, int k1, int k2){
     

}

int main(){
    Grafo G1(4); // crea un oggetto Grafo con 5 nod

    G1(1, 0, true);
    G1(1, 3, true);
    G1(2, 0, true);
    G1(2, 3, true);

    G1.stampaGrafo(G1);
    G1.stampaMatriceAdiacenza();

    bool result = G1.esercizio4(G1,2,3);
    cout<<boolalpha<<result;

}