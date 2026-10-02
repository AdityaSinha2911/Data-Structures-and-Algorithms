#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(int i, int j, int n, int m){
        if(i<0 || i>=n || j<0 ||j>=m){
            return false;
        }
        return true;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }else{
                    mat[i][j]=-1;
                }
            }
        }    

        int x[]={-1,1,0,0};
        int y[]={0,0,-1,1};

        while(!q.empty()){
            auto[i,j]=q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int row=i+x[k];
                int col=j+y[k];

                if(isValid(row,col,n,m) && mat[row][col]==-1){
                    mat[row][col]=mat[i][j]+1;
                    q.push({row,col});
                }
            }
        }

        return mat;
    }
};

int main(){
    // driver code 

}