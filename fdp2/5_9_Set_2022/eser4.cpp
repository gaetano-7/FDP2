#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <stack>
#include <map>

bool esercizio4(vector<string>V, vector<vector<string>>T, int k){
    // Variabile per salvare tutti i sottoinsiemi generati
    vector<vector<string>> sottoinsiemi; 
    // Variabile temporanea per costruire un sottoinsieme
	vector<string> stt_insieme; 
    // Stack per il backtracking
	stack<pair<int, vector<string>>> s; 
    // Inizializza lo stack con l'insieme vuoto
	s.push({0, stt_insieme});

	while(!s.empty()){
		pair<int, vector<string>> top = s.top();
		int index = top.first;
		vector<string> stt_insieme = top.second;
		s.pop();
        // Aggiunge il sottoinsieme corrente alla lista di sottoinsiemi
		sottoinsiemi.push_back(stt_insieme);

		for(int i = index; i < V.size(); i++){
            // Aggiunge un elemento al sottoinsieme corrente
			stt_insieme.push_back(V[i]);
            // Salva la coppia (indice successivo, sottoinsieme attuale) nello stack
			s.push({i+1,stt_insieme});
            // Rimuove l'elemento aggiunto per provare combinazioni diverse
			stt_insieme.pop_back();
		}
	}

    //------------------------------------

    // Conta quante volte un elemento del sottoinsieme appare in un insieme di T
    int cont = 0; 
    // Variabile per verificare se un sottoinsieme soddisfa i criteri
    int check; 
    // Variabile temporanea per un elemento di T
    string cor; 

    for (int i = 0; i < sottoinsiemi.size(); i++) {
        // Verifica che il sottoinsieme abbia almeno k elementi
        if (sottoinsiemi[i].size() >= k) { 
            // Itera su ogni insieme in T
            for (int j = 0; j < T.size(); j++) { 
                // Itera su ogni elemento dell'insieme corrente
                for (int p = 0; p < T[j].size(); p++) { 

                    cor = T[j][p];      // Elemento corrente di T

                    // Itera su ogni elemento del sottoinsieme
                    for (int k = 0; k < sottoinsiemi[i].size(); k++) { 
                        // Se l'elemento corrente di T è presente nel sottoinsieme
                        if (cor == sottoinsiemi[i][k]) { 
                            cont++;
                        }
                    }
                }

                // Se il numero di elementi coincidenti è uguale alla dimensione del sottoinsieme
                if (cont == sottoinsiemi[i].size()) { 

                    check++;    // Incrementa il conteggio di sottoinsiemi validi
                }
                cont = 0;       // Reimposta il contatore per l'insieme successivo di T
            }

            // Se non ci sono sottoinsiemi validi per l'insieme corrente di V
            if (check == 0) { 
                return true;    // Restituisce true
            }
            check = 0;  // Reimposta il conteggio per il sottoinsieme successivo di V
        }
    }
    return false;
}

int main(){
    vector<string> V = {"a","b","c","d","e","f","g","h"};

    vector<vector<string>> T = {{"a","b","f","c",},
                                {"b","h","d"},
                                {"b","a","c"},
                                {"d","h"},
                                {"e","f","g","h"}};
    int k = 2;
    
    bool result = esercizio4(V,T,k);

    if(result==1) cout<<"true";
    else cout<<"false";

    return 0;
}