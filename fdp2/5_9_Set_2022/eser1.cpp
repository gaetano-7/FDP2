#include <iostream>
using namespace std;

int main(){
    int* matricola = new int[6] {2,2,0,6,6,6};
    //1. La seguente istruzione è corretta? Se sì, cosa stampa?
    cout << *(&matricola[4]); // stampa l'elemento con indice 4, quindi 6
    cout<<endl;

    //2. La seguente istruzione è corretta? Se sì, cosa stampa?
    cout << *(matricola + 3); // stampa l'elemento con indice 3, quindi 6
    cout<<endl;

    //3. Cosa stampa la seguente porzione di codice?
    int& second = matricola[1]; // second è un alias di matricola[1]
    matricola[1]++; // incrementa matricola[1], quindi anche second che da 2 diventa 3
    second ++; // incrementa second, quindi anche matricola[1] che da 3 diventa 4
    cout << second; // stampa 4
    cout<<endl;

    //4. Come andrebbe deallocata la memoria dinamica allocata inizialmente?
    // A: delete matricola[6];
    // B: delete[] matricola; // corretta
    // C: delete matricola;
    // D: Nel main non va deallocata alcuna memoria dinamica.
}