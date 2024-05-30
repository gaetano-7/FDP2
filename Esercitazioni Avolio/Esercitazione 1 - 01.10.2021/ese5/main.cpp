//ISTOGRAMMI

//stampa degli istogrammi relativi ad una sequenza di numeri terminata da un numero negativo
/*
	INPUT: 3 4 1 0 2 -1

	OUTPUT:
	***
	****
	*

	**

*/
#include <iostream>
using namespace std;

void stampa_istogramma(int val);

int main(){

	int num;
	cin >> num;

	while(num >= 0){
		stampa_istogramma(num);
		cin >> num;
	}

	return 0;
}

void stampa_istogramma(int val){

	if(val >= 0){ //controllo superfluo ai fini del programma in quanto già nel main ci assicuriamo che i numeri siano >= 0.
		for(int i = 0; i < val; i++)
			cout << "*";

		cout << "\n";
	}
}
