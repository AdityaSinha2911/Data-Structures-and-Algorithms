#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n, int m){
    if(i<0 || i>=n || j<0 ||j>=m){
        return false;
    }

    return true;
}

void dfs(vector<vector<int>>& adj, int i, int j, int n, int m, vector<vector<bool>>& vis){
    vis[i][j]=true;

    int x[]={-1,1,0,0};
    int y[]={0,0,-1,1};

    for(int k=0;k<4;k++){
        int row=i+x[k];
        int col=j+y[k];

        if(isValid(row,col,n,m) && vis[row][col]==false && adj[row][col]=='O'){
            dfs(adj,row, col, n, m, vis);
        }
    }
}   

void solve(vector<vector<int>>& board){
    int n=board.size();
    int m=board[0].size();

    vector<vector<bool>> vis(n,vector<bool>(m,false));

    for(int i=0;i<n;i++){
        if(board[i][0]=='O' && !vis[i][0]){
            dfs(board,i,0,n,m,vis);
        }

        if(board[i][m-1]=='O' && !vis[i][m-1]){
            dfs(board,i,m-1,n,m,vis);
        }
    }

    for(int j=0;j<m;j++){
        if(board[0][j]=='O' && !vis[0][j]){
            dfs(board,0,j,n,m,vis);
        }


        if(board[n-1][j]=='O' && !vis[n-1][j]){
            dfs(board,n-1,j,n,m,vis);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='O' && !vis[i][j]){
                board[i][j]='X';
            }
        }
    }
}

int main(){
    vector<vector<int>> board={{'X','X','X','X'},
                                {'X','O','O','X'},
                                {'X','X','O','X'},
                                {'X','O','X','X'}};

    solve(board);

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}