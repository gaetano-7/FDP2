#include <iostream>
#include <list>
#include <map>
using namespace std;

class Partita{
    private:
        string squadraCasa;
        string squadraOspite;
        int goalCasa;
        int goalOspite;
    public:

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
};

class GestorePartite{
    private:
        list<Partita*> partite;
    public:
        GestorePartite() {}
        void aggiungiPartita(string squadraCasa, string squadraOspite, int goalCasa, int goalOspite){
            Partita* p = new Partita(squadraCasa,squadraOspite,goalCasa,goalOspite);
            partite.push_back(p);
        }

        string getSquadraPiuForte() const{
            int maxVittorie = 0;
            string squadraForte;

            map<string, int> vittorie;

            for(Partita* p : partite){
                if(p->get_goalCasa() > p->get_goalOspite()){
                    vittorie[p->get_squadraCasa()]++;
                } else if (p->get_goalOspite() > p->get_goalCasa()){
                    vittorie[p->get_squadraOspite()]++;
                }
            }

            for (auto it = vittorie.begin(); it != vittorie.end(); ++it) {
                if (it->second > maxVittorie) {
                    maxVittorie = it->second;
                    squadraForte = it->first;
                }
            }

            return squadraForte;
        }

        double mediaGoal() const {
            int totalGoals = 0;
            int numPartite = partite.size();

            for (Partita* partita : partite) {
                totalGoals += partita->get_goalCasa() + partita->get_goalOspite();
            }

            if (numPartite > 0) {
                return static_cast<double>(totalGoals) / numPartite;
            } else {
                return 0.0;
            }

        }

        // Costruttore di copia
        GestorePartite(const GestorePartite& other) {
            for (Partita* partita : other.partite) {
                partite.push_back(new Partita(*partita));
            }
        }
};

int main(){
    GestorePartite g;
    g.aggiungiPartita("juve","milan",2,1);
    g.aggiungiPartita("inter","juve",0,2);
    g.aggiungiPartita("milan","inter",2,2);
    g.aggiungiPartita("roma","napoli",1,0);

    cout<<"SQUADRA PIU' FORTE: ";
    cout<<g.getSquadraPiuForte()<<endl;

    cout<<"MEDIA GOAL SEGNATI: ";
    cout<<g.mediaGoal()<<endl;
}