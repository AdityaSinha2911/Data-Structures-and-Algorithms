#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>>& adj, int node, int parent, vector<bool>& vis, bool& cycle){
    vis[node]=true;

    for(int i=0;i<adj[node].size();i++){
        int neigh=adj[node][i];

        if(neigh==parent){
            continue;
        }

        if(vis[neigh]==true){
            cycle=true;
            return;
        }

        dfs(adj,neigh,node,vis, cycle);

        if(cycle){
            return;
        }
    }
}

bool isCycle(int n, vector<vector<int>>& edges){
    vector<vector<int>> adj(n);

    for(int i=0;i<edges.size();i++){
        int src=edges[i][0];
        int dest=edges[i][1];

        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }

    vector<bool> vis(n,false);
    bool cycle=false;

    for(int i=0;i<n;i++){
        if(vis[i]==false){
            dfs(adj,i,-1,vis,cycle);

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
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}