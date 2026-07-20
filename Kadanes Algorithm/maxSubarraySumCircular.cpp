#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        int maxSubarraySumCircular(vector<int> &nums){
            int currMaxSum=nums[0];
            int maxSum=nums[0];

            int currMinSum=nums[0];
            int minSum=nums[0];

            int totalSum=nums[0];

            for(int i=1;i<nums.size();i++){
                totalSum+=nums[i];

                currMaxSum=max(nums[i],currMaxSum+nums[i]);
                maxSum=max(currMaxSum,maxSum);

                currMinSum=min(nums[i],currMinSum+nums[i]);
                minSum=min(currMinSum,minSum);
            }

            if(totalSum==minSum){
                return maxSum;
            }

            return max(maxSum,totalSum-minSum);
        }
};

int main(){
    Solution obj;
    vector<int> nums = {1,-2,3,-2};
    int maxCircularSum = obj.maxSubarraySumCircular(nums);
    cout << "Maximum Circular Subarray Sum: " << maxCircularSum << endl; // Output: Maximum Circular Subarray Sum: 3
    return 0;
}