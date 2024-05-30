#include <iostream>
using namespace std;

const int dim=5;

int main(){
    int A[dim],max;
    for (int i=0; i<dim;i++){
        cin>>A[i];
    }
    max=A[0];
    for(int i=0;i<dim;i++){
        if(A[i]>max){
            max=A[i];
        }
    }
    for(int i=0;i<dim;i++){
        cout<<A[i]-max<<endl;
    }
    return 0;
}