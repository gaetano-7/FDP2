#include <iostream>
using namespace std;

int main(){
    int n;
    string s;
    while(n>=0){
        s="";
        for(int i=0;i<n;i++){
            s+="*";
        }
        cout<<s<<endl;
        cin>>n;
    }
    return 0;
}