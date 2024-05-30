#include <iostream>
using namespace std;

int main(){
    Carriera() {} // costruttore senza parametri
    Carriera(const Carriera&): numAppelli(), esiti(), nomiEsami(){} // costruttore di copia
    Carriera& operator=(const Carriera&) {    // Operatore di assegnazione
            numAppelli = numAppelli,
            esiti = esiti,
            nomiEsami = nomiEsami;
            return *this;}
    ~Carriera() {}    // Distruttore

    // classe virtuale pura
    virtual int getStipendio(){
        return 0;
    }

    // sottoclasse che eredita la classe Persona
    class Studente : public Persona{
    public:
        Studente(): Persona() {}
        Studente(string n, string c): Persona(n,c) {}
        int getStipendio(){
            return 10;
        }
    }

    // costruttore classe Veicolo
    Veicolo(string tg, double pr, string ma) : targa(tg), prezzo(pr), marca(ma) {}
    // costruttore di copia
    Veicolo(const Veicolo& other) : targa(other.targa), prezzo(other.prezzo), marca(other.marca) {};
    // Definizione della classe Auto, derivata dalla classe Veicolo

    // Dichiarazione di una funzione virtuale pura per il calcolo del prezzo finale del veicolo
    virtual double prezzoFinale() const = 0; 

    class Auto : public Veicolo{ 
        public: 
            // Costruttore della classe Auto
            Auto(string tg, double pr, string ma) : Veicolo(tg, pr, ma) {} 
            // Implementazione del metodo virtuale prezzoFinale per la classe Auto
            double prezzoFinale() const override{ 
                return get_prezzo() - (get_prezzo() * 0.25); 
            } 
    }; 

};

    // costruttore con tutti i parametri
    Partita(string sC, string sO, int gC, int gO) : squadraCasa(sC), squadraOspite(sO), goalCasa(gC), goalOspite(gO) {}
    // metodi get
    string get_squadraCasa() const {return squadraCasa;}
    string get_squadraOspite() const {return squadraOspite;}
    int get_goalCasa() const {return goalCasa;}
    int get_goalOspite() const {return goalOspite;}

    // metodi set
    void set_squadraCasa(string sC) {squadraCasa = sC;}
    void set_squadraOspite(string sO) {squadraOspite = sO;}
    void set_goalCasa(int gC) {goalCasa = gC;}
    void set_goalOspite(int gO) {goalOspite = gO;}

    // ereditarietà
    class StatisticheVettore{
        public:
            virtual double compute(const vector<int>&) = 0;
    };

    class MediaVettore : public StatisticheVettore{
        public:
            double compute(const vector<int>& l) override{
                double somma = 0;
                for(auto i : l){
                    somma+=i;
                }
                double media = somma / l.size();
                return media;
            }
    };

    int main(){ 
    vector<Veicolo*> veicoli; // Vettore di puntatori a oggetti della classe Veicolo
 
    // Ciclo per l'inserimento dei veicoli nel vettore
    while(veicoli.size() < 4){ 
        string tipo; // Tipo di veicolo (auto o moto)
        string targa; // Numero di targa del veicolo
        double prezzo; // Prezzo di vendita del veicolo
        string marca; // Marca del veicolo
        cin >> tipo >> targa >> prezzo >> marca; // Lettura dei dati del veicolo dall'input
        if(tipo == "auto"){ // Se il tipo di veicolo è auto, crea un oggetto di tipo Auto e lo inserisce nel vettore
            veicoli.push_back(new Auto(targa, prezzo, marca)); 
        }else if(tipo == "moto"){ // Se il tipo di veicolo è moto, crea un oggetto di tipo Moto e lo inserisce nel vettore
            veicoli.push_back(new Moto(targa, prezzo, marca)); 
        } 
    } 

    // Ordina i veicoli in base al prezzo finale calcolato tramite il metodo virtuale prezzoFinale
    sort(veicoli.begin(), veicoli.end(), [](const Veicolo* v1, const Veicolo* v2){return v1->prezzoFinale() < v2->prezzoFinale();}); 

    // Stampa i dati dei veicoli nel vettore in ordine crescente di prezzo finale
    for(auto v : veicoli){ 
        cout << v->get_targa() << " " << v->prezzoFinale() << " " << v->get_marca() << endl; 
        delete v; // Elimina l'oggetto dallo heap per evitare memory leak
    } 
}