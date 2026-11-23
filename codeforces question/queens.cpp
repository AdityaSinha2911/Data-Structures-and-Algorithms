#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;

    vector<int>parent(n+1);
    vector<int>c(n+1);

    vector<vector<int>>children(n+1);

    for(int i=1;i<=n;i++){
        cin>>parent[i]>>c[i];

        if(parent[i]!=-1){
            children[parent[i]].push_back(i);
        }
    }

    vector<int>ans;

    for(int i=1;i<=n;i++){
        if(parent[i]==-1 || c[i]==0){
            continue;
        }

        bool canDelete=true;

        for(int child: children[i]){
            if(c[child]==0){
                canDelete=false;
                break;
            }
        }

        if(canDelete){
            ans.push_back(i);
        }
    }

    if(ans.size()==0){
        cout<<"-1"<<endl;
        return;
    }else{
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }

    return;
}
void solve2(){
    int n;
    cin>>n;

    vector<int>parent(n+1);
    vector<int>c(n+1);

    for(int i=0;i<n;i++){
        cin>>parent[i]>>c[i];
    }

    vector<int>ans;

    for(int i=1;i<=n;i++){
        if(parent[i]==-1 || c[i]==0){
            continue;
        }

        bool canDelete=true;

        for(int j=1;j<=n;j++){

            if(parent[j]==i && c[j]==0){
                canDelete=false;
                break;
            }
        }

        if(canDelete){
            ans.push_back(i);
        }
    }

    if(ans.size()==0){
        cout<<"-1"<<endl;
        return;
    }else{
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }

    return;
}

int main(){
    solve();
    return 0;
}