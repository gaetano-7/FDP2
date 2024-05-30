#include <iostream>
#include <vector>
using namespace std;

//si potrebbe implementare mantenendo un vettore di dimensione (somma+1)/2 essendo il vettore possibiliSomme simmetrico
int main()
{
    
 	cout << "Inserisci le monete terminate dal valore -1" << endl;

 	//leggo le monete disponibili
 	vector<int> coins;
 	int coin; cin >> coin;
 	int somma = 0;
 	while(coin != -1){
 		coins.push_back(coin);
 		somma += coin;
 		cin >> coin;
 	}

 	//possibiliSomme[i] = true se e solo se è possibile ottenere i come somma
    bool possibiliSomme[somma + 1] = {false};

    possibiliSomme[0] = true; //inizializzo come somma possibile il valore 0

    for(int coin: coins) {
        for(int j = somma-coin; j >= 0; --j) {
            if (possibiliSomme[j])
                possibiliSomme[j+coin] = true;
        }
    }


    //parto dalla posizione centrale (che darebbe differenza 0) e vado all'indietro (si potrebbe andare anche in avanti, vettore simmetrico)
    bool trovato=false; 
	for(int i = somma/2; i >= 0 && !trovato; --i) 
        if(possibiliSomme[i])
        {
        	cout << "Minima differenza: " << (somma - i) - i << endl; //somma - 2*i
        	trovato=true;
        }

	return 0;
}