#include <iostream>
using namespace std;

int potenza(int a,int b);

int main(){
    int a,b,pot;
    cin>>a>>b;
    pot=potenza(a,b);
    cout<<pot;
    return 0;   
}

int potenza(int a,int b){
    int potenza=1;
    for(int i=1;i<=b;i++){
        potenza=potenza*a;
    }
    return potenza;
}
