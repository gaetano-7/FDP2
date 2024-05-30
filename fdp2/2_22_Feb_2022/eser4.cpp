#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <stack>
#include <map>

bool esercizio4(vector<string>V, vector<vector<string>>C){
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

    
}

int main(){
    int n = 5;
    vector<string> A = {"a", "b", "c", "d", "e"};
    vector<vector<string>> C = {{"a", "e", "d"}, 
                                {"b", "c", "d"},
                                {"c", "a", "b"}, 
                                {"d", "e", "c"}};
    
    esercizio4(A,C);

    return 0;
}