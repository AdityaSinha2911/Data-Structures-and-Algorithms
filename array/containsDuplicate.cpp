#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool containDuplicate(vector<int>& nums){
    sort(nums.begin(),nums.end());

    for(int i =1; i<nums.size();i++){
        if(nums[i]==nums[i-1]){
            return true;
        }
    }

    return false;
}

int main(){
    vector<int> nums={1,3,5,2,3,9};
    if(containDuplicate(nums)==1){
        cout<<"True";
    }else{
        cout<<"False";
    }

    return 0;
}