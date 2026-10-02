#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
    int n=grid.size();
    int m=grid[0].size();

    if(i==n-1 || j==m-1){
        return 1;
    }

    if(grid[i][j]==1){
        return 0;
    }

    if(dp[i][j]!= -1){
        return dp[i][j];
    }

    int count=0;

    if(i+1<n){
        count+=solve(grid,i+1,j,dp);
    }
    
    if(j+1<m){
        count+=solve(grid,i,j+1,dp);
    }

    return dp[i][j]=count;
}

int uniquePath(vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();

    vector<vector<int>> dp(n,vector<int>(m,-1));

    return solve(grid,0,0,dp);
}

int main(){
    vector<vector<int>> grid={{0,0,0},{0,1,0},{0,0,0}};
    cout<<uniquePath(grid)<<endl; // Output: 2
    return 0;
}