// ES.2
#include <iostream>
using namespace std;

bool lte_5(int a[],int n){
    for(int i=0;i<n;i++){
        if(a[i]<=5){
            return true;
        }
    }
    return false;
}

bool gt_5(int a[],int n){
    for(int i=0;i<n;i++){
        if(a[i]>5){
            return true;
        }
    }
    return false;
}

int main(){
    const int n=5;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        if(lte_5(a,n) or gt_5(a,n)) return 0;
    }
    return 0;
}