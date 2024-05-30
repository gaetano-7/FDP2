//LOGARITMO INTERO
//calcolo del logaritmo intero

//log_3 9 = 2
//log_2 8 = 3
//log_2 6 = 2,... -> 2

#include <iostream>
using namespace std;

//Calcola il logaritmo intero in base b di a
int log_int(int a, int b);

int main(){

	int a, b;
	cout << "inserisci la base del log: "; cin >> b;

	cout << "inserisci il numero: "; cin >> a;

	cout << "il log intero di " << a << " in base " << b << " è pari a " << log_int(a, b) << endl;
	return 0;
}

int log_int(int a, int b){

	int cont = 0, potenza = 1;

	while(potenza <= a){

		potenza *= b;
		cont++;	
	}

	cont--;
	return cont;
	// al posto delle due righe precedenti potrei scrivere solo return cont - 1
}











