#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n, int m){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
}

int dfs(vector<vector<int>>& a, int i, int j, int n, int m, vector<vector<bool>>& vis){
    int area=1;

    vis[i][j]=true;

    int x[]={-1,1,0,0};
    int y[]={0,0,-1,1};

    for(int k=0;k<4;k++){
        int row=i+x[k];
        int col=j+y[k];

        if(isValid(row,col,n,m)==true && a[row][col]==1 && vis[row][col]==false ){
            area+=dfs(a,row,col,n,m,vis);
        }
    }
    return area;
}

int maxAreaOfIsland(vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();

    int maxSum=0;

    vector<vector<bool>> vis(n,vector<bool>(m,false));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==false && grid[i][j]==1){
                int area=dfs(grid,i,j,n,m,vis);
                maxSum=max(area,maxSum);
            }
        }
    }

    return maxSum;
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 0, 1, 1}
    };

    cout << "Maximum area of island: " << maxAreaOfIsland(grid) << endl;

    return 0;
}