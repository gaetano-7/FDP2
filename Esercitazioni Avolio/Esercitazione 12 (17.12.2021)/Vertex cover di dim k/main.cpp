#include "grafoNonOrientato.h"
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

struct Soluzione{
    /* ISTANZA */
    GrafoNonOrientato g;
    int dim_target;
    /**********/

    /* SOLUZIONE */ 
    vector<int> rimossi;
    /************/

    Soluzione(GrafoNonOrientato& g_i, int dim_i):g(g_i), dim_target(dim_i){}

};

void add(int nodo, Soluzione& soluzione){
    soluzione.rimossi.push_back(nodo);
}

void remove(Soluzione& soluzione){
    soluzione.rimossi.pop_back();
}

bool canAdd(int nodo, const Soluzione& soluzione){
    if(find(soluzione.rimossi.begin(), soluzione.rimossi.end(), nodo) != soluzione.rimossi.end())
        return false;

    if(soluzione.g.n() - soluzione.rimossi.size() - 1 < soluzione.dim_target)
        return false;

    for(int i = 0; i < soluzione.g.n(); i++){
        if(soluzione.g(nodo, i) && find(soluzione.rimossi.begin(), soluzione.rimossi.end(), i) != soluzione.rimossi.end())
            return false;    
    }
    return true;
    
}

bool isComplete(const Soluzione& soluzione){
    return soluzione.g.n() - soluzione.rimossi.size() == soluzione.dim_target;
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
            nodo++;
        }
        else
            nodo ++;
    }

    return false;
}