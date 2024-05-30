#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

int main(){
    vector<int> nums{2,3,4,5};
    int target = 7;

    vector<int> soluzione = twoSum(nums, target);
    for(int i = 0; i < soluzione.size(); i++)
        cout << "Indice: " << soluzione[i] << " - Valore: " << nums[soluzione[i]] << endl;

    return 0;
}

vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> mappa;
    
    vector<int> soluzione;

    for(int i = 0; i < nums.size(); i++){
        auto it = mappa.find( target-nums[i] );
        
        if(it != mappa.end()){
            cout <<  "Soluzione trovata" << endl;
            soluzione.push_back(i);
            soluzione.push_back(it -> second);
            return soluzione;
        } else{
            mappa.insert( {nums[i], i} );
        }
    }

    return soluzione;
}

/*
2 3 4 5  t = 7

2 -> mappa esiste 7-2 come chiave? No. mappa: 2 -> 0
3 -> mappa esiste 7-3 come chiave? No. mappa: 3 -> 1
4 -> mappa esiste 7-4 come chiave? Si. return vector{2,1}*/