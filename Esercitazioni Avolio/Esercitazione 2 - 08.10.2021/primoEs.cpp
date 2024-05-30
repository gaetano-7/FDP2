//Scrivere una funzione che, data una matrice, determini se tutte le coppie di righe hanno 
//almeno un elemento in comune, anche in colonne diverse.
#include <iostream>
using namespace std;
const int righe = 3;
const int colonne = 2;

bool proprieta(int M[][colonne]);
bool elementoInComune(int M[][colonne], int i, int j);

int main(){
	int M[righe][colonne];
	M[0][0] = 5; M[0][1] = 6;
	M[1][0] = 3; M[1][1] = 5;
	M[2][0] = 2; M[2][1] = 5;

	if(proprieta(M))
		cout << "Ogni coppia di righe ha almeno un elemento in comune";
	else
		cout << "Proprietà non verificata";

	return 0;
}

bool proprieta(int M[][colonne]){
	bool trovataCoppia = false;
	for(int i = 0; i < righe-1 && !trovataCoppia; i++)
		for(int j = i+1; j < righe && !trovataCoppia; j++)
			if(! elementoInComune(M, i, j))
				trovataCoppia = true;
	
	// return !trovataCoppia
	if(trovataCoppia)
		return false;
	else
		return true;

}

bool elementoInComune(int M[][colonne], int i, int j){
	bool trovatoElemenoComune = false;
	for(int s = 0; s < colonne && !trovatoElemenoComune; s++)
		for(int t = 0; t < colonne && !trovatoElemenoComune; t++)
			if(M[i][s] == M[j][t])
				trovatoElemenoComune = true;
	return trovatoElemenoComune;
}