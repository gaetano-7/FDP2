#include <iostream>
using namespace std;
int main(){

	int prec = 0, corr = 0, succ = 0;
	int numDati = 0, numPicchi = 0;

	cin >> succ;

	while(succ >= 0)
	{ 
		numDati++;
		if(numDati >= 3)
			if( (prec < corr) && (corr > succ))
			{
				cout << "Trovato picco: " << corr << " nel giorno " << numDati -1 << endl;
				numPicchi++;
			}

		prec = corr;
		corr = succ;
		cin >> succ;
	}

	cout << "Numero di picchi massimi rilevati " << numPicchi << endl;
	cout << "Numero di dati letti " << numDati << endl;

	return 0;
}