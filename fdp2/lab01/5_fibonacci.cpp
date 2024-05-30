#include <iostream>
using namespace std;

int main(){
    int n,n1=0,n2=1;
    cin>>n;
    if (n==0) cout<<n<<endl;
    if (n==1) cout<<n<<endl;
    else
    for(int i=2;i<n;i++){
        n=n1+n2;
        n1=n2;n2=n;
        cout<<n<<endl;
    } 
    return 0;
}