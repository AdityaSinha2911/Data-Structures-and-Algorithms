#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& prices,int fees,int i, int holding, vector<vector<int>>& dp){
    if(i==prices.size()){
        return 0;
    }

    if(dp[i][holding]!=-1){
        return dp[i][holding];
    }

    int ans=0;

    if(holding==0){
        // We can buy or skip
        int buy=-prices[i]+solve(prices,fees,i,1,dp);
        int skip=solve(prices,fees,i+1,0,dp);

        ans=max(buy,skip);
    }else{
        int sell=prices[i]-fees + solve(prices,fees,i,0,dp);
        int skip=solve(prices,fees,i+1,1,dp);

        ans=max(sell,skip);
    }
    return dp[i][holding]=ans;
}

int maxProfit(vector<int>& prices,int fees){
    int n=prices.size();

    vector<vector<int>>dp(n,vector<int>(2,-1));

    return solve(prices,fees,0,0,dp);
}

int main(){
    vector<int> prices={1,3,2,8,4,9};
    int fees=2;
    cout<<maxProfit(prices,fees)<<endl;
    return 0;
}