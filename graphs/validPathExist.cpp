#include <bits/stdc++.h>
using namespace std;


bool dfs(vector<vector<int>>& adj, int node, int dest, vector<bool>& vis){
    if(node==dest)return true;

    vis[node]=true;

    for(int i=0;i<adj[node].size();i++){
        int neigh=adj[node][i];

        if(vis[neigh])continue;

        if(dfs(adj,neigh,dest,vis))return true;
    }
    return false;
}

bool isValidPath(vector<vector<int>>& edges, int n, int source,int destination){
    vector<vector<int>> adj(n);

    for(int i=0;i<edges.size();i++){
        int src=edges[i][0];
        int dest=edges[i][1];

        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }
    vector<bool> vis(n,false);

    return dfs(adj,source,destination,vis);

}

int main() {
    int n = 5; // Number of nodes
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4}
    };
    int source = 0;
    int destination = 4;

    if (isValidPath(edges, n, source, destination)) {
        cout << "A valid path exists from " << source << " to " << destination << "." << endl;
    } else {
        cout << "No valid path exists from " << source << " to " << destination << "." << endl;
    }

    return 0;
}