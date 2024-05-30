#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isSubsetCoverPossible(const vector<int>& S, const vector<vector<int>>& C, int k) {
    int n = C.size();
    int m = S.size();

    // Creazione di una mappa per tenere traccia del numero di volte che ogni elemento di S appare negli insiemi Ci
    unordered_map<int, int> elementCount;

    // Conteggio delle occorrenze degli elementi di S negli insiemi Ci
    for (const auto& set : C) {
        for (int element : set) {
            if (elementCount.find(element) != elementCount.end()) {
                elementCount[element]++;
            } else {
                elementCount[element] = 1;
            }
        }
    }

    // Verifica se è possibile generare un insieme S* con almeno k elementi
    for (const auto& element : S) {
        if (elementCount[element] < k) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<int> S = {1, 2, 3, 4, 5};
    vector<vector<int>> C = {{1, 2, 3}, {1, 3, 4}, {1, 4, 5}};
    int k = 2;

    bool isPossible = isSubsetCoverPossible(S, C, k);

    cout << std::boolalpha; // Stampa "true" o "false" al posto di "1" o "0"
    cout << isPossible << endl;

    return 0;
}

