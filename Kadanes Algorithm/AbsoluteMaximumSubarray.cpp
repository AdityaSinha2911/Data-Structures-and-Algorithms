#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:

    int maxAbsoluteSum(vector<int>& nums){
        int currMaxSum=nums[0];
        int maxSum=nums[0];

        int currMinSum=nums[0];
        int minSum=nums[0];

        for(int i=1;i<nums.size();i++){
            currMaxSum=max(nums[i],currMaxSum+nums[i]);
            maxSum=max(currMaxSum,maxSum);

            currMinSum=min(nums[i],currMinSum+nums[i]);
            minSum=min(currMinSum,minSum);
        }

        return max(abs(minSum),abs(maxSum));
    }
};

int main(){
    Solution obj;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int maxAbsSum = obj.maxAbsoluteSum(nums);
    cout << "Maximum Absolute Subarray Sum: " << maxAbsSum << endl; // Output: Maximum Absolute Subarray Sum: 6
    return 0;
}