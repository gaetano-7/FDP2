#include <iostream>
#include <vector>

using namespace std;

class Grafo {
private:
    int numNodi;
    vector<vector<bool>> adiacenze;

public:
    Grafo(int n) : numNodi(n), adiacenze(n, vector<bool>(n, false)) {}

    int n() const {
        return numNodi;
    }

    int m() const {
        int numArchi = 0;
        for (int i = 0; i < numNodi; i++) {
            for (int j = 0; j < numNodi; j++) {
                if (adiacenze[i][j]) {
                    numArchi++;
                }
            }
        }
        return numArchi;
    }

    bool operator()(int i, int j) const {
        return adiacenze[i][j];
    }

    void addEdge(int i, int j) {
        adiacenze[i][j] = true;
    }
};

bool isSafe(const Grafo& g, int v, const vector<int>& subset) {
    for (int i = 0; i < subset.size(); i++) {
        if (g(subset[i], v)) {
            return false;
        }
    }
    return true;
}

bool backtrack(const Grafo& g, int k1, int k2, int currSize, int currIndex, vector<int>& subset) {
    if (currSize >= k1 && currSize <= k2) {
        return true;  // Trovato un sottoinsieme valido
    }

    if (currSize > k2 || currIndex >= g.n()) {
        return false;  // Sottodimensionato o superdimensionato
    }

    // Prova ad aggiungere il nodo corrente al sottoinsieme
    subset.push_back(currIndex);
    if (isSafe(g, currIndex, subset) && backtrack(g, k1, k2, currSize + 1, currIndex + 1, subset)) {
        return true;
    }
    subset.pop_back();  // Ripristina lo stato precedente

    // Prova ad escludere il nodo corrente dal sottoinsieme
    if (backtrack(g, k1, k2, currSize, currIndex + 1, subset)) {
        return true;
    }

    return false;
}

bool esercizio4(const Grafo& g, int k1, int k2) {
    vector<int> subset;
    return backtrack(g, k1, k2, 0, 0, subset);
}

int main() {
    // Esempio di utilizzo
    Grafo g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    int k1 = 2;
    int k2 = 3;

    if (esercizio4(g, k1, k2)) {
        cout << "Esiste un sottoinsieme U con " << k1 << " <= |U| <= " << k2 << endl;
    } else {
        cout << "Nessun sottoinsieme U soddisfa le condizioni richieste." << endl;
    }

    return 0;
}
