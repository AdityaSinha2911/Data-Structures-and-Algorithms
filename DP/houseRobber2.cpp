#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int i, vector<int>& dp){
    if(i==0)return nums[0];

    if(i<0)return 0;

    if(dp[i]!=-1)return dp[i];

    int c1=nums[i]+solve(nums,i-2,dp);
    int c2=solve(nums,i-1,dp);

    return dp[i]=max(c1,c2);
}

int rob(vector<int>& nums){
    int n=nums.size();

    if(n==1)return nums[0];

    vector<int>first(nums.begin(),nums.end()-1);
    vector<int> dp1(n,-1);

    int c1=solve(first, n-2,dp1);
    
    vector<int>second(nums.begin()+1,nums.end());
    vector<int> dp2(n,-1);

    int c2=solve(second,n-2,dp2);

    return max(c1,c2);
}

int main(){
    // driver function
}