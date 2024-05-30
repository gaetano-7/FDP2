#include <iostream>
using namespace std;

const int n=4;

int riempi_mat(int m[][n]){
    int M[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>m[i][j];
        }
    }
    return m[n][n];
}

void stampa(int m[][n]){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<m[i][j]<<" ";
        }
    cout<<endl;
    }
}

void reverse(int m[][n],int m2[][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            m2[i][j]=m[j][i];
        }
    }
}

void somiglianze(int A2[][n],int B2[][n],int L[n]){
    int k=0;
    while(k!=4){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(A2[k][i]==B2[k][j]){
                    L[k]=A2[k][i];
                }
            }
        }
        k++;
    }
}

int main(){
    int A[n][n]={};
    int B[n][n]={};
    int A2[n][n]={};
    int B2[n][n]={};
    int L[n]={};
    riempi_mat(A);
    riempi_mat(B);
    cout<<"stampa A: "<<endl;
    stampa(A);
    cout<<"stampa B: "<<endl;
    stampa(B);
    reverse(A,A2);
    reverse(B,B2);
    cout<<"stampa reverse A: "<<endl;
    stampa(A2);
    cout<<"stampa reverse A: "<<endl;
    stampa(B2);
    cout<<"stampa somiglianze: "<<endl;
    somiglianze(A2,B2,L);
    for(int h=0;h<n;h++){
        cout<<L[h]<<" ";
    }
    return 0;
}