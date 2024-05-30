#include "AlberoB.h"
#include <iostream>
#include <queue>
#include <list>

using namespace std;
bool isHeap(const AlberoB<int>& a);
bool piramideSalda(const AlberoB<int>& a, int pesoMassimo);
int sommaPath(const AlberoB<int>& a);
int sommaPath(const AlberoB<int>& a, int sommaCorrente);
bool pariEDispari(const AlberoB<int>& a);
bool pariEDispari(const AlberoB<int>& a, int livello);
bool esame(const AlberoB<int>& a);

bool esame(const AlberoB<int>& a, list<int>& percorso, int x);
list<int> esame_(const AlberoB<int>& a, int x);

int main(){

    AlberoB<int> a(5);

    AlberoB<int> b(6);
    AlberoB<int> c(12);
    a.insFiglio(SIN, b);
    a.insFiglio(DES, c);

    AlberoB<int> d(10);
    b.insFiglio(SIN, d);

    AlberoB<int> e(42);
    AlberoB<int> f(32);
    c.insFiglio(SIN, f);
    c.insFiglio(DES, e);

    for(int a: esame_(a, 6))
        cout << a << " ";
}

list<int> esame_(const AlberoB<int>& a, int x){
    list<int> percorso;
    if(esame(a, percorso, x))
        return percorso;

    percorso.push_back(-1);
    return percorso;
}


bool esame(const AlberoB<int>& a, list<int>& percorso, int x){
    if(a.nullo())
        return false;
    percorso.push_back(a.radice());
    if(a.foglia())
        if(a.radice() == x)
        {
            return true;
        }
        else{
            percorso.pop_back();
            return false;
        }
    
    if(esame(a.figlio(SIN), percorso, x))
        return true;
    
    if(esame(a.figlio(DES), percorso, x))
        return true;
        
    percorso.pop_back();
    return false;
    
}

//return true se e solo se a è un heap con il valore massimo come radice
bool isHeap(const AlberoB<int>& a){

    if(a.foglia() || a.nullo())
        return true;
    
    if(!a.figlio(SIN).nullo() && a.radice() < a.figlio(SIN).radice()){

        cout << a.figlio(SIN).radice() << " (SIN) maggiore del padre " << a.radice() << endl;
        return false;
    }
    if(!a.figlio(DES).nullo() && a.radice() < a.figlio(DES).radice()){
        
        cout << a.figlio(DES).radice() << " (DES) maggiore del padre " << a.radice() << endl;
        return false;
    }

    return isHeap(a.figlio(SIN)) && isHeap(a.figlio(DES));

}

//return true se e solo se la somma dei valori su ogni livello è <= pesoMassimo
bool piramideSalda(const AlberoB<int>& a, int pesoMassimo){
    if (a.nullo())
        return true;
    
    queue<AlberoB<int>> qAlberi;
    queue<int> qLivelli; 

    qAlberi.push(a);
    qLivelli.push(1);
    
    int somma = 0;
    int livelloCorrente = 1;

    while(!qAlberi.empty()) {
        AlberoB<int> temp = qAlberi.front(); 
        qAlberi.pop();			 
        
        int livelloTemp = qLivelli.front();
        qLivelli.pop();

        if (livelloTemp == livelloCorrente)
            somma += temp.radice();
        else {
            cout << "Livello" << livelloCorrente << " peso = " << somma << endl;
            if(somma > pesoMassimo)
                return false;

            livelloCorrente++;
            somma = temp.radice();
        }    

        if (!temp.figlio(SIN).nullo()){
            qAlberi.push(temp.figlio(SIN));
            qLivelli.push(livelloTemp + 1);
        }

        if (!temp.figlio(DES).nullo()){
            qAlberi.push(temp.figlio(DES));
            qLivelli.push(livelloTemp + 1);
        }
    }
    cout << "Ultimo livello peso = " << somma << endl; 
    if(somma > pesoMassimo)
        return false;

    return true;
}

