#include "AlberoB.h"
#include <iostream>
#include <string>
#include <queue>

using namespace std;

AlberoB<int> cerca(const AlberoB<int>& a, int v) {
    if (a.nullo() || a.radice() == v)
        return a;
    
    // a questo punto sono in un sottoalbero che non ha v come valore informativo e non è nullo
    AlberoB<int> temp = cerca(a.figlio(SIN), v);
    if (!temp.nullo())
        return temp;
    // a questo punto so che nel sottoalbero sinistro non c'era un albero con v come valore informativo
    return cerca(a.figlio(DES), v);
}
int somma(AlberoB<int> a)
{
	if (a.nullo()) return 0;
	return a.radice()+somma(a.figlio(SIN))+somma(a.figlio(DES));
}

typedef AlberoB<int> AlberoBInt;

void visitaPerLivelli(const AlberoB<int>& a) {
    if (a.nullo())
        return;
    
    queue<AlberoB<int>> q;
    q.push(a);
    
    while(!q.empty()) {
        AlberoBInt temp = q.front(); // q.front() restituisce l'oggetto in 
//testa alla coda SENZA RIMUOVERLO
        q.pop();			 // q.pop() rimuove l'oggetto in testa alla coda
        
// elaborare l'albero temp
        cout << temp.radice() << " --> " << somma(temp)<<endl; 

        if (!temp.figlio(SIN).nullo())
            q.push(temp.figlio(SIN));
        if (!temp.figlio(DES).nullo())
            q.push(temp.figlio(DES));
    }
}

bool verificaSomme(AlberoB<int> a)
{
	if (a.nullo()) return true;
	return	(a.radice()> somma(a.figlio(SIN))+somma(a.figlio(DES)))
		 && verificaSomme(a.figlio(SIN))
		&& verificaSomme(a.figlio(DES));
}

int main()
{
	string temp;
	bool firstLine=true; 
	AlberoB<int> A(42); //un valore a caso
	
	while (getline(cin,temp))
	{
		if (temp=="-1") break;
		if (firstLine){
			int valoreRadice=stoi(temp);
			A.modRadice(valoreRadice); 
			firstLine=false;
		}
		else{
			int indiceDuePunti=temp.find(':');
			int indiceSpazio=temp.find(' ');
			string parteSinistra=temp.substr(0,indiceDuePunti);
			string parteDestra=temp.substr(indiceDuePunti+1,indiceSpazio-indiceDuePunti);
			
			int valoreNodo=stoi(parteSinistra);
			int valorePadre=stoi(parteDestra);
			Direzione dir;		
			if (temp[indiceSpazio+1] == 'd') dir=DES;
			else dir=SIN;
			
			AlberoB<int> padreInCuiInserire=cerca(A,valorePadre);
			if (!padreInCuiInserire.nullo()){
				AlberoB<int> daInserire(valoreNodo);
				padreInCuiInserire.insFiglio(dir,daInserire);
			}
		}
	}
	visitaPerLivelli(A);
}
