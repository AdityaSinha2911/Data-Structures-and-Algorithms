#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int node, vector<int>& res, vector<bool>& vis){

    res.push_back(node);
    vis[node]=true;

    for(int i=0;i< adj[node].size();i++){
        int neigh = adj[node][i];

        if(vis[neigh]==false){
            dfs(adj,neigh,res,vis);
        }
    }
}

vector<int> bfs(vector<vector<int>>& adj){
    int n=adj.size();
    vector<int> res;
    vector<bool> vis(n,false);

    queue<int> q;

    q.push(0);
    vis[0]=true;

    while(!q.empty()){
        int node=q.front();
        q.pop();

        res.push_back(node);

        for(int i=0;i<adj[node].size();i++){
            int neigh=adj[node][i];

            if(vis[neigh]==false){
                q.push(neigh);
                vis[neigh]=true;
            }
        }
    }

    return res;
}

int main() {

    // Graph:
    //
    //       0
    //      / \
    //     1   2
    //    / \
    //   3   4
    //

    vector<vector<int>> adj = {
        {1, 2},    // 0
        {0, 3, 4}, // 1
        {0},       // 2
        {1},       // 3
        {1}        // 4
    };

    // DFS
    vector<int> dfsRes;
    vector<bool> dfsVis(adj.size(), false);

    dfs(adj, 0, dfsRes, dfsVis);

    cout << "DFS: ";
    for(int node : dfsRes) {
        cout << node << " ";
    }

    // BFS
    vector<int> bfsRes = bfs(adj);

    cout << "\nBFS: ";
    for(int node : bfsRes) {
        cout << node << " ";
    }

    return 0;
}
