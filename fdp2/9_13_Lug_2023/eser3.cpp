#include <assert.h>
#include <iostream>
using namespace std;

enum Direzione { SIN=0, DES=1 };

template <class T>
struct SNodo{
	T vinfo; // parte informativa
	SNodo *ppadre, *pfiglio[2]; // puntatori al padre e ai due figli
	SNodo( const T& inf ): vinfo(inf)
	{	ppadre = pfiglio[SIN] = pfiglio[DES] = 0;
	}
	~SNodo( ) {delete pfiglio[SIN]; delete pfiglio[DES];}
};

template <class T>
class AlberoB
{
public:
	SNodo<T>* pradice; // puntatore alla radice

	//	FUNZIONI NON COSTANTI
    AlberoB () : pradice(0) {};

    AlberoB ( const T& a) {
        pradice = new SNodo<T>(a);
    };

	//	inserisce l'albero AC come figlio d = SIN/DES
    void insFiglio ( Direzione d, AlberoB& AC ) {
        assert( !nullo() );
        assert( figlio(d).nullo() );
        if ( !AC.nullo() ) {
            pradice->pfiglio[d]=AC.pradice;
            AC.pradice->ppadre=pradice;
        }
    };

	// 	estrae il figlio d = SIN/DES
    AlberoB<T> estraiFiglio ( Direzione d ) {
        assert( !nullo() );
        AlberoB<T> A = figlio(d);
        A.pradice->ppadre=0;
        pradice->pfiglio[d] = 0;
        return A;
    };

    // modifica il contenuto informativo della radice
    void modRadice ( const T& a ) {
        assert( !nullo() );
        pradice->vinfo = a;
    };

	// svuota l'albero cancellandone tutti i nodi
    void svuota() { delete pradice; pradice = 0; };

	// svuota l'albero ma senza cancellare i nodi
    void annulla() { pradice = 0; };

    //	FUNZIONI COSTANTI
	bool nullo() const { return pradice == 0; };

	// restituisce una copia dell'albero
    AlberoB<T> copia () const {
        if ( nullo() ) return AlberoB<T>();
        AlberoB<T> AC(radice());
        AlberoB<T> fs = figlio(SIN).copia();
        AlberoB<T> fd = figlio(DES).copia();
        AC.insFiglio(SIN,fs);
        AC.insFiglio(DES,fd);
        return AC;
    } ;

	//	mostra l'info della radice
    const T& radice () const {
        assert( !nullo() ); // se sto chaimando radice su un albero nullo => esegui l'assert
        return pradice->vinfo;
    };

	// restituisce true se la radice è nodo foglia
    bool foglia () const {
        return !nullo()&&figlio(SIN).nullo()&& figlio(DES).nullo();
    };

	// restituisce il figlio d = SIN/DES
    AlberoB<T> figlio ( Direzione d ) const {
        assert( !nullo() );
        AlberoB<T> AC;
        AC.pradice = pradice->pfiglio[d];
        return AC;
    };

	//	restituisce il padre eventualmente nullo
    AlberoB<T> padre () const {
        assert( !nullo() );
        AlberoB<T> AC;
        AC.pradice = pradice->ppadre;
        return AC;
    };

    int valutaEspressioneAritmetica(const AlberoB<string>& albero) {
        if (albero.nullo()) {
            // L'albero è vuoto, quindi l'espressione non ha valori
            return 0;
        }

        string radice = albero.radice();

        // Se la radice è un operando numerico, restituisci il suo valore convertito in intero
        if (radice != "+" && radice != "-" && radice != "*" && radice != "/") {
            return stoi(radice);
        }

        // La radice è un operatore aritmetico, valuta i sottoalberi ricorsivamente
        int risultato = 0;
        int figlioSinistro = valutaEspressioneAritmetica(albero.figlio(SIN));
        int figlioDestro = valutaEspressioneAritmetica(albero.figlio(DES));

        if (radice == "+") {
            risultato = figlioSinistro + figlioDestro;
        } else if (radice == "-") {
            risultato = figlioSinistro - figlioDestro;
        } else if (radice == "*") {
            risultato = figlioSinistro * figlioDestro;
        } else if (radice == "/") {
            risultato = figlioSinistro / figlioDestro;
        }

        return risultato;
    }
};

int main() {
    // Creazione dell'albero rappresentante l'espressione aritmetica: 3 + (4 * 5)

    // Creazione dei nodi dell'albero
    SNodo<string>* nodo1 = new SNodo<string>("+");
    SNodo<string>* nodo2 = new SNodo<string>("3");
    SNodo<string>* nodo3 = new SNodo<string>("*");
    SNodo<string>* nodo4 = new SNodo<string>("4");
    SNodo<string>* nodo5 = new SNodo<string>("5");

    // Collegamento dei nodi
    nodo1->pfiglio[SIN] = nodo2;
    nodo1->pfiglio[DES] = nodo3;

    nodo3->pfiglio[SIN] = nodo4;
    nodo3->pfiglio[DES] = nodo5;

    nodo2->ppadre = nodo1;
    nodo3->ppadre = nodo1;
    nodo4->ppadre = nodo3;
    nodo5->ppadre = nodo3;

    // Creazione dell'albero
    AlberoB<string> albero;
    albero.pradice = nodo1;

    // Valutazione dell'espressione aritmetica
    int risultato = albero.valutaEspressioneAritmetica(albero);

    // Stampare il risultato
    cout << "Il risultato dell'espressione aritmetica è: " << risultato << endl;

    // Deallocazione dei nodi dell'albero
    delete nodo1;
    delete nodo2;
    delete nodo3;
    delete nodo4;
    delete nodo5;

    return 0;
}
