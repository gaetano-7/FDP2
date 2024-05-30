#include <iostream>
using namespace std;

const int n = 5;

void leggiMatrice(int M[][n]);
void calcolaSottomatriceMassimaUguale(int M[][n]);
bool controllaSottoMatrice(int M[][n], int i, int j, int dim);

int main(){

	
	int M[n][n];


	leggiMatrice(M);

	calcolaSottomatriceMassimaUguale(M);

	return 0;
}

void leggiMatrice(int M[][n]){

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> M[i][j];
}

void calcolaSottomatriceMassimaUguale(int M[][n]){
	bool sottoMatriceTrovata = false;

	for(int dim = n; dim >= 1 && !sottoMatriceTrovata; dim--)
		for(int i = 0; i <= n-dim && !sottoMatriceTrovata; i++)
			for(int j = 0; j <= n-dim && !sottoMatriceTrovata ; j++){
				if(controllaSottoMatrice(M, i, j, dim)){
					cout << "Dimensione massima di sottomatrice: " << dim << endl;
					cout << "Coordinate del primo punto: [" << i << "," << j << "]" << endl;
					cout << "Valore " << M[i][j] << endl;
					sottoMatriceTrovata = true;
				}
			}

}

bool controllaSottoMatrice(int M[][n], int i, int j, int dim){

	int elem = M[i][j];

	bool trovatoElemDiverso = false;

	for(int a = 0; a < dim && !trovatoElemDiverso; a++)
		for(int b = 0; b < dim && !trovatoElemDiverso; b++)
			if(M[i+a][j+b] != elem)
				trovatoElemDiverso = true;

	if(trovatoElemDiverso)
		return false;
	else 
		return true;

}

/*
1   2   3   4   5
2   2   2   3   1
2   2   2   4   5
2   2   2   1   3
3   4   1   5   6
*/