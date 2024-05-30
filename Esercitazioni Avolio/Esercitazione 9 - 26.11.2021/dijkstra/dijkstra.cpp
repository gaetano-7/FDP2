#include <iostream>
#include <limits>
#include <list>
#include "grafoPesato.h"
using namespace std;

void printPath(int nodo, vector<int> pie);
unsigned extractMin(list<unsigned>& Q, const vector<unsigned>& d);
vector<unsigned> dijkstra(const GrafoPesato& g, const unsigned& x);

int main() {
    GrafoPesato g(9);
    g(0,1,true,1); g(0,2,true,1); g(0,4,true,2);
    g(1,3,true,2); g(1,8,true,8);
    g(2,4,true,3);
    g(3,4,true,1); g(3,5,true,1);
    g(4,6,true,2); g(4,8,true,5);
    g(5,8,true,2);
    g(6,3,true,4); g(6,7,true,2);
    g(7,5,true,3); g(7,8,true,1);

    vector<unsigned> shortestPath = dijkstra(g, 0);
    cout << "Costo del cammino minimo da 0 a 8: " << shortestPath[8] << '\n'; // costo del cammino minimo verso y

    return 0;
}

unsigned extractMin(list<unsigned>& Q, const vector<unsigned>& d) {
    // itero su Q e cerco il nodo con il valore di d più piccolo possibile
    unsigned min_val = numeric_limits<unsigned>::max();
    // il puntatore al nodo con valore d minore
    list<unsigned>::iterator minVertexPointer;
    for (auto it = Q.begin(); it != Q.end(); ++it)
        if (min_val > d[*it]) {
            min_val = d[*it];
            minVertexPointer = it;
        }
    // minVertexPointer è il puntatore al nodo con valore d più piccolo
    // lo estraggo da Q
    unsigned nodoMin = *minVertexPointer;
    Q.erase(minVertexPointer);

    return nodoMin;
}

// calcola il costo dei cammini minimi da x verso tutti gli altri nodi di g
vector<unsigned> dijkstra(const GrafoPesato& g, const unsigned& x) {
    // d = distanza del cammino minimo verso un certo nodo
    vector<unsigned> d(g.n(), numeric_limits<unsigned>::max()); // unsigned max

    // π = predecessore di un certo nodo
    vector<int> pie(g.n(), -1);

    list<unsigned> S; // insieme dei nodi visitati
    list<unsigned> Q; // insieme dei nodi ancora da visitare

    // tutti i nodi stanno inizialmente dentro Q
    for (unsigned u = 0; u < g.n(); ++u)
        Q.push_back(u);

    // il costo del cammino minimo da x verso x è 0
    d[x] = 0;

    while (!Q.empty()) {
    
        // cerca il nodo con d minore, e lo estrae da Q
        unsigned u = extractMin(Q, d);
        S.push_back(u);

        for (unsigned v = 0; v < g.n(); ++v)
            if (u != v && g(u,v))
                if (d[v] > d[u] + g.w(u,v)) { // se il costo corrente per arrivare a v è maggiore del costo per arrivare a u + il peso dell'arco tra u e v, allora aggiorna
                    d[v] = d[u] + g.w(u,v); // aggiorno il costo corrente di v
                    pie[v] = u;             // il predecessore di v è ora u
                }
    }

    printPath(8, pie);
    
    // il costo dei cammini minimi da x verso tutti gli altri nodi
    return d;
}

void printPath(int nodo, vector<int> pie){

    cout << "path per raggiungere: " << nodo << endl;
    string path = to_string(nodo);

    while(pie[nodo] != -1){
        path = to_string(pie[nodo]) + " -> " + path;
        nodo = pie[nodo];
    }
    cout << path << endl;
    
}

