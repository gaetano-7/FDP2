#include <iostream>
#include <vector>
using namespace std;

class Persona{
    private:
        string nome;
        string cognome;
    public:
        Persona() {} // costruttore senza parametri
        Persona(string n, string c) :nome(n), cognome(c) {} // costruttore con parametri

        // metodi get
        string get_nome() const {return nome;}
        string get_cognome() const {return cognome;}

        // metodi set
        void set_nome(string n) {nome = n;}
        void set_cognome(string c) {cognome = c;}

        // classe virtuale pura
        virtual int getStipendio(){
            return 0;
        }
};

class Studente : public Persona{
    public:
        Studente(): Persona() {}
        Studente(string n, string c): Persona(n,c) {}
        int getStipendio(){
            return 10;
        }
};

class Impiegato : public Persona{
    public:
        Impiegato(): Persona() {}
        Impiegato(string n, string c): Persona(n,c) {}
        int getStipendio(){
            return 100;
        }
};

class GestorePersone{
    private:
        vector<Persona*> persone;
    public:
        void aggiungiPersona(Persona* p){
            persone.push_back(p);
        }

        double getStipendioMedio(){
            double somma = 0.0;
            for(auto p: persone){
                somma+=p->getStipendio();
            }
            return somma/persone.size();
        }
};

int main(){
    GestorePersone g;
    Studente* s1 = new Studente("Giuseppe","Lentini");
    Studente* s2 = new Studente("Gaetano", "Larocca");
    Impiegato* i1 = new Impiegato("Pio","Pisera");
    Impiegato* i2 = new Impiegato("Pio","Pisera");
    g.aggiungiPersona(s1);
    g.aggiungiPersona(s2);
    g.aggiungiPersona(i1);
    g.aggiungiPersona(i2);
    cout<<g.getStipendioMedio()<<endl;
}