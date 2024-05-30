#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <stack>
#include <map>

bool esercizio4(vector<string>V, vector<vector<string>>L, int q){
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

		for(int i = index; i < V.size(); i++){
			stt_insieme.push_back(V[i]);
			s.push({i+1,stt_insieme});
			stt_insieme.pop_back();
		}
	}

    //------------------------------------

    string att;
    int cont = 0;
    for(int i = 0; i < sottoinsiemi.size(); i++){
        if(sottoinsiemi[i].size() >= q){
            for(int j = 0; j < sottoinsiemi[i].size(); j++){
                for(int x = 0; x < L.size(); x++){
                    for(int y = 0; y < L[x].size(); y++){
                        att = L[x][y];
                        for(int k = 0; k < sottoinsiemi[i].size(); k++){
                            if(sottoinsiemi[i][k]==att){
                                cont++;
                            }
                        }
                    }
                    cont = 0;
                }
                if(cont < q){
                    return true;
                }
                cont = 0;
            }    
        }    
    }
    return false;
}

int main(){
    vector<string> S = {"a","b","c","d","e","f"};
	vector<vector<string>> L = {{"a","b","c"},
                                {"a","d"},
                                {"d","e"},
                                {"b","f"}};
                                
	cout<<boolalpha<<esercizio4(S,L,3)<<endl;

    return 0;
}