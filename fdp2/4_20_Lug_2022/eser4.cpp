#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <stack>
#include <map>

int val(string stringa){
    if(stringa=="ab"){
        return 11;
    }
    else if(stringa=="cde"){
        return 11;
    }
    else if(stringa=="xyz"){
        return 12;
    }
    else if(stringa=="q"){
        return 8;
    }
    else if(stringa=="q42"){
        return 7;
    }
    else if(stringa=="8a8b"){
        return 34;
    }
    else if(stringa=="ccc"){
        return 23;
    }
    else{
        return 0;
    }
}

bool esercizio4(vector<string>S){
    vector<vector<string>> sottoinsiemi;
	vector<string> stt_insieme;
	stack<pair<int, vector<string>>> s;
	s.push({0, stt_insieme});

	while(!s.empty()){
		pair<int, vector<string>> top = s.top();
		int index = top.first;
		vector<string> stt_insieme = top.second;
		s.pop();
		sottoinsiemi.push_back(stt_insieme);
		for(int i = index; i < S.size(); i++){
			stt_insieme.push_back(S[i]);
			s.push({i+1,stt_insieme});
			stt_insieme.pop_back();
		}
	}
    
    int somma1 = 0;
    int somma2 = 0;
    int check;
    string att;
    for(int i = 0; i < sottoinsiemi.size(); i++){
        for(int j = 0; j < sottoinsiemi[i].size(); j++){
            somma1+=val(sottoinsiemi[i][j]);
        }
        for(int k = 0; k < S.size(); k++){
            att = S[k];
            for(int j = 0; j < sottoinsiemi[i].size();j++){
                if(att==sottoinsiemi[i][j]){
                    check++;
                }
            }
            if(check==0){
                somma2+=val(att);
            }
            check = 0;
        }
        if(somma1 == somma2){
            return true;
        }
        somma1 = 0;
        somma2 = 0;
    }
    return false;
}

int main(){
    vector<string> S = {"ab","cde","xyz","q","q42","8a8b","ccc"};

    cout<<boolalpha<<esercizio4(S);

    return 0;
}