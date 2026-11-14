#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;

    vector<int>nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    sort(nums.begin(),nums.end());
    
    int maxFreq=1;
    int distinct=1;
    int currFreq=1;

    for(int i=0;i<n-1;i++){
        
        if(nums[i]==nums[i+1]){
            currFreq++;
            maxFreq=max(maxFreq,currFreq);
        }else{
            distinct++;
            currFreq=1;
        }

    }

    int ans=0;

    if(distinct==maxFreq){
        ans=distinct-1;
    }else{
        ans=min(distinct,maxFreq);
    }

    cout<<ans<<"\n";
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