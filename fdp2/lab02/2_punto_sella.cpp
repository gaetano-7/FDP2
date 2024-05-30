#include <iostream>
using namespace std;

const int rig= 4;
const int col= 4;

int riempi(int m[][col]){
    for (int i=0;i<rig;i++){
        for (int j=0;j<col;j++){
            cin>>m[i][j];
        }
    }
    return m[rig][col];
}

void printa(int m[][col]){
    for (int i=0;i<rig;i++){
        for (int j=0;j<col;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
}

int max_col(int m[][col],int colo){
    int mass=0;
    for (int i=0;i<rig;i++){
        if(m[i][colo]>mass){
            mass=m[i][colo];
        }
    }
    return mass;
}

int max_rig(int m[][col],int riga){
    int mass=0;
    for (int i=0;i<rig;i++){
        if(m[riga][i]>mass){
            mass=m[riga][i];
        }
    }
    return mass;
}

int main(){
    int m[rig][col]={};
    riempi(m);
    printa(m);
    for (int i=0;i<rig;i++){
        for (int j=0;j<col;j++){
            if (m[i][j]==max_col(m,j) && m[i][j]==max_rig(m,i)){
                cout<<"punto di sella: "<<m[i][j]<<" in posizione: "<<i<<" e "<<j<<endl;
            }
        }
    }

    return 0;
}