#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<long long>>nums(m,vector<long long>(n));


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>nums[j][i];
        }
    }


    long long totalWinning=0;

    for(int j=0;j<m;j++){
        sort(nums[j].begin(),nums[j].end());

        for(int i=0;i<n;i++){
            long long multiplier = 2LL * i - n + 1;
            totalWinning += nums[j][i] * multiplier;
        }
    }

    cout<<totalWinning<<"\n";
    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;

    while(t>0){
        solve();
        t--;
    }

    return 0;
}