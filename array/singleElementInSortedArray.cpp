#include <iostream>
#include <vector>

using namespace std;

// leetcode question:540

// Check if the unique element is at the beginning

// Check if the unique element is at the end

// Traverse the middle of the array to find the element
// whose left and right neighbors are different

int numCountOne(vector<int>& nums){
    if(nums.size()==1){
        return nums[0];
    }

    if(nums[0]!=nums[1]){
        return nums[0];
    }

    if(nums[nums.size()-1] !=nums[nums.size()-2]){
        return nums[nums.size()-1];
    }


    for(int i=1;i<nums.size()-1;i++){
        if(nums[i]!=nums[i-1] && nums[i] != nums[i+1]){
            return nums[i];
        }
    }

    return -1;
}

int main(){
    vector<int> arr={2,3,3,4,4};
    cout<<numCountOne(arr);
}
