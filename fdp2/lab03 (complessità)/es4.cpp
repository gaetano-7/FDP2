#include <iostream>
using namespace std;

bool somma(int M[][N]) {
    for(int i = 0; i < N; ++i) {
        if(M[i][i] != 0) {
            for(int j = 0; j < N; ++j) {
                s += M[i][j];
            }
        }
    }
    return s > 0;
}

bool elabora(int M[][N], int V[N]) {
    bool b =false;
    int i = 1;
    
    while(i <= N and not b) {
        if(somma(M) || V[i-1] == 0) {
            b =true;
        }
        i = i + 2;
    }
    return b;
}