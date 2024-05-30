#include <iostream>
using namespace std;
int main(){

	int card = 0, card_ins = 0, card_max = 0, val;

	cout << "Inserisci la sequenza" << endl;

	cin >> val;
	
	while(val != -1){

		if(val != 0)
			card_ins++;
		else{
			card++;
			
			if(card_ins > card_max)
				card_max = card_ins;

			card_ins = 0;
		}

		cin >> val;
	}

	cout << "Cardinalità della famiglia = " << card << endl;
	cout << "Cardinalità massima degli insiemi = " << card_max << endl;


	return 0;
}
