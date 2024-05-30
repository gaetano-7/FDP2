#include <iostream>
#include <vector>
using namespace std;

int main(){
    n() // -> numero nodi grafo
    m() // -> numero archi grafo
    archi[i][j]==true // -> true se esiste un arco, false altrimenti

    Grafo g(4); // crea un oggetto Grafo con 4 nodi

    g(0, 1, true);  //  {0,1}    0100
    g(1, 2, true);  //  {1,2}    0011
    g(1, 3, true);  //  {1,3}    0101
    g(2, 1, true);  //  {2,1}    0000
    g(2, 3, true);  //  {2,3}

    // restituisca il numero di nodi in G  
    // che non raggiungono il nodo u
    int f(const Grafo& g, int u){
            int cont = 0;
            for(int i = 0; i < g.n(); i++){
                if(u != i && archi[i][u] == 0){
                    cont++;
                }
            }
            return cont;
        }
    // restituisce il nodo con valore f(u) max
    // ed etichetta(num nodo) minima
    void esercizio3(const Grafo& g){
        int max_f_u = 0;
        for(int i = 0; i < g.n(); i++){
            if((g,i) > max_f_u && i <= max_f_u){
                max_f_u = i;
            }
        }
        cout<<max_f_u<<endl;
    }

    /* Il valore di ogni transfer deve essere almeno k1 e al più k2;
       Per ogni nodo con grado (n. di archi) di entrata pari, la somma dei transfer entranti in un nodo non
       può essere maggiore della somma dei transfer uscenti dallo stesso nodo.
       Per ogni nodo con grado (n. di archi) di entrata dispari, la somma dei transfer entranti in un nodo
       non può essere minore della somma dei transfer uscenti dallo stesso nodo*/
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

    // La funzione deve ritornare il nodo con stato pari a 1 e con il
    // potenziale più alto
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

    // La somma dei pesi degli archi entranti in v è minore del suo deposito, e
    // Il deposito di ogni nodo avente un arco entrante in v è maggiore o uguale al deposito di v
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

    // Per ogni nodo u di G, la somma dei pesi dei nodi verso i quali esiste un arco uscente da u 
    // è maggiore o uguale alla somma dei pesi dei nodi a partire dai quali esiste un arco entrante in u.
    string esercizio3(const Grafo& g) {
            vector<int> W = {6,6,6,4};
            vector<int> pesi_entr;
            for(int i = 0; i < n(); i++){
                int somma = 0;
                for(int j = 0; j < n(); j++){
                    if (archi[j][i] == 1){
                        somma+=W[j];
                    }
                }
                pesi_entr.push_back(somma);
            }

            vector<int> pesi_usc;
            for(int i = 0; i < n(); i++){
                int somma = 0;
                for(int j = 0; j < n(); j++){
                    if (archi[i][j] == 1){
                        somma+=W[j];
                    }
                }
                pesi_usc.push_back(somma);
            }

            for(int i = 0; i < n(); i++){
                if (pesi_usc[i] >= pesi_entr[i]){
                    continue;
                }
                else{
                    return "false";
                }    
            }
            return "true";
        }  

        // restituisci arco con la massima quantità della formula
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

}