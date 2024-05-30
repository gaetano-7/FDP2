#include <iostream>
#include <vector>
using namespace std;




struct Soluzione{
    /* SOLUZIONE */
    vector<int> sol; //indici degli elementi inseriti
    //int somma_corrente; //se voglio evitare di ricalcolare la somma
    /****/

    /* ISTANZA */
    vector<int> elementi; //elementi in input
    int somma_target;
    /****/

    Soluzione(vector<int>& el, int st) : elementi(el), somma_target(st){}
};

bool solve(Soluzione& soluzione);
bool canAdd(int x, const Soluzione& soluzione);
void add(int x, Soluzione& soluzione);
bool isComplete(const Soluzione& soluzione);
void remove(Soluzione& soluzione);

int main(){
    vector<int> elementi;
    cout << "Inserisci elementi: ";
    int elem; cin >> elem;

    while (elem != -1)
    {
        elementi.push_back(elem);
        cin >> elem;
    }

    int somma_target;
    cout << endl << "Inserisci target: ";
    cin >> somma_target;

    Soluzione s(elementi, somma_target);

    if(solve(s))
        for(int indice: s.sol)
            cout << s.elementi[indice] << " ";
    else    
        cout << "Non esiste alcuna soluzione";
    
}

bool solve(Soluzione& soluzione){
    int x = 0;
    while(x < soluzione.elementi.size()){
        if(canAdd(x, soluzione)){
            add(x, soluzione);

            if(isComplete(soluzione))
                return true;
            
            if(solve(soluzione)) //if(solve(soluzione, x+1))
                return true;
            
            remove(soluzione);
            x++;
        } 
        else 
            x++;
    }
    return false;
}

//True se aggiungendo x non supero il target, False altrimenti
bool canAdd(int x, const Soluzione& soluzione){

    //controllo se ho gia' usato l'indice x
    for(int y: soluzione.sol)
        if(y == x)
            return false;

    int somma = 0;

    for(int indice: soluzione.sol){
        somma += soluzione.elementi[indice];
    }

    if(somma + soluzione.elementi[x] > soluzione.somma_target)
        return false;
    
    return true;
}

void add(int x, Soluzione& soluzione){
    soluzione.sol.push_back(x);
}

bool isComplete(const Soluzione& soluzione){
    int somma = 0;
    for(int indice: soluzione.sol)
        somma += soluzione.elementi[indice];
    
    return somma == soluzione.somma_target;
}

void remove(Soluzione& soluzione){
    soluzione.sol.pop_back();
}