#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph,int node,vector<bool>& vis){
    vis[node]=true;

    for(int i=0;i<graph[node].size();i++){
        if(!vis[i] && graph[node][i]==1){
            dfs(graph,i,vis);
        }
    }
}

int numOfProvince(vector<vector<int>>& graphs){
    int n=graphs.size();

    vector<bool> vis(n,false);

    int ans=0;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            ans++;
            dfs(graphs,i,vis);
        }
    }
    return ans;
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<int>> graphs = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 1}
    };

    int provinces = numOfProvince(graphs);
    cout << "Number of provinces: " << provinces << endl;

    return 0;
}