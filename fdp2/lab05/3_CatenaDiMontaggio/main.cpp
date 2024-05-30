#include "CatenaDiMontaggio.h"
#include <iostream> 
using namespace std;

int main(){
    CatenaDiMontaggio<int> lista;
    lista.aggiungi(1);
    lista.aggiungi(2);
    lista.aggiungi(3);
    lista.aggiungi(4);
    lista.aggiungi(5);

    cout<<"Lunghezza: "<<lista.size()<<endl;
    cout<<lista.prossimo()<<endl;
    lista.rimuovi();

    cout<<lista.prossimo()<<endl;
    lista.rimuovi();

    cout<<lista.prossimo()<<endl;
    lista.rimuovi();

    cout<<lista.prossimo()<<endl;
    lista.rimuovi();

    cout<<lista.prossimo()<<endl;
    lista.rimuovi();
    
    cout<<"Lunghezza: "<<lista.size()<<endl;
    return 0;
}