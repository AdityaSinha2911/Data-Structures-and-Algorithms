#include <bits/stdc++.h>
using namespace std;

int n,m;
int ans=0;
vector<int>cat;
vector<vector<int>>adj;

void dfs(int u,int parent, int cats){
    if(cat[u]==1){
        cats++;
    }else{
        cats=0;
    }

    if(cats>m)return;

    if(u!=1 && adj[u].size()==1){
        ans++;
        return;
    }

    for(int v:adj[u]){
        if(v!=parent){
            dfs(v,u,cats);
        }
    }

}

void solve(){
    cin>>n>>m;

    cat.resize(n+1);
    adj.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>cat[i];
    }

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,-1,0);

    cout<<ans<<"\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();

    return 0;
}