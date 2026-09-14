#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n, int m){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
}

int rotten(vector<vector<int>> & a){
    int n=a.size();
    int m=a[0].size();

    queue<pair<int,int>> q;

    int fresh=0;
    int time=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==2){
                q.push({i,j});
            }
            if(a[i][j]==1){
                fresh++;
            }
        }
    }

    int x[]={-1,1,0,0};
    int y[]={0,0,-1,1};

    while(!q.empty() && fresh >0){
        time++;
        
        int sz=q.size();

        while(sz--){
            pair<int,int> p=q.front();
            q.pop();

            int r=p.first;;
            int c=p.second;

            for(int k=0;k<4;k++){
                int row= r+x[k];
                int col= c+y[k];

                if(isValid(row,col,n,m) && a[row][col]==1){
                    q.push({row,col});

                    a[row][col]=-1;

                    fresh--;
                }
            }
        }
    }

    
    if(fresh>0) return -1;
    
    return time;
}

int orangeRotting(vector<vector<int>> & grid){
    return rotten(grid);
}

int main(){
    vector<vector<int>> grid={{2,1,1},{1,1,0},{0,1,1}};
    cout<<orangeRotting(grid);
}