#include <iostream>
using namespace std;
const int n = 3;

void leggiMatrice(int M[][n]);
void vettoreSomiglianze(int A[][n], int B[][n], int V[]);
bool allineateGrado3(int A[][n], int B[][n], int V[]);

int main(){
	int A[n][n], B[n][n], V[n];

	leggiMatrice(A);
	leggiMatrice(B);

	vettoreSomiglianze(A, B, V);
	if(allineateGrado3(A, B, V))
		cout << "allineate con grado 3";
	else 
		cout << "non allineate con grado 3";

	return 0;
}

void leggiMatrice(int M[][n]){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> M[i][j];
}

void vettoreSomiglianze(int A[][n], int B[][n], int V[]){

	for(int j = 0; j < n; j++){
		int gradoSomiglianza = 0;
		for(int s = 0; s < n; s++)
			for(int t = 0; t < n; t++)
				if(A[s][j] == B[t][j])
					gradoSomiglianza ++;
		V[j] = gradoSomiglianza;
 	}
}

bool allineateGrado3(int A[][n], int B[][n], int V[]){

	bool trovataColonnaDisallineata = false;
	for(int j = 0; j < n && !trovataColonnaDisallineata; j++)
		if(V[j] >= n-3){
			for(int s = 0; s < n && !trovataColonnaDisallineata; s++)
				for(int t = 0; t < n && !trovataColonnaDisallineata; t++)
					if(A[s][j] == B[t][j] && abs(s-t)>1)
						trovataColonnaDisallineata = true;	


		}

	if(trovataColonnaDisallineata)
		return false;

	return true;

}

