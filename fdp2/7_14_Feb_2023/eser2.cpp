#include <iostream>
#include <vector>

using namespace std;

class Prodotto {
    public:
        Prodotto(string nome, double prezzo) : nome(nome), prezzo(prezzo) {}
        Prodotto(const Prodotto& other) : nome(other.nome), prezzo(other.prezzo) {}
        string get_nome() const { return nome; }
        double get_prezzo() const { return prezzo; }
        bool operator==(const Prodotto& other) { return nome == other.nome && prezzo == other.prezzo; }
    private:
        string nome;
        double prezzo;
};

class ListaDellaSpesa {
    private:
        struct Entry {
            Prodotto prodotto;
            int quantita;
        };
        vector<Entry> lista;
    public:
        void inserisci(const Prodotto& p, int q) {
            for (auto& i : lista) {
                if (i.prodotto == p) {
                    i.quantita += q;
                    return;
                }
            }
            lista.push_back({p, q});
        }

        bool rimuovi(const Prodotto& p) {
            for (auto it = lista.begin(); it != lista.end(); ++it) {
                if (it->prodotto == p) {
                    lista.erase(it);
                    return true;
                }
            }
            return false;
        }

        double totale() const {
            double costoTotale = 0.0;
            for (const auto& i : lista) {
                costoTotale += i.prodotto.get_prezzo() * i.quantita;
            }
            return costoTotale;
        }
};

int main() {
    ListaDellaSpesa lista;
    Prodotto p1("Pasta", 1.5);
    Prodotto p2("Latte", 2.0);
    Prodotto p3("Pane", 1.0);

    lista.inserisci(p1, 2);
    lista.inserisci(p2, 3);
    lista.inserisci(p3, 1);

    cout << "Totale: " << lista.totale() << endl;

    lista.rimuovi(p2);

    cout << "Totale dopo la rimozione: " << lista.totale() << endl;

    return 0;
}
