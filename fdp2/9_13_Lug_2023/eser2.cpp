#include <iostream>
#include <list>

using namespace std;

class Spedizione {
private:
    int codice;
    float valore;
    float peso;

public:
    Spedizione(int codice, float valore, float peso) : codice(codice), valore(valore), peso(peso) {}

    int getCodice() const {
        return codice;
    }

    float getValore() const {
        return valore;
    }

    float getPeso() const {
        return peso;
    }

    friend ostream& operator<<(ostream& os, const Spedizione& sp) {
        os << "Codice: " << sp.codice << ", Valore: " << sp.valore << ", Peso: " << sp.peso;
        return os;
    }

    bool operator==(const Spedizione& other) {
        return (codice == other.codice) && (valore == other.valore) && (peso == other.peso);
    }
};

class CodaSpedizioni : public list<Spedizione*> {
public:
    void add(Spedizione* sp) {
    // Controllo se la spedizione esiste già
    for (auto it = this->begin(); it != this->end(); ++it) {
        if (*it == sp) {
            return;  // Spedizione già presente, non fare nulla
        }
    }

    // Inserimento ordinato della spedizione
    auto it = this->begin();
    while (it != this->end()) {
        if (sp->getPeso() < (*it)->getPeso()) {
            break;  // Inserimento in base al peso
        } else if (sp->getPeso() == (*it)->getPeso() && sp->getValore() < (*it)->getValore()) {
            break;  // Inserimento in base al valore a parità di peso
        } else if (sp->getPeso() == (*it)->getPeso() && sp->getValore() == (*it)->getValore() &&
                   sp->getCodice() < (*it)->getCodice()) {
            break;  // Inserimento in base al codice a parità di peso e valore
        }
        ++it;
    }

    this->insert(it, sp);
}

    Spedizione* next() const {
        if (!this->empty()) {
            return *(this->begin());
        }
        return nullptr;
    }

    void remove() {
        if (!this->empty()) {
            delete *(this->begin());
            this->erase(this->begin());
        }
    }

    unsigned int size() const {
        return this->size();
    }
};

int main() {
    CodaSpedizioni coda;

    // Creazione delle spedizioni
    Spedizione spedizione1(1, 100.0, 10.0);
    Spedizione spedizione2(2, 200.0, 20.0);
    Spedizione spedizione3(3, 150.0, 15.0);
    Spedizione spedizione4(4, 180.0, 18.0);

    // Aggiunta delle spedizioni alla coda
    coda.add(&spedizione1);
    coda.add(&spedizione2);
    coda.add(&spedizione3);
    coda.add(&spedizione4);

    // Stampa della prossima spedizione nella coda
    Spedizione* prossimaSpedizione = coda.next();
    if (prossimaSpedizione != nullptr) {
        cout << "Prossima Spedizione: " << *prossimaSpedizione << endl;
    }

    // Rimozione della prossima spedizione dalla coda
    coda.remove();

    // Stampa della prossima spedizione dopo la rimozione
    prossimaSpedizione = coda.next();
    if (prossimaSpedizione != nullptr) {
        cout << "Prossima Spedizione: " << *prossimaSpedizione << endl;
    }

    // Stampa della dimensione della coda
    cout << "Dimensione della coda: " << coda.size() << endl;

    return 0;
}
