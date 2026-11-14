#include <bits/stdc++.h>
using namespace std;
// how many unique BST can be formed of n unique integer, non negative

int solve(int n, vector<int>& dp){
    if(n==0)return 1;

    if(dp[n]!=-1)return dp[n];

    int ans=0;

    for(int i=1;i<=n;i++){
        int left=solve(i-1,dp);
        int right=solve(n-i,dp);

        ans+=left*right;
    }

    return dp[n]=ans;
}

int uniqueBST(int n){
    vector<int>dp(n+1,-1);

    return solve(n,dp);
}

int main(){

    return 0;
}