// ogni percorso radice foglia non deve superare il valore max
bool ogniPercorsoRadiceFoglia(const AlberoB<int>& a, int max, int sommaCorrente){
    
    if(a.nullo())
        return true;

    sommaCorrente += a.radice();

    if(a.foglia())
        if(sommaCorrente > max)
            return false;
        else   
            return true;

    return ogniPercorsoRadiceFoglia(a.figlio(SIN), max, sommaCorrente) &&
            ogniPercorsoRadiceFoglia(a.figlio(DES), max, sommaCorrente);    


}

//return true se e solo se:
// su ogni livello pari ci sono solo valori pari
// su ogni livello dispari ci sono solo valori dispari
// assumiamo che la radice sia a livello 1


bool pariEDispari(const AlberoB<int>& a){
    return pariEDispari(a, 1);
}

bool pariEDispari(const AlberoB<int>& a, int livello){

    if(a.nullo())
        return true;

    if((livello % 2 == 0 && a.radice() % 2 == 1) || (livello % 2 == 1 && a.radice() % 2 == 0))
        return false;

    return pariEDispari(a.figlio(SIN), livello + 1) && pariEDispari(a.figlio(DES), livello + 1);
    
}


/*  
      2
    /	\
   3     4
  / \   /
 5   1 3 

 235 + 231 + 243 = 709
*/
int sommaPath(const AlberoB<int>& a){
    return sommaPath(a, 0);
}

int sommaPath(const AlberoB<int>& a, int sommaCorrente){

    if(a.nullo())
        return 0;

    int numero = sommaCorrente * 10 + a.radice();
    cout << numero << endl;

    if(a.foglia())   
        return sommaCorrente * 10 + a.radice();
    
    return sommaPath(a.figlio(SIN), sommaCorrente * 10 + a.radice()) +
           sommaPath(a.figlio(DES), sommaCorrente * 10 + a.radice());
    
}

/***************************************************/
/*riceve un vector di interi e popola l'albero 

/* vettore = 3, 5, 7, 2, 4, 1, 5
 4 -> 1 (i-1)/2
 3 -> 1 (i-1)/2

 5 -> 2 (i-1)/2
 6 -> 2 (i-1)/2

/* alberi = {(3), (5), (7)
/* albero ->       3
				 /  \
			    5    7
			   / \  / \
			  2	 4 1   5
*/
AlberoB<int> vecToAlbero(vector<int> vettore)
{
    AlberoB<int> albero(vettore[0]);

    vector<AlberoB<int>> alberi;
    alberi.push_back(albero);

    for(int i = 1; i < vettore.size(); i++){
        AlberoB<int> newAlbero(vettore[i]);
        alberi.push_back(newAlbero);

        if(i % 2 == 1)
            alberi[ (i-1) / 2].insFiglio(SIN, newAlbero);
        else
            alberi[ (i-1) / 2].insFiglio(DES, newAlbero);
    }  

    return albero;

}

//PER CASA (PER CHI VUOLE)

/*Restituisce true se e solo se il numero di foglie con valore < 0 
è uguale al numero di foglie con valore >= 0*/
bool fogliePosEqfoglieNeg(const AlberoB<int>& a){

    return false;
}
//Restituisce true se la somma di ogni coppia di livelli adiacenti non supera il max
bool sommaLivelliAdiacenti(const AlberoB<int>& a, int max){
    return false;
}


/* Supponiamo che ogni percorso dalla radice alla foglia constituisca una parola. 
 Restituisce true: 
    se ogni parola ha un numero di vocali e di consonanti che differisce al più di uno.
 Si supponga che la parola contenga solo lettere e che siano tutte minuscole
    a
   / \
  i   d
 / \   \
e  f    l
 -> false perchè aie contiene tre vocali e zero consonanti
 */

bool vocaliEConsonanti(const AlberoB<char>& a){

    return false;
}


bool cercaSePresente(const AlberoB<int>& a, int x){

    if(a.nullo())
        return false;

    if(a.radice() == x)
        return true;
    
    return cercaSePresente(a.figlio(SIN), x) || 
           cercaSePresente(a.figlio(DES), x);
}


int laiseFunction(const AlberoB<int>& a, bool direzione){

    if(a.nullo())
        return 0;
    
    if(a.foglia())
        if(direzione)
            return a.radice();
        else 
            return 0;

    return laiseFunction(a.figlio(SIN), true) + laiseFunction(a.figlio(DES), false);    
}
