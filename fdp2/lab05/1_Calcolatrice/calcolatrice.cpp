#include <iostream>
#include <typeinfo>
using namespace std;

template <typename T>
void Calcolatrice(T num1, string segno, T num2){
    if(segno=="+") cout<<"RISULTATO = "<<(num1+num2)<<endl;
    if(segno=="-") cout<<"RISULTATO = "<<(num1-num2)<<endl;
    if(segno=="/") cout<<"RISULTATO = "<<(num1/num2)<<endl;
    if(segno=="*") cout<<"RISULTATO = "<<(num1*num2)<<endl;
}

int main(){
    int acc;
    cout<<"per accendere la calcolatrice invia 1, 0 per spegnerla"<<endl;
    cin>>acc;
    while(acc!=0){
        int tipo;
        cout<<"CALCOLATRICE ACCESA"<<endl;
        cout<<"scegli il tipo di numeri che vuoi usare:"<<endl;
        cout<<"1: INT, 2: FLOAT, 3: DOUBLE"<<endl;
        cin>>tipo;
        if(tipo==1){
            cout<<"hai scelto il tipo INT"<<endl;
            int n1_in; string segn_in; int n2_in;
            cout<<"inserisci un operazione con numeri di tipo INT:"<<endl;
            cin>>n1_in;
            cin>>segn_in;
            cin>>n2_in;
            Calcolatrice(n1_in,segn_in,n2_in);
        }
        if(tipo==2){
            cout<<"hai scelto il tipo FLOAT"<<endl;
            float n1_fl; string segn_fl; float n2_fl;
            cout<<"inserisci un operazione con numeri di tipo FLOAT:"<<endl;
            cin>>n1_fl;
            cin>>segn_fl;
            cin>>n2_fl;
            Calcolatrice(n1_fl,segn_fl,n2_fl);
        }
        if(tipo==3){
            cout<<"hai scelto il tipo DOUBLE"<<endl;
            double n1_do; string segn_do; double n2_do;
            cout<<"inserisci un operazione con numeri di tipo DOUBLE:"<<endl;
            cin>>n1_do;
            cin>>segn_do;
            cin>>n2_do;
            Calcolatrice(n1_do,segn_do,n2_do);
        }
        cout<<"1 per continuare ad usare la calcolatrice, 0 per spegnerla"<<endl;
        cin>>acc;
    }
    if(acc==0) cout<<"CALCOLATRICE SPENTA"<<endl;
    return 0;
}