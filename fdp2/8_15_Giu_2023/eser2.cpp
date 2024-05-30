#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Veicolo{
    private:
        string targa;
        double prezzo;  
        string marca;
    public:
        // costruttore classe Veicolo
        Veicolo(string tg, double pr, string ma) : targa(tg), prezzo(pr), marca(ma) {}
        // costruttore di copia
        Veicolo(const Veicolo& other) : targa(other.targa), prezzo(other.prezzo), marca(other.marca) {};
        
        string get_targa() const{return targa;}
        double get_prezzo() const{return prezzo;}
        string get_marca() const{return marca;}

        virtual double prezzoFinale() const = 0;
};

class Auto : public Veicolo{
    public:
        Auto(string tg, double pr, string ma) : Veicolo(tg, pr, ma) {}
        double prezzoFinale() const override{
            return get_prezzo() - (get_prezzo() * 0.25);
        }
};

class Moto : public Veicolo{
    public:
        Moto(string tg, double pr, string ma) : Veicolo(tg, pr, ma) {}
        double prezzoFinale() const override{
            return get_prezzo() - (get_prezzo() * 0.15);
        }
};

int main(){
    vector<Veicolo*> veicoli;

    while(veicoli.size() < 4){
        string tipo;
        string targa;
        double prezzo;
        string marca;
        cin >> tipo >> targa >> prezzo >> marca;
        if(tipo == "auto"){
            veicoli.push_back(new Auto(targa, prezzo, marca));
        }else if(tipo == "moto"){
            veicoli.push_back(new Moto(targa, prezzo, marca));
        }
    }
    //ordina i veicoli
    sort(veicoli.begin(), veicoli.end(), [](const Veicolo* v1, const Veicolo* v2){return v1->prezzoFinale() < v2->prezzoFinale();});
    //stampa i veicoli
    for(auto v : veicoli){
        cout << v->get_targa() << " " << v->prezzoFinale() << " " << v->get_marca() << endl;
        delete v;
    }
    return 0;
}