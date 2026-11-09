#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;

    vector<int> arr(n);

    unordered_map<int,int> mp;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }

    vector<int>freq;

    for(auto it:mp){
        freq.push_back(it.second);
    }

    sort(freq.begin(),freq.end());

    int k=freq.size();

    vector<int> prefix(k+1,0);

    for(int i=0;i<k;i++){
        prefix[i+1]=prefix[i]+freq[i];
    }

    int ans=n;

    for(int i=0;i<k;i++){
        int left=prefix[i];
        int right=prefix[k]-prefix[i+1];

        int extra=right-(k-i-1)*freq[i];

        int cost=left+extra;

        ans=min(ans,cost);
    }

    cout<<ans<<"\n";
}

int main(){
    int x;
    cin>>x;

    for(int i=0;i<x;i++){
        solve();
    }

    return 0;
}