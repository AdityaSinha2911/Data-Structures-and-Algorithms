#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n, int m){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
}

void dfs(vector<vector<char>>& a, int i,int j, int n, int m, vector<vector<bool>>& vis){
    vis[i][j]=true;

    int x[]={-1,1,0,0};
    int y[]={0,0,-1,1};

    for(int k=0;i<k;i++){
        int row=i+x[k];
        int col=j+y[k];

        if(isValid(row,col,n,m)&& a[row][col]=='1' && vis[row][col]==false){
            dfs(a,row,col,n,m,vis);
        }
    }
}

int numIsland(vector<vector<char>>& a){
    int n=a.size();
    int m=a[0].size();

    int res=0;

    vector<vector<bool>> vis(n,vector<bool>(m,false));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='1' && vis[i][j]==false){
                dfs(a,i,j,n,m,vis);
                res++;
            }
        }
    }

    return res;
}

int main() {
    vector<vector<char>> a = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    cout << "Number of islands: " << numIsland(a) << endl;

    return 0;
}