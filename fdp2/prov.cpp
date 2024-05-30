// . (fino a 6 punti) Si vuole simulare il movimento di formiche lungo un percorso
// unidimensionale. Si immagini che le formiche siano all’interno di celle di un array
// (ogni cella può contenere al massimo 1 formica), come nella seguente figura:
// Ogni formica ha una posizione ed una direzione iniziale (destra o sinistra) e
// procede lungo tale direzione una cella per volta. Ogni volta che una formica si
// “scontra” con l’estremità sinistra o destra dell’array, o si scontra con un’altra
// formica, cambia la sua direzione. Di seguito una possibile implementazione non
// parallela che riproduce il comportamento sopradescritto:
// Le funzioni setVariables() e setPosDir() (omesse per brevità ) servono
// per il setup iniziale, ovvero stabilire quante formiche e quante celle ci sono, e la
// posizione e la direzione iniziale di ciascuna formica. In pratica, prima dell’invocazione
// della funzione init(), nel main(), l’array ants conterrà le informazioni di
// tutte le formiche (ovvero la posizione e la direzione iniziale).
// Modificare il codice riportato in modo da realizzare una versione parallela in MPI,
// nella quale l’array contenente le formiche è suddiviso tra i vari processi MPI che
// dovranno gestire la loro porzione dell’array e le formiche ivi contenute (le formiche
// muovendosi possono passare da un processo all’altro).
// In particolare si richiede l’implementazione delle funzioni init() e move() (ed
// eventuali dichiarazioni di variabili). Si aggiungano, inoltre, le inizializzazioni MPI
// necessarie all’inizio del main() (ovvero prima dell’invocazione della funzione
// setVariables()).
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "mpi.h"
using namespace std;

struct ant{
    int pos;
    int dir;
};

ant* ants;
int nAnts;
int nCells;
ant** readV;
ant** writeV;

int rank;
int size;

void init(){

    readV = new ant*[nCells];
    writeV = new ant*[nCells];

    for(int i=0; i<nAnts; i++){

        readV[ants[i].pos]=&ants[i];
    }

}

void move(){

    for(int i=0;i<nCells;i++){

        writeV[i]=NULL;
        if (i>0 && readV[i-1]!=NULL && readV[i-1]->dir==1 && readV[i]==NULL){
            //arriva il vicino da sinistra
            writeV[i]=new ant;
            *(writeV[i])=*(readV[i-1]);
            writeV[i]->pos++;
        } else if (i<nCells-1 && readV[i+1]!=NULL && readV[i+1]->dir==-1 && readV[i]==NULL){
            //arriva il vicino da destra
            writeV[i]=new ant;
            *(writeV[i])=*(readV[i+1]);
            writeV[i]->pos--;
        }else if (readV[i]!=NULL && (i+readV[i]->dir<0 || i+readV[i]->dir>nCells-1 || readV[i+readV[i]->dir]!=0)){
            //caso in cui cambio direzione
            writeV[i]=new ant;
            *(writeV[i])=*(readV[i]);
            writeV[i]->dir*=-1;
        }
    }
    ant** p=readV;
    readV=writeV;
    writeV=p;

}

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    setVariables(nAnts,nCells);
    ants = new ant[nAnts];
    for(int i=0; i<nAnts; i++){
        setPosDir(i, ants[i].pos, ants[i].dir);
    }
    init();
    while(true){
        move();
    }
    return 0;
}
