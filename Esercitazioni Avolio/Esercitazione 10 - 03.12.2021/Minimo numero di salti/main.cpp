#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int jump(vector<int> nums);

int main(){

    vector<int> nums {2,3,1,1,4};
    cout << jump(nums);
}

int jump(vector<int> nums){
    int* salti_da = new int[nums.size()];
    salti_da[nums.size() - 1] = 0; //parte della soluzione

    for(int i = nums.size() - 2; i>=0; i--)
        salti_da[i] = 1 + getMinimoRaggiungibile(i, nums, salti_da);

    return salti_da[0];
}

int getMinimoRaggiungibile(int i, vector<int> nums, int* salti_da){

    int min = INT_MAX - 1;
    for(int j = 1; j <= nums[i] && i+j<nums.size(); j++)
        if(salti_da[i + j] < min)
            min = salti_da[i + j];
    
    return min;

}