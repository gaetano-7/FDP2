#include <iostream>
using namespace std;

int main(){
    int* matricola = new int[6]{220666};
    cout << *(matricola + 3) << *(matricola + 2) << endl; 
    //cout << *(matricola[0])  << endl; 
    int& a = matricola[4];
    int b = matricola[5];
    --a;b += 1;
    cout << matricola[4] << " " << matricola[5]<< endl;
}
