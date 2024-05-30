#include <iostream>
using namespace std;

const int n=5;

int somm(int A[],int n){
    int sum=0;
    for (int i=0;i<n;i++){
        sum+=A[i];
    }
    return sum;
}

int main(){
    int A[n];
    for (int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<somm(A,n)<<endl;
    return 0;
}

