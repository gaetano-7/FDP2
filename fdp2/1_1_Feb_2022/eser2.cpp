#include <iostream>
#include <map>
using namespace std;

class GestoreValori{
    public:
        GestoreValori() {}

        multimap<int,char> lista;

        void inserisciCoppia(int a, char b){
            lista.insert(pair<int,char> {a,b});
        }

        int numCoppie(){
            return lista.size();
        }

        int getRisultato(){
            return -1;
        }
};

class GestoreValoriA : public GestoreValori{
    public:
        int getRisultato(){
            int somma = 0;
            int cont = 0;
            for(auto i : lista){
                if(i.second=='a'){
                    somma += i.first;
                    cont++;
                }
            }
            if(cont>0){
                return somma;
            }
            return 0;
        }
};

class GestoreValoriB : public GestoreValori{
    public:
        int getRisultato(){
            int somma = 0;
            int cont = 0;
            for(auto i : lista){
                if(i.second=='b'){
                    somma += i.first;
                    cont++;
                }
            }
            if(cont>0){
                return somma / cont;
            }
            return 0;
        }
};

int main(){
    GestoreValori gv;
    GestoreValoriA gvA;
    GestoreValoriB gvB;
    gvA.inserisciCoppia(3,'a');
    gvB.inserisciCoppia(7,'b');
    gvA.inserisciCoppia(2,'a');
    gvB.inserisciCoppia(6,'b');

    cout<<gv.getRisultato()<<endl;

    cout<<gvA.getRisultato()<<endl;
    cout<<gvB.getRisultato()<<endl;
    return 0;
}