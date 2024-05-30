#include <iostream>
using namespace std;

int main(){

    //backtracking
    bool esercizio4(vector<string>V, vector<vector<string>>C){
        vector<vector<string>> sottoinsiemi; 
        vector<string> stt_insieme; 
        stack<pair<int, vector<string>>> s; 
        s.push({0, stt_insieme});

        while(!s.empty()){
            pair<int, vector<string>> top = s.top();
            int index = top.first;
            vector<string> stt_insieme = top.second;
            s.pop();
            sottoinsiemi.push_back(stt_insieme);

            for(int i = index; i < V.size(); i++){
                stt_insieme.push_back(V[i]);
                s.push({i+1,stt_insieme});
                stt_insieme.pop_back();
            }
        }
    }

    //backtracking grafo
    bool esercizio4(const Grafo& g, int k1, int k2){
        vector<int> nodi;
        for(int i = 0; i < g.n(); i++){
            nodi.push_back(i);
        }
        
        vector<vector<int>> sottoinsiemi;
        vector<int> stt_insieme;
        stack<pair<int,vector<int>>> s;
        s.push({0,stt_insieme});

        while(!s.empty()){
            pair<int,vector<int>> top = s.top();
            int index = top.first;
            vector<int> stt_insieme = top.second;
            s.pop();
            sottoinsiemi.push_back(stt_insieme);
            for(int i = index; i < nodi.size(); i++){
                stt_insieme.push_back(nodi[i]);
                s.push({i+1,stt_insieme});
                stt_insieme.pop_back();
            }
        }
    }

    // P ha almeno q stringhe,
    // Non esiste una lista l in L tale che tutte le sue stringhe sono contenute in P.
    string att;
    int cont = 0;
    for(int i = 0; i < sottoinsiemi.size(); i++){
        if(sottoinsiemi[i].size() >= q){
            for(int j = 0; j < sottoinsiemi[i].size(); j++){
                for(int x = 0; x < L.size(); x++){
                    for(int y = 0; y < L[x].size(); y++){
                        att = L[x][y];
                        for(int k = 0; k < sottoinsiemi[i].size(); k++){
                            if(sottoinsiemi[i][k]==att){
                                cont++;
                            }
                        }
                    }
                    cont = 0;
                }
                if(cont < q){
                    return true;
                }
                cont = 0;
            }    
        }    
    }
    return false;

}