//leggere una seq. di N cifre binarie, con N letto da input. individuare 
//la lunghezza massima della sottosequenza costituita da cifre uguali, e la cifra di questa sottosequenza.
#include <iostream>
using namespace std;

int main(){
	int N, lung, lung_max=0, cifra, ultimo, cifra_max;
	
	cout<<"Inserire la lunghezza della sequenza N";
	cin>>N;
	if (N>0)
	{
		cin>>cifra;
		ultimo=cifra;
		lung=1;
		N--;
		while(N>0)
		{
			cin>>cifra;
			N--;
			if (cifra==ultimo) lung++;
			else{
				if(lung>=lung_max)
				{
					lung_max=lung;
					cifra_max=ultimo;
				}
				ultimo=cifra;
				lung=1;
			}
		}
		if(lung>=lung_max)
		{
			lung_max=lung;
			cifra_max=ultimo;
		}
		
		cout<<"Lunghezza massima : "<<lung_max<<endl;
		cout<<"Cifra :"<<cifra_max<<endl;
		
	}
	
}