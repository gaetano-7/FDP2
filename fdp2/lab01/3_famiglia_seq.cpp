#include <iostream>
using namespace std;

int main(){
    int x;
    int card=0,max=0,lilla=0;
    cin>>x;
    while (x>=0){
        if(x!=0){
            card++;
        }
        if(x==0){
            lilla++;
            card=0;
        }
        if(card>max) max=card;
        cin>>x;
    }
    cout<<"la cardinalita' della famiglia e': "<<lilla<<endl;
    cout<<"l'insieme di cardinalita' massima e': "<<max<<endl;
    return 0;
}