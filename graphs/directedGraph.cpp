#include <bits/stdc++.h>
using namespace std;

bool cycle=false;

void dfs(vector<vector<int>>& adj,int node,vector<bool>& path, vector<bool>& vis){

    vis[node]=true;
    path[node]=true;

    for(int i=0;i<adj[node].size();i++){
        int neigh= adj[node][i];

        if(vis[neigh] && path[neigh]){
            cycle = true;
            return;
        }

        if(!vis[neigh]){
            dfs(adj,neigh,path,vis);
        }
    }

    path[node]=false;
}

bool isCycle(int n, vector<vector<int>>& edges){
    
    vector<vector<int>> adj(n);

    for(int i=0;i<edges.size();i++){
        int src=edges[i][0];
        int dest=edges[i][1];

        adj[src].push_back(dest);
    }

    vector<bool> vis(n,false);
    vector<bool> path(n, false);

    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(adj,i,path,vis);

            if(cycle){
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0}, // This edge creates a cycle
        {3, 4}
    };

    if (isCycle(n, edges)) {
        cout << "The directed graph contains a cycle." << endl;
    } else {
        cout << "The directed graph does not contain a cycle." << endl;
    }

    return 0;
}