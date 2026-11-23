#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<int>dummyRow(n,-1);
        vector<int>dummyCol(m,-1);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    dummyRow[i]=0;
                    dummyCol[j]=0;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dummyRow[i]==0 || dummyCol[j]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

int main(){

    return 0;
}