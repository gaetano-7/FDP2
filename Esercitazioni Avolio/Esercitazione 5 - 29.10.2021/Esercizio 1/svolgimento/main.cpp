#include "Studente.h"
#include <limits>
#include <iostream>
using namespace std;

bool bestStudents(Studente studenti[], unsigned numeroStudenti);
unsigned numeroEsamiAllaLaurea(Studente studenti[], unsigned numeroStudenti);

int main(){

    cout << "Inserisci il numero di studenti: ";
    int numero_studenti; cin >> numero_studenti;

    Studente* studenti = new Studente[numero_studenti];

    for(int i = 0; i < numero_studenti; i++)
    {
        cout << "Sto inserendo lo studente numero " << (i+1) << endl;
        cin >> studenti[i];
    }

    //TEST METODI
    /*if(bestStudents(studenti, numero_studenti))
        cout << "Tutti best student" << endl;
    else
        cout << "Non tutti best student" << endl;
    */
    cout << "Numero esami alla laurea " << numeroEsamiAllaLaurea(studenti, numero_studenti);
    delete [] studenti;
    
    return 0;

}

//restituisce true se tutti gli studenti nell'array hanno una media ponderata maggiore o uguale a 28
bool bestStudents(Studente studenti[], unsigned numeroStudenti){

    for(int i = 0; i < numeroStudenti; ++i)
        if(studenti[i].getMediaPonderata() < 28)
            return false;
    
    return true;
}

//restituisce il numero di esami che restano da sostenere allo studente piu vicino
//alla laurea (supponendo che siano 24)
unsigned numeroEsamiAllaLaurea(Studente studenti[], unsigned numeroStudenti){
    unsigned esami_rimasti = 24;

    for(int i = 0; i < numeroStudenti; ++i)
        if(24 - studenti[i].getEsamiSostenuti() < esami_rimasti)
            esami_rimasti = 24 - studenti[i].getEsamiSostenuti();

    return esami_rimasti;

    //IMPLEMENTAZIONE ALTERNATIVA
    // int n_esami_massimo;
    // return 24-n_esami_massimo;
}

//restituisce true se s1 e s2 hanno sostenuto lo stesso numero di esami e hanno ottenuto la
//stessa votazione per lo stesso numero di esami
//ESEMPIO: s1 -> Fondamenti 24, Analisi 24, Basi di dati 25 - 
//         s2 -> Analisi 25, Matematica Discreta 24, Inglese 24
bool stessiVoti(const Studente& s1, const Studente& s2){
    if(s1.getEsamiSostenuti() != s2.getEsamiSostenuti()) return false;

    int esami_per_voti[31];
    for(int i = 0; i < 31; ++i)
        esami_per_voti[i] = 0;

    // 24 24 25
    // 25 24 24

    //esami_per voti = 0 0 0 0 0 ...0 0 0 0 0 0 0 0 0 0
    for(int i = 0; i < s1.getEsamiSostenuti(); ++i){
        esami_per_voti[s1.getVotoI(i)] ++;
        esami_per_voti[s2.getVotoI(i)] --;
    }

    for(int i = 0; i < 31; ++i)
        if(esami_per_voti[i] != 0)
            return false;
    
    return true;

}

//tra tutti gli studenti aventi al piu 20 anni e che hanno sostenuto almeno 3 esami, restituisce la matricola di quello 
//con la media dei voti maggiore. A parita  di media voti, restituire lo studente piu giovane
//se non esiste alcuno studente con tali caratteristiche, restituire la stringa "---"
string getMatricolaStudenteGiovaneEBravo(Studente studenti[], unsigned numeroStudenti){
    string matricola = "---";
    float mediaVoti = 0;
    unsigned eta = numeric_limits<unsigned>::max();

    for(int i = 0; i < numeroStudenti; ++i)
        if(studenti[i].getEta()<=20 && studenti[i].getEsamiSostenuti()>=3)
            if(studenti[i].getMediaVoti()>mediaVoti || (studenti[i].getMediaVoti() == mediaVoti && studenti[i].getEta() < eta))
            {
                matricola = studenti[i].getMatricola();
                mediaVoti = studenti[i].getMediaVoti();
                eta = studenti[i].getEta();
            }
    
    return matricola;
}