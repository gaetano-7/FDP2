//Calcolo della potenza tramite funzione
//Scrivere una funzione che ricevuti due numeri a e b calcoli la potenza a^b

#include <iostream>
using namespace std;

int potenza(int, int);

int main(){

	int a, b;
	cout << "inserisci la base: ";
	cin >> a;
	
	cout << "inserisci l'esponente: ";
	cin >> b;
	
	cout << "il risultato di " << a << "^" << b << " è " << potenza(a,b) << endl;
}

int potenza(int x,int y){
	int risultato = 1;
	for(int i = 1; i <= y; i++)
		risultato *= x;
	return risultato;

}
