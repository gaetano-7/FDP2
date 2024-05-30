#include <iostream>
#include <vector>
using namespace std;


bool dfs(const vector<vector<int>>& graph, vector<bool>& visited, int current, int target, int k) {
    if (current == target && k == 0) {
        return true; // Trovato un cammino di lunghezza k che connette il nodo 0 al nodo n - 1
    }

    if (k <= 0) {
        return false; // Lunghezza del cammino non corretta
    }

    visited[current] = true;

    for (int neighbor : graph[current]) {
        if (!visited[neighbor]) {
            if (dfs(graph, visited, neighbor, target, k - 1)) {
                return true; // Trovato un cammino di lunghezza k che connette il nodo 0 al nodo n - 1
            }
        }
    }

    visited[current] = false; // Backtracking

    return false; // Nessun cammino di lunghezza k che connette il nodo 0 al nodo n - 1
}

bool esercizio4(const Grafo& G, int k) {
    int n = G.n();
    vector<vector<int>> graph(n);

    // Costruisci il grafo orientato a partire da G
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G(i, j)) {
                graph[i].push_back(j);
            }
        }
    }

    vector<bool> visited(n, false);
    return dfs(graph, visited, 0, n - 1, k);
}