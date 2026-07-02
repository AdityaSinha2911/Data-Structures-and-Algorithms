#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
*/

int minSubArrayLen(vector<int>& nums,int target){
    int n=nums.size();
    int low, high, sum;
    low=high=sum=0;

    int ans= INT_MAX;

    while(high<n){
        sum+=nums[high];
        
        while(sum>=target){
            int len=high-low +1;
            ans = min(ans,len);

            sum -=nums[low];
            low++;
        }

        high++;
    }

    if(ans==INT_MAX) return 0;

    return ans;

}

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    cout << "Minimum Length: " << minSubArrayLen(nums, target) << endl;

    return 0;
}