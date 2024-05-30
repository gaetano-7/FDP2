//SOMMA E PRODOTTO CON FUNZIONI
//1. somma di due numeri con funzioni
//2. prodotto di due numeri usando la somma

#include <iostream>
using namespace std;

int somma(int, int);
int prodotto(int, int);

int main(){

	cout << "Inserisci i valori" << endl;

	int a, b;
	cin >> a >> b;

	cout << "La somma tra " << a << " e " << b << " vale " << somma(a, b) << endl;
	cout << "Il prodotto tra " <<  a << " e " << b << " vale " << prodotto(a, b) << endl;
}

int prodotto(int x, int y){
	int prodotto = 0;

	for(int i = 0; i < y; i++)
		prodotto = somma(x, prodotto);

	return prodotto;
}


int somma(int x, int y){
	return x + y;
}
