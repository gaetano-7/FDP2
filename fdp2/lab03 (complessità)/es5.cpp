#include <iostream>
using namespace std;

bool g(int val, int &V[N]) {
    bool b =false;
    for(int i=0; i < N && !b; i++)
        if(val == V[i])
            b =true;
    return b;
}

int f(int V1[N], int V2[N]) {
    bool b =false;
    int i = 1;
    while(!b && i < N) {
        
        b = g(V1[i], V2) && g(V2[i], V1);
        i = i * 2;
    }
    return i;
}