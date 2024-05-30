// ES.1           CASO PEGGIORE: n    CASO MIGLIORE: log.n
#include <iostream>
using namespace std;

int f(int x){
    return x*x+4;
}

int main(){
    int n;cin>>n;
    int p=1;
    for (int i=0;i<n;i++)
        p=p*i;
    cout<<f(p)<<endl;
    return 0;
}
