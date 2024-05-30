#include <iostream>
using namespace std;

int log_disc(int a, int b);

int main(){
    int a; int b;
    int c=0;
    cin>>a>>b;
    c=log_disc(a,b);
    cout<<c;
    return 0;
}

int log_disc(int a, int b){
    int c=0;
    int potenza=1;
    for(int i=1;i<=10;i++){
        potenza=potenza*b;
        if(potenza==a){
            c=i;
        }
    }
    return c;
}