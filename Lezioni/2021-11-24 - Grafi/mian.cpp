#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool esercizio4(vector<string> V, vector<vector<string>> T, int k) {
    int n = V.size();
    vector<unordered_set<string>> trans_set;
    for (auto trans : T) {
        trans_set.push_back(unordered_set<string>(trans.begin(), trans.end()));
    }
    for (int i = 0; i < (1 << n); i++) {
        unordered_set<string> subset;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset.insert(V[j]);
            }
        }
        if (subset.size() < k) continue;
        bool valid = true;
        for (auto trans : trans_set) {
            for (auto elem : subset) {
                if (trans.find(elem) != trans.end()) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }
        if (valid) return true;
    }
    return false;
}

int main() {
    vector<string> V = {"A", "B", "C", "D","E","F","G","H"};
    vector<vector<string>> T = {{"A", "B","F","C"}, {"B", "H","D"}, {"B","A", "C"},{"D","H"},{"E","F","G","H"}};
    int k = 2;
    if (esercizio4(V, T, k)) {
        cout << "Esiste un sottinsieme valido" << endl;
    } else {
        cout << "Non esiste un sottinsieme valido" << endl;
    }
    return 0;
}
