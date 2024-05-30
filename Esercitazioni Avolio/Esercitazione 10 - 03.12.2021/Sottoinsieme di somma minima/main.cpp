#include <iostream>
#include <vector>
using namespace std;
vector<int>::iterator sceltaGolosa(vector<int>& nums);
int getSommaMinima(vector<int> nums, int k);

int main(){
    vector<int> nums = {5, 7, 1, 0, -1};
    int k = 2;
    cout << getSommaMinima(nums, k);
}

int getSommaMinima(vector<int> nums, int k){
    int sum = 0;

    //complessità O(k n) = O(n^2)
    for(int i = 0; i < k; i++){
        vector<int>::iterator it_min = sceltaGolosa(nums);
        sum += *it_min;
        nums.erase(it_min);
    }
    return sum;
}

vector<int>::iterator sceltaGolosa(vector<int>& nums){
    vector<int>::iterator it_min = nums.begin();

    for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        if(*it < *it_min)
            it_min = it;
    
    return it_min;
}

//ORDINAMENTO O(n logn)
//Scelta dei primi k O(k)