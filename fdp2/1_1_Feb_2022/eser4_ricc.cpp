#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// G orientato -> (i,j) != (j,i)
class Grafo {
    protected:
        unsigned vn = 0;    // numero di nodi
        unsigned vm = 0;    // numero di archi

        // matrici di adiacenza
        vector<vector<int>> transfer = {{0,0,3,0},{1,0,0,0},{1,0,0,0},{0,-2,0,0}};
        vector<int> deposito = {6,6,6,4};
        vector<vector<int>> peso = {{0,2,0,0},{0,0,3,1},{0,2,0,2},{0,0,0,0}};
        vector<vector<bool>> archi;     // se esiste un arco (i,j) == true

        // inizializza la matrice di adiacenza
        void init(unsigned n) {
            this->vn = n;
            this->vm = 0;
            this->archi = vector<vector<bool>>(n);
            for(unsigned i = 0; i < n; i++){
                this->archi[i] = vector<bool>(n, false);
            }
        }

    public:

        Grafo(unsigned n) {
            assert(n >= 1);
            this->init(n);
        }

        unsigned grado(unsigned x) const {
            unsigned g = 0;
            for(int i = 0; i < n(); i++){
                if(archi[i][x]){
                    g++;
                }
            }
            return g;
        }

        vector<unsigned> gradi() const {
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

        // inserisce o elimina l'arco(i,j) (a seconda del valore di b)
        void operator()(unsigned i, unsigned j, bool b) {
            assert(i >= 0 && i < this->n() && j >= 0 && j < this->n());
            bool esisteArco = this->archi[i][j];
            if ((!esisteArco && b) || (esisteArco && !b)){
                this->archi[i][j] = b;      // arco i->j
                //this->archi[j][i] = b;    // arco j->i (rende il grafo non orientato)
                if (b){
                    vm++;
                }
                else{
                    vm--;
                }
            }
        }

        unsigned n() const { return vn; }
        unsigned m() const { return vm; }

        // true se l'arco (i,j) esiste, altrimenti false
        bool operator()(unsigned i, unsigned j) const {
            assert(i >= 0 && i < this->n() );
            return this->archi[i][j];
        }

        // elimina tutti gli archi
        void svuota() {
            for (unsigned i = 0; i < this->n(); i++)
                for (unsigned j = 0; j < this->n(); j++) {
                    archi[i][j] = false;
                    //archi[j][i] = false;
                }
            vm = 0;
        }

        void stampaGrafo(const Grafo& G1) {
            cout << "Il numero dei nodi del grafo e': " << n() << endl;

            vector<unsigned> grad_nod = G1.gradi();
            for(int i = 0; i < 5; i++){
                cout << "Il grado del nodo: " << i << "e': " << grad_nod[i] << endl;
            }

            cout << "Il numero di archi del grafo e': " << m() << endl;

            cout << "Gli archi presenti nel grafo sono: " << endl;
            for(int i = 0; i < 6; i++){
                for(int j = 0; j < 6; j++){
                    if(archi[i][j] == true){
                        cout << "{" << i << "," << j << "}" << endl;
                    }
                }
            }
        }

bool Es4( const Grafo &g, int k1, int k2)
{
    vector<int> ins;
    for(int i = 0; i<= g.n(); i++)
    {
        for(int j = 0; j<= g.n(); j++)
        {
            if (archi[i][j])
            {
                ins.push_back(i);
                if (ins.size() >= k1 and ins.size() <= k2)
                {
                    for(auto i : ins)
                    {
                        cout<<i;
                    }
                    return true;
                }    
                break;         
            }
            
        }
    }

    return false;
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

    g.Es4(g, k1, k2);
    return 0;
}