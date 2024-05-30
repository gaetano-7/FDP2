#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>
using namespace std;

bool by_value(const pair<int, int>& a, const pair<int,int>& b) {
    return a.first < b.first; 
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> seq(n);
    for (int i = 0; i < n; ++i) {
        cin >> seq[i].first; 
        seq[i].second = i; 
    }
    sort(seq.begin(), seq.end(), by_value); 
    int sum = 0; 
    cout << "Elementi ottimi: "; 
    for (int i = 0; i < k; ++i) {
        sum += seq[n-1-i].first; 
        cout << seq[n-1-i].first << " ";
    }
    cout << endl; 
    
    cout << "Somma massima: " << sum << endl; 
    
    cout << "Indici elementi ottimi nella sequenza originale: "; 
    for (int i = 0; i < k; ++i) {
        cout << seq[n-1-i].second << " ";
    }
    cout << endl; 
    return 0;
}
