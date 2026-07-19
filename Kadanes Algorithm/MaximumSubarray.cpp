#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        int maxSubarray(vector<int> &nums){
            int currSum=nums[0];
            int maxSum=nums[0];

            for(int i=1;i<nums.size();i++){
                int extendedSum=currSum+nums[i];

                if(nums[i]>extendedSum){
                    currSum=nums[i];
                }else{
                    currSum=extendedSum;
                }

                if(currSum > maxSum){
                    maxSum=currSum;
                }
            }

            return maxSum;
        }

};

int main(){
    Solution obj;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int maxSum = obj.maxSubarray(nums);
    cout << "Maximum Subarray Sum: " << maxSum << endl; // Output: Maximum Subarray Sum: 6
    return 0;
}