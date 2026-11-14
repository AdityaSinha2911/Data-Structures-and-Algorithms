#include <bits/stdc++.h>
using namespace std;

int solve(string word1,string word2, int i, int j, vector<vector<int>>& dp){
    if(i==0)return j;

    if(j==0)return i;

    if(dp[i][j]!=-1)return dp[i][j];

    if(word1[i-1]==word2[j-1]){
        return dp[i][j]=solve(word1,word2,i-1,j-1,dp);
    }

    int insert=solve(word1,word2,i,j-1,dp);
    int delteOp=solve(word1,word2,i-1,j,dp);
    int replace=solve(word1,word2,i-1,j-1,dp);

    return dp[i][j]=min({insert,delteOp},replace);
}

int targetSum(string word1,string word2){
    int n=word1.size();
    int m=word2.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

    return solve(word1,word2,n,m,dp);
}



int main(){
    string word1="abc";
    string word2="abbc";

    cout<<targetSum(word1,word2);

    return 0;
}
