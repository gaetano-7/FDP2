#include <iostream>
using namespace std;
const int N = 5;
const int K = 3;

void leggiMatriceA(int A[][N]);
void leggiMatriceQ(int Q[][K]);
bool verificaEsisteSimile(int A[][N], int Q[][K]);
bool verificaSimili(int A[][N], int Q[][K], int i, int j);

int main(){
	int A[N][N];
	int Q[K][K];

	leggiMatriceA(A);
	leggiMatriceQ(Q);

	if(verificaEsisteSimile(A, Q))
		cout << "Esiste una sottomatrice simile";
	else 
		cout << "Non Esiste";

	return 0;
}

void leggiMatriceA(int A[][N]){
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			cout << "inserisci A[" << i<< " "<<j<<"] "<<endl;
			cin >> A[i][j];
		}
}

void leggiMatriceQ(int Q[][K]){
	for(int i = 0; i < K; i++)
		for(int j = 0; j < K; j++){
			cout << "inserisci Q[" << i<< " "<<j<<"] "<<endl;
			cin >> Q[i][j];
		}
}

bool verificaEsisteSimile(int A[][N], int Q[][K]){
	
	bool esisteSimile = false;
	int i, j;

	for(i = 0; i <= N-K && !esisteSimile; i++)
		for(j = 0; j <= N-K && !esisteSimile; j++){
			esisteSimile = verificaSimili(A, Q, i, j);
		}

	// decrementiamo i e j di 1 in quanto nel for vengono incrementati anche dopo aver trovato la sottomatrice simile
	i--;
	j--;

	if(esisteSimile){
		for(int s = 0; s < K; s++)
			for(int t = 0; t < K; t++)
				A[i+s][j+t] = Q[s][t];

		cout << "Parto dalla posizione "<< i << "," << j <<endl;
		for(int s = 0; s < N; s++){
			for(int t = 0; t < N; t++)
				cout << A[s][t] << " ";
			cout << endl;
		}
			
		return true;
	}
	else {
		return false;
	}

}
bool verificaSimili(int A[][N], int Q[][K], int i, int j){
	
	int sommaDiagonaleA = 0, sommaDiagonaleQ = 0;

	for(int t = 0; t < K; t++)
	{
		sommaDiagonaleQ += Q[t][t];
		sommaDiagonaleA += A[i+t][j+t];
	}

	if(sommaDiagonaleA == sommaDiagonaleQ)
		return true;
	else
		return false;
}


/*
N = 5 K = 3

1 2 3 4 5     0 2 4
2 3 4 1 2     2 3 1
2 3 5 4 2     6 5 3
1 2 1 1 6
2 5 6 7 8*/
















































