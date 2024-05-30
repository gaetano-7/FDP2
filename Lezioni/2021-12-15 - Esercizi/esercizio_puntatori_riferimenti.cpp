#include <iostream>
using namespace std;
void f(int* matricola);

int main(){
    int* matricola = new int[6]{1,7,6,1,8,3};
    
    /*****************************************/
    
    cout << *matricola << endl; //E' corretta? Se si, cosa stampa? Corretta, stampa il primo elemento.
    cout << *(&matricola[2]) << endl;  //E' corretta? Se si, cosa stampa? Corretta, stampa il terzo elemento.
    //cout << *(matricola[2]) << endl;  //E' corretta? Se si, cosa stampa? No non è corretta.
    cout << *(matricola + 4) << endl;  //E' corretta? Se si, cosa stampa? Corretta, stampa il quinto elemento.
    
    /*****************************************/


    /*****************************************/
    f(matricola); //La funzione f presenta errori sintattici? No. 
    
    //Cosa stampa? Stampa la matricola invertita alla quale, in posizione i, viene aggiunto il valore i
    for(int i = 0; i < 6; i++) 
        cout << matricola[i] + i << " ";
    cout << endl;
    
    /*****************************************/
    //E' corretta? Se si, cosa stampa? Corretta. Stampa quinto, quarto e terzo elemento della matricola invertita.

    matricola ++;

    int* p = &matricola[3];
    for(int i = 0; i <= 2; i++){
        cout << *(p-i) << " "; 
    }
    /*****************************************/

        
    /*Quale delle seguenti va utilizzata per deallocare l'array? La terza*/
    
    //delete matricola[];
    //delete matricola[6];
    delete [] matricola;
    //delete [6] matricola;
    //delete *matricola;     
    
    /************************************************************/

    
}

void f(int* matricola){
    for(int i = 0; i < 3; i++){
        int* a = new int(*(matricola + i));
        *(matricola + i) = *(matricola + 5 - i);
        matricola[5-i] = *a;
    }
}