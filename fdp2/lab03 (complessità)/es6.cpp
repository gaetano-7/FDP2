#include <iostream>
using namespace std;

void elabora(int M[][N], int V[N]) {
    bool b =false;
    int j, i = 0;
    char car;
    
    while(i<N && !b) {
        cin >> car;
        switch(car) {
            case'a':
                
                if(f2(V))
                    for(j=0; j<N; j++)
                        cout << M[i][j];
                break;
            case'b':
                
                if(f1(M) && f2(V))
                    b =true;
                else
                    cout << V[i];
                    break;
            default:
                cout << V[i];
        }
        
        for(int x=0; x<N; x++)
            if(M[x][i] != V[x])
                b =true;
        i++;
    }
}