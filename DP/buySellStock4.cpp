#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(vector<int>& a, int n, int i, int k, vector<vector<int>>& dp){
        if(i==n)return 0;

        if(k==0)return 0;

        if(dp[i][k]!=-1){
            return dp[i][k];
        }

        if(k%2==0){
            int buy=solve(a,n,i+1,k-1,dp)-a[i];
            int skip=solve(a,n,i+1,k,dp);

            return dp[i][k]=max(buy,skip);
        }else{
            int sell=solve(a,n,i+1,k-1,dp)+a[i];
            int skip=solve(a,n,i+1,k,dp);

            return dp[i][k]=max(sell,skip);
        }
    }

    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();

        vector<vector<int>> dp(n,vector<int>(k*2+1,-1));

        return solve(prices,n,0,k*2,dp);
    }
};

int main(){
    vector<int> prices={2,4,1,7,3,6};
    int k=2;
    Solution s;
    cout<<s.maxProfit(k,prices)<<endl;

}