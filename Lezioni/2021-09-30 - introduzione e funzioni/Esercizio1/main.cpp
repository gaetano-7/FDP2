#include <iostream>
using namespace std;

bool ePrimo(int n);

int main(){
	
	int numero;
	while(cin>>numero)
	{
		if (ePrimo(numero)) 
			cout<<numero<<" e' primo \n";
		else
			cout<<numero<<" non e' primo \n";
	}

	cout<<"Il programma e' finito andate in pace \n";
}

bool ePrimo(int n){
	bool primo=true;
	
	for (int k=n/2; k>1 && primo; k--){
		if(n % k == 0) primo=false;
	}
	return primo;
}