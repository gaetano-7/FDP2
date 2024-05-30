#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <stack>
#include <map>

bool esercizio4(int n, vector<vector<int>> lista, int k){
    int att_j;
    int contatore = 0;
    for(int i = 0; i < lista.size(); i++){
        if(lista[i].size()==k){
            for(int j = 0; j < lista.size(); j++){
                if(i!=j){
                    for(int l = 0; l < lista[j].size(); l++){
                        att_j = lista[j][l];
                        for(int p = 0; p < k; p++){
                            if(lista[i][p]==att_j){
                                contatore++;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(contatore==lista.size()-1){
            return true;
        }
        contatore = 0;
    }
    return false;
}

int main(){
    vector<vector<int>> lista = {{3,7,8},{1,2,3,4,5},{5,4,7,0,1},{75,8,80}};
    cout<<esercizio4(5,lista,3)<<endl;
}