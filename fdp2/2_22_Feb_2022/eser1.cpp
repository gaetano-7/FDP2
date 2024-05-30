#include <iostream>
using namespace std;

void func(char& a, char b){
    // char & a = alias di nomeprof[0], quindi ogni modifica fatta ad a viene fatta a nomeprof[0]
    // char b = b assume il valore di nomeprof[1], quindi b='a'
    char c = a; // char c assume il valore di a, quindi c='m'
    a = b; // siccome a è un alias di nomeprof[0], nomeprof[0] assume il valore di b, quindi nomeprof[0]='a'
    b = c; // b assume il valore di c, quindi b='m'
}

int main()
{
 char* nome = new char[3]{'g','a','e'};
    //1. La seguente istruzione è corretta? Se sì, cosa stampa?
    //cout << *(nome[1]) << endl;
    // non è corretta, se si vuole stampare l'elemento con indice 1 si scrive cout << *(nome + 1)

    //2. La seguente istruzione è corretta? Se sì, cosa stampa?
    cout << *(nome + 2) << endl;
    // stampa l'elemento con indice 2 dell'array matricola : 'e'

    //3. La seguente istruzione è corretta? Se sì, cosa stampa?
    char* a = &nome[2]; // a punta all'indirizzo di memoria dell'elemento con indice 2 : 'e'
    cout << *(a - 1) << endl; // sottrae 1 all'elemento puntato da a, quindi ora a punta all'elemento con indice 1 : 'a'


    //4. Cosa viene stampato dalla seguente porzione di codice?
    char* nome_prof = new char[3]{'m','a','t'};
    func (nome_prof[0], nome_prof[1]); // la funzione crea un alias al primo elemento e gli assegna il valore del secondo elemento, quindi il primo elemento avrà lo stesso valore del secondo elemento
    cout << nome_prof[0] << " " << nome_prof[1] << endl; // stampa :  a a
}