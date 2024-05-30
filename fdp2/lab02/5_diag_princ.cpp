#include <iostream>
using namespace std;

const int n=4;
void riempi_mat(int m[][n]);
int somm_diag_pri(int m[][n]);

int main(){
    int a[n][n];
    int b[n][n];
    int som_a=0;
    int som_b=0;
    riempi_mat(a);
    riempi_mat(b);
    som_a=somm_diag_pri(a);
    som_b=somm_diag_pri(b);
    if(som_a==som_b)
        cout<<"La somma della diagonale di A e' uguale a quella di B"<<endl;
    else
        cout<<"La somma non e' uguale"<<endl;
    return 0;
}

void riempi_mat(int m[][n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>m[i][j];
}

int somm_diag_pri(int m[][n]){
    int f=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i==j){
                f+=m[i][j];
            }
    return f;
}