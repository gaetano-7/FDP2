#include <iostream>
using namespace std;
void stampa(int * v, const int size);
void resize(int * & v , int & capacity, int increment);

const int dim_base=10; //fisso una dimensione di partenza per l’array
int main(){
int * elenco=new int[dim_base];
int size=0, elem, capacity=dim_base;

while(cin>>elem)
{ 	if(size<capacity) //se c’è ancora spazio:
		elenco[size++]=elem;

	else{ 	//altrimenti crea nuovo spazio: ingrandisci l’array
		resize(elenco, capacity, dim_base);
		elenco[size++]=elem;
	}
}
stampa(elenco,size);
};

void resize(int * & v , int & capacity, int increment)
{
	int * temp= new int[capacity+increment]; //creo un nuovo array più grande
	for (int i=0; i<capacity; i++)	//copio gli elementi di v
		temp[i]= v[i];
	delete [] v;				//cancello il vecchio v 
					// ATTENZIONE SE NON LO FACCIO E’ UN DISASTRO!
	v=temp; 					//creo il nuovo v
    capacity+= increment; 
}
// ATTENZIONE, quando esco dalla funzione viene cancellato temp, ma non lo spazio che ho allocato, quindi il nuovo array rimane in memoria

void stampa(int * v, const int size)
{	for (int i=0; i <size; i++) cout<<v[i]<<" ";
	cout<<endl;
}
