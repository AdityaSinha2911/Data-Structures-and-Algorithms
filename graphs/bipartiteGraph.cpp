#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& adj,int node,int c, vector<int>& colors){
    colors[node]=c;

    for(int i=0;i<adj[node].size();i++){
        int neigh=adj[node][i];

        if(colors[neigh]==-1){
            int newColors=1-c;

            bool result=dfs(adj,neigh,newColors,colors);

            if(result==false){
                return false;
            }
        }else if(colors[neigh]==c){
            return false;
        }
    }

    return true;
}

bool isBipartiteGraph(vector<vector<int>>& graphs){
    int n=graphs.size();

    vector<int> colors(n,-1);

    for(int i=0;i<n;i++){
        if(colors[i]==-1){
            if(dfs(graphs,i,0,colors)==false){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> graphs(n);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        graphs[u].push_back(v);
        graphs[v].push_back(u);
    }

    if(isBipartiteGraph(graphs)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}