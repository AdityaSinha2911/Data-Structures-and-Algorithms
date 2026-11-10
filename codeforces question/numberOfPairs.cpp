#include <bits/stdc++.h>
using namespace std;

long long countPairs(vector<int>& arr, int limit){
    int left=0;
    int right=arr.size()-1;

    long long count=0;

    while(left<right){
        if(arr[left]+arr[right]<=limit){
            count+=(right-left);
            left++;
        }else{
            right--;
        }
    }

    return count;
}

void solve(){
    int n,l,r;
    cin>>n>>l>>r;

    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());

    auto count=countPairs(arr,r)-countPairs(arr,l-1);

    // for(int i=0;i<n;i++){
    //     int left=i+1;
    //     int right=n-1;

    //     while(left<right){
    //         int sum=arr[left] + arr[right];
    //         if( sum>= l && sum <= r){
    //             int x=right-left;
    //             count+=x;
    //             left++;
    //         }else if(sum<l){
    //             left++;
    //         }else if(sum>r){
    //             right--;
    //         }
    //     }
    // }

    cout<<count<<"\n";
    return;
}

int main(){
    int t;
    cin>>t;

    while(t>0){
        solve();
        t--;
    }

    return 0;
}