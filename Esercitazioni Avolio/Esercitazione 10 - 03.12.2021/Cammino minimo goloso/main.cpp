#include <iostream>
#include <list>
#include <climits>
using namespace std;
#include "grafoPesato.h"
list<int> calcolaCamminoMinimoGoloso(GrafoPesato g, int da, int a);
int sceltaGolosa(GrafoPesato g, int da, vector<bool> visitati);
int main(){

    GrafoPesato g(4);
	g(0,1,true,7);
	g(0,2,true,5);
    g(1,3, true, 4);
    g(2,3,true,10);

    list<int> cammino = calcolaCamminoMinimoGoloso(g, 0, 3);

    if(cammino.empty())
        cout << "Nessuna soluzione trovata" << endl;
    else{
        cout << "SOLUZIONE TROVATA: " << endl;

		int costoTotale = 0;
		for(auto it = cammino.begin(); it != --cammino.end(); it++){
			cout << *it << " -> ";
			costoTotale += g.w(*it, *(next(it,1)));
		}
		
		cout << cammino.back() << endl;
		cout << "COSTO TOTALE: " << costoTotale << endl;

    }
    

}

list<int> calcolaCamminoMinimoGoloso(GrafoPesato g, int da, int a){

    vector<bool> visitati(g.n(), false);
    visitati[da] = true;

    list<int> cammino;
    cammino.push_back(da);

    if(da == a) return cammino;

    do{
        int prossimoNodo = sceltaGolosa(g, da, visitati);
        
        if(prossimoNodo == -1)
            return list<int>();
        
        visitati[prossimoNodo] = true;
        cammino.push_back(prossimoNodo);
        da = prossimoNodo;

    }while(da != a);

    return cammino;

}

int sceltaGolosa(GrafoPesato g, int da, vector<bool> visitati){
    int costoPerSuccessivo = INT_MAX;
    int migliorNodoSuccessivo = -1;

    for(int i = 0; i < g.n(); i++)
        if(!visitati[i] && g(da, i) && g.w(da, i) < costoPerSuccessivo){
            costoPerSuccessivo = g.w(da, i);
            migliorNodoSuccessivo = i;
        }

    return migliorNodoSuccessivo;

}
