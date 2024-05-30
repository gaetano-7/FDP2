#include <iostream>
using namespace std;

int main(){
    string* nc = new string[2]{"Gaetano", "Larocca"};
    //1: La seguente istruzione è corretta? Se sì, cosa stampa?
    cout << nc[0][2]; // stampa il carattere con indice 2 della stringa con indice 0, quindi 'e'
    cout<<endl;

    //2: La seguente istruzione è corretta? Se sì, cosa stampa?
    cout << *(nc + 1); // stampa l'elemento con indice 1, quindi "Larocca"
    cout<<endl;

    //3: La seguente porzione di codice è corretta? Se sì, cosa fa?
    for (int i = 0; i < nc[0].length();i++) // scandisce i caratteri della stringa con indice 0
        cout << nc[0][nc[0].length() - 1 - i]; // stampa la stringa al contrario, quindi "onateaG"
    cout<<endl;
    
    //4: Come andrebbe deallocata la memoria dinamica allocata in questo main?
    // A: delete nc[2];
    // B: delete nc;
    // C: delete [] nc; // corretta
    // D: nel main non serve il distruttore.
}