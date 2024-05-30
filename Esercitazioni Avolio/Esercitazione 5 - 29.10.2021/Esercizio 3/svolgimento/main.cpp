#include <iostream>
using namespace std;

#include "DocumentoMP3.h"
int main(){

    DocumentoMP3* d1 = new DocumentoMP3("matteo","esame", 100, 5.0);

    cout << d1->getProprietario(); //matteo
    

}