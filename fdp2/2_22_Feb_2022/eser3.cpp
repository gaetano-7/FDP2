#include <iostream>
#include <vector>
#include <assert.h>
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
protected:
	SNodo<T>* pradice; // puntatore alla radice
public:

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

	// Restituisce l'informazione contenuta nella radice
    const T& radice () const {
        assert( !nullo() ); // se sto chaimando radice su un albero nullo => esegui l'assert
        return pradice->vinfo;
    };

	// Restituisce true se la radice è un nodo foglia (senza figli)
    bool foglia () const {
        return !nullo()&&figlio(SIN).nullo()&& figlio(DES).nullo();
    };

	// Restituisce il figlio nella direzione `d` (SIN o DES)
    AlberoB<T> figlio ( Direzione d ) const {
        assert( !nullo() );
        AlberoB<T> AC;
        AC.pradice = pradice->pfiglio[d];
        return AC;
    };

	//	restituisce il padre dell'albero eventualmente nullo
    AlberoB<T> padre () const {
        assert( !nullo() );
        AlberoB<T> AC;
        AC.pradice = pradice->ppadre;
        return AC;
    };
};

// ---------------------------------------------- 

bool isHeap(const AlberoB<int> & a, int precedente);

template<typename T>
AlberoB<T> vecToAlbero(const vector<T>& valori);

template<typename T>
void stampaAlbero(const AlberoB<T>&,int=0);

vector<int>esercizio3(const AlberoB<int>&a, int x, vector<int> lista);

template<typename T>
    AlberoB<T> vecToAlbero(const vector<T>& vettore)
    {
        AlberoB<T> albero(vettore[0]);

        vector<AlberoB<T>> alberi;
        alberi.push_back(albero);

        for (int i = 1; i < vettore.size(); i++)
        {
            //nota che in alberi inseriamo una copia dell'albero "nuovo", ma avendo internamente dei puntatori,
            //gli alberi che troviamo nel vector sono quelli reali
            AlberoB<T> nuovo(vettore[i]);
            alberi.push_back(nuovo);

            if(i % 2 == 1)
                alberi[ (i-1) / 2 ].insFiglio(SIN, nuovo);
            else
                alberi[ (i-1) / 2 ].insFiglio(DES, nuovo);
                
        }

	    return albero;
    }

template<typename T>
    void stampaAlbero(const AlberoB<T>& tree, int depth) {
        if (tree.nullo()) { 
            return;
        }
        for (int i = 0; i < depth; ++i) {
            cout << "  ";
        }
        cout << tree.radice() << endl; 
        stampaAlbero(tree.figlio(SIN), depth+1);
        stampaAlbero(tree.figlio(DES), depth+1);
    }

bool isHeap(const AlberoB<int>&a, int precedente){
        if(a.nullo()){
            return true;
        }
        cout<<"PRECEDENTE: "<<precedente<<endl;
        if(a.radice() >= precedente){
            precedente = a.radice();
        }
        else{
            return false;
        }
        cout<<"ATTUALE: "<<a.radice()<<endl;
        return isHeap(a.figlio(SIN),precedente) and isHeap(a.figlio(DES),precedente);
    }

vector<int> esercizio3(const AlberoB<int>&a, int x, vector<int> lista){
    if(a.nullo()){
        return {-1};
    }
    if(a.foglia()){
        if(a.radice()==x){
            lista.push_back(a.radice());
            return lista;
        }
    }
    else{
        lista.push_back(a.radice());
    }
    auto risultato_sin = esercizio3(a.figlio(SIN),x,lista);
    if(risultato_sin[0] != -1){
        return risultato_sin;
    }
    auto risultato_des = esercizio3(a.figlio(DES),x,lista);
    if(risultato_des[0] != -1){
        return risultato_des;
    }
    return {-1};
}

int main(){
    AlberoB<int> T1 = vecToAlbero(vector<int>({5,6,12,10,0,42,32}));
    
    for(int i = 0; i < esercizio3(T1, 10, {}).size(); i++){
        cout<<esercizio3(T1, 10, {})[i]<<" ";
    }

}