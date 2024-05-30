#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Dato un insieme di numeri interi positivi S = {x1, …, xn} determinare quale sia
// il **più piccolo sottoinsieme** R in S tale che la somma dei numeri
// contenuti in R sia esattamente uguale ad una costante data W.

// Dentro Soluzione io ho due tipi di sol
// soluzione.sol = soluzione corrente generata (<--- valore corrente)
// soluzione.best = soluzione migliore (= più piccola) che ho trovato fino ad ora (<--- min possibile)
struct Soluzione {
    vector<int> sol;
    vector<int> best;


    vector<int> elementi;
    int somma_target;

    Soluzione(vector<int>& el, int st) : elementi(el), somma_target(st) {}
};

void solve(Soluzione& soluzione);
bool canAdd(int x, const Soluzione& soluzione);
void add(int x, Soluzione& soluzione);
bool isComplete(const Soluzione& soluzione);
void remove(Soluzione& soluzione);
bool isBetter(const vector<int>& sol, const vector<int>& best) ;

int main() {
    vector<int> elementi;
    cout << "Inserisci elementi: ";
    int elem; cin >> elem;

    while (elem != -1)
    {
        elementi.push_back(elem);
        cin >> elem;
    }

    int somma_target;
    cout << endl << "Inserisci target: ";
    cin >> somma_target;

    Soluzione sol(elementi, somma_target);
    solve(sol);

    if (sol.best.size() != 0) { // ho trovato una soluzione ed è anche la più piccola possibile
        for (int v: sol.best)
            cout << sol.elementi[v] << ' ';
        cout << '\n';
    }

    return 0;
}
void solve(Soluzione& soluzione) {
    int x = 0;
    while (x < soluzione.elementi.size()) {
        if (canAdd(x, soluzione)) {
            add(x, soluzione);

            if (isComplete(soluzione)) {
                if (isBetter(soluzione.sol, soluzione.best))
                    soluzione.best = soluzione.sol;
            } else
                solve(soluzione);

            remove(soluzione);
            x++;
        } else
            x++;
    }
}

bool canAdd(int x, const Soluzione& soluzione) {
    //controllo se ho gia' usato l'indice x
    for(int y: soluzione.sol)
        if(y == x)
            return false;

    int somma = 0;

    for(int indice: soluzione.sol){
        somma += soluzione.elementi[indice];
    }

    if(somma + soluzione.elementi[x] > soluzione.somma_target)
        return false;
    
    return true;
    
}

void add(int x, Soluzione& soluzione) { soluzione.sol.push_back(x); }

bool isComplete(const Soluzione& soluzione) {
    int somma = 0;
    for(int indice: soluzione.sol)
        somma += soluzione.elementi[indice];
    
    return somma == soluzione.somma_target;
}

void remove(Soluzione& soluzione) { soluzione.sol.pop_back(); }

bool isBetter(const vector<int>& sol, const vector<int>& best) {
    // la prima volta che facciamo questa comparazione best sarà ancora vuota
    return sol.size() < best.size() || best.size() == 0;
}



