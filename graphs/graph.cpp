#include <bits/stdc++.h>
using namespace std;

void createGraph(int n, vector<vector<int>>& adj){
    int m;
    cin>>m;

    for(int i =0;i<m;i++){
        int src,dest;
        cin>>src>>dest;

        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }
}

int main(){
    
    int n;
    cin>>n;
    vector<vector<int>> adj(n);

    createGraph(n,adj);

    for(int i=0;i<n;i++){
        cout<<i<<"->";
        for(auto it:adj[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    return 0;
}