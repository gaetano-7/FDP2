Esercizio 1.

bool precede(Spedizione* s1, Spedizione* s2) {
    if(s1->getCodice() == 1 && s2->getCodice() != 1)
        return true;
    if(s2->getCodice() == 1 && s1->getCodice() != 1)
        return false;
    if(s1->getCodice() == 1 && s2->getCodice() == 1)
        return s1->getValore() < s2->getValore();
        
    //Da qui in poi sappiamo che il codice di s1 e di s2 è sicuramente diverso da 1.
    if(s1->getCodice() == 2 && s2->getCodice() != 2)
        return true;
    if(s2->getCodice() == 2 && s1->getCodice() != 2)
        return false;
    if(s1->getCodice() == 2 && s2->getCodice() == 2)
        return s1->getPeso() < s2->getPeso();
        
    //Da qui in poi sappiamo che il codice di s1 e di s2 è sicuramente diverso da 1 e diverso da 2.
    return s1->getId() < s2->getId();
}

class CodaSpedizioni : private list<Spedizione*> {
    public:
        void add(Spedizione* s) {
            //push_back(s);
            //sort(precede);
            for(auto it = begin(); it != end(); it++) {
                if(precede(s, *it)) {
                    insert(it, s);
                    return;
                }
            }
            push_back(s);
            
        }
        Spedizione* next() const {
            return front();
        }
        void remove() {
            pop_front(); 
        }
        unsigned int size() const {
            return list<Spedizione*>::size();
        }
};


Esercizio 2.
class Prodotto {
    public:
        virtual ~Prodotto() {}
        Prodotto(string i, float p) : id(i), prezzo(p) {}
        friend ostream& operator<<(ostream& o, const Prodotto& p) {
            return p.stampa(o);
        }
        virtual void stampaPrezzoScontato() const { cout << prezzo << endl; }
        
        float getPrezzo() const { return prezzo; }
        string getId() const { return id; }
        
    protected:
        virtual ostream& stampa(ostream& out) const {
            out << "Prodotto: " << id << ", " << prezzo;
            return out;
        }
        
    private:
        string id;
        float prezzo;
};

class Libro : public Prodotto {
    public:
        Libro(string id, float prezzo, string t, string a) : Prodotto(id, prezzo), titolo(t), autore(a) {}
        void stampaPrezzoScontato() const { cout << (getPrezzo()-(getPrezzo()*0.3)) << endl; }
    protected:
        ostream& stampa(ostream& out) const {
            out << "Libro: " << getId() << ", " << getPrezzo() << ", " << titolo << ", " << autore;
            return out;
        }
        
    private:
        string titolo;
        string autore;
};

class Computer : public Prodotto {
    public:
        Computer(string id, float prezzo, string m) : Prodotto(id, prezzo), modello(m) {}
        void stampaPrezzoScontato() const {
            cout << (getPrezzo()-(getPrezzo()*0.05)) << endl;
        }
        
    private:
        string modello;
        
};

Esercizio 3.

1) L'output è bP.
2) Linea 3 perché la classe Test è astratta (ha un metodo virtuale puro), quindi non può essere creato un oggetto di tipo Test.
Linea 4 perché il metodo b() è protected, quindi non è visibile nel main.
Linea 5 per lo stesso motivo della linea 4.
Linea 6 peché in Test non è definito il distruttore virtuale.
3) Le linee 1 e 2 diventerebbero scorrette.
4) Solo il distruttore, aggiungendo la keyword virtual, perché altrimenti il comportamento della linea 6 del main è indefinito.