#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(vector<vector<int>>& adj, int node, vector<bool>& vis, vector<bool>& path){
        vis[node]=true;
        path[node]=true;

        for(int i=0;i<adj[node].size();i++){
            int neigh=adj[node][i];

            if(vis[neigh]&& path[neigh]){
                return false;
            }

            if(!vis[neigh]){
                if(!dfs(adj,neigh,vis,path)){
                    return false;
                }
            }
        }

        path[node]=false;
        return true;
    }


    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int> ans;

        vector<bool> vis(n,false);
        vector<bool> path(n,false);

        for(int i=0;i<n;i++){
            if(dfs(graph,i,vis, path)){
                ans.push_back(i);
            }
        }

        return ans;
    }
};