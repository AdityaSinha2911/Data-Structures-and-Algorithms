#include <iostream>
#include <vector>

using namespace std;

/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can
flip at most k 0's.

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.


Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
*/

int longestOne(vector<int>& nums, int k){
    int low=0;
    int high=0;
    int res=0;
    int zeroCount=0;

    for(int high=0;high<nums.size();high++){
        if(nums[high]==0){
            zeroCount++;
        }

        while(zeroCount>k){
            if(nums[low]==0){
                zeroCount--;
            }

            low++;
        }

        res=max(res,high-low+1);
    }

    return res;
}

int main() {

    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    cout << longestOne(nums, k) << endl;

    return 0;
}