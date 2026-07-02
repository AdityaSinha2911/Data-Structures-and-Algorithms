#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

int maximumSumSubarray(vector<int>& nums,int k){
    int n=nums.size();
    int i=0;
    int sum=0;

    while(i<k){
        sum+=nums[i];
        i++;
    }

    int res= sum;

    int low=0;
    int high =k-1;

    while(high<n-1){
        low++;
        high++;
        sum=sum -nums[low-1];
        sum=sum+nums[high];

        res=max(res,sum);
    }

    return res;
}

int main() {
    vector<int> nums = {2, 5, 1, 8, 2, 9, 1};
    int k = 3;

    cout << "Maximum Sum: " << maximumSumSubarray(nums, k) << endl;

    return 0;
}