#include <iostream>
#include <vector>
using namespace std;

class Carriera{
    private:
        int numAppelli;
        vector<bool*> esiti;
        vector<string*> nomiEsami;
    public:
        Carriera() {} // costruttore senza parametri
        Carriera(const Carriera&): numAppelli(), esiti(), nomiEsami(){} // costruttore di copia
        Carriera& operator=(const Carriera&) {    // Operatore di assegnazione
            numAppelli = numAppelli,
            esiti = esiti,
            nomiEsami = nomiEsami;
            return *this;
        }
        ~Carriera() {}    // Distruttore

        void aggiungiTentativo(string nome, bool esito){
            esiti.push_back(&esito);
            nomiEsami.push_back(&nome);
        }

        void rimuoviUltimoAppello(){
            esiti.pop_back();
            nomiEsami.pop_back();
        }

        bool studenteDiligente(){
            int pos = 0;
            int neg = 0;

            for(bool i : esiti){
                if(i==true){
                    pos+=1;
                }
                else {
                    neg+=1;
                }
            }

            if(pos>neg){
                return true;
            }
            else{
                return false;
            }
        }
};

int main(){
    Carriera c;

    c.aggiungiTentativo("Analisi",true);
    c.aggiungiTentativo("RicercaOperativa",true);
    c.aggiungiTentativo("Economia",false);
    c.aggiungiTentativo("Fondamenti",false);
    c.aggiungiTentativo("Fondamenti",false);

    //c.rimuoviUltimoAppello();

    bool f = c.studenteDiligente();

    if(f) cout<<"true";
    else cout<<"false";

    return 0;
}