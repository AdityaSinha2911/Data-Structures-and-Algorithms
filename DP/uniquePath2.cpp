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

// int uniquePath(vector<vector<int>>& grid){
//     int n=grid.size();
//     int m=grid[0].size();

//     vector<vector<int>> dp(n,vector<int>(m,-1));

//     return solve(grid,0,0,dp);
// }



// tabulation method
int uniquePath(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Starting cell is an obstacle
        if (obstacleGrid[0][0] == 1)
            return 0;

        // Starting point
        dp[0][0] = 1;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                // Starting cell already initialized
                if (i == 0 && j == 0)
                    continue;

                // Obstacle => no path
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }

                // From top
                if (i > 0)
                    dp[i][j] += dp[i - 1][j];

                // From left
                if (j > 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }

        return dp[n - 1][m - 1];
}

int main(){
    vector<vector<int>> grid={{0,0,0},{0,1,0},{0,0,0}};
    cout<<uniquePath(grid)<<endl; // Output: 2
    return 0;
}