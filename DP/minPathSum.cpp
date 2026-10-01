#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        // Base Case 
        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }
        
        // Base Case , boundary check
        if (i >= m || j >= n) {
            return INT_MAX; 
        }
        
        //  Check if already calculated 
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        // Down move karo
        int down = solve(i + 1, j, m, n, grid, dp);
        
        // Right move karo
        int right = solve(i, j + 1, m, n, grid, dp);
        
        // Current cell ki value add karke dp table me store kare
        return dp[i][j] = grid[i][j] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // DP table ko -1 se initialize karte hain
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, m, n, grid, dp);
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << s.minPathSum(grid) << endl; // Output: 7
    return 0;
}