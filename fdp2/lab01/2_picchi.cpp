#include <iostream>
using namespace std;

int main(){
    int prec=0, corr=0, succ=0;
    int n_dati=0, n_picchi=0;
    cin>>succ;
    while(succ>=0){
        n_dati++;
        if(n_dati >=3)
            if((prec<corr) && (corr>succ))
            {   
                cout<<"Trovato picco: "<<corr<<" nel giorno: "<<n_dati -1<<endl;  
                n_picchi++;
            }
        prec=corr;
        corr=succ;
        cin>>succ;
    }
    cout<<"Numero di picchi massimi rilevati: "<<n_picchi<<endl;
    cout<<"Numero dei dati letti: "<<n_dati<<endl;
    return 0;
}