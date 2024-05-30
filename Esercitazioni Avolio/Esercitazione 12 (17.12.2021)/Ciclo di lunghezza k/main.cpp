#include "grafo.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Soluzione{
    /* ISTANZA */
    Grafo g;
    int dimCiclo;
    /***********/
    
    /* SOLUZIONE */
    vector<int> ciclo;
    /************/

    Soluzione(Grafo& g_i, int dim_i):g(g_i), dimCiclo(dim_i){}
};

void add(int nodo, Soluzione& soluzione){
    soluzione.ciclo.push_back(nodo);
}

void remove(Soluzione& soluzione){
    soluzione.ciclo.pop_back();
}

bool canAdd(int nodo, const Soluzione& soluzione){
    if(soluzione.ciclo.empty()) return true; //se e' il primo elemento posso aggiungerlo sempre

    //se non esiste l'arco, non posso aggiungerlo
    if(!soluzione.g(soluzione.ciclo.back(), nodo))
        return false;
    
    //se lo ho gia' visitato, non posso aggiungerlo
    if(find(soluzione.ciclo.begin(), soluzione.ciclo.end(), nodo) != soluzione.ciclo.end())
        return false;

    //se la size corrente è minore di quella richiesta, allora posso aggiungerlo
    if(soluzione.ciclo.size() < soluzione.dimCiclo)
        return true;
    
    return false;
    
}

bool isComplete(const Soluzione& soluzione){
    return soluzione.ciclo.size() == soluzione.dimCiclo && soluzione.g(soluzione.ciclo.back(), soluzione.ciclo.front());    
}

bool solve(Soluzione& soluzione){
    int nodo = 0;
    while(nodo < soluzione.g.n()){
        if(canAdd(nodo, soluzione)){
            add(nodo, soluzione);

            if(isComplete(soluzione))
                return true;
            
            if(solve(soluzione))
                return true;
            
            remove(soluzione);

            nodo ++;
        } 
        else
            nodo ++;
    }

    return false;
}

int main(){
    Grafo g(5);
    g(0,1,true);
    g(1,3,true); g(1,4,true);
    g(2,1,true);
    g(3,2,true);
    g(4,3,true);

    int dimCiclo = 4;

    Soluzione s(g, dimCiclo);

    if(solve(s)){
        cout << "SOLUZIONE: "<<endl;
        for(int i = 0; i < s.ciclo.size() - 1; i++){
            cout << s.ciclo[i] << " -> " << s.ciclo[i+1] << endl;
        }
        cout << s.ciclo.back() << " -> " << s.ciclo.front() << endl;
    }
    else
        cout << "Non esiste soluzione";
}