#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

int solve(int n, int k){
    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin>> nums[i];
    }

    int maxNum=nums[0] - 0;

    for(int i=1;i<n;i++){
        if(nums[i]-nums[i-1]>maxNum){
            maxNum=nums[i]-nums[i-1];
        }
    }

    int x= 2* abs(k- nums[n-1]);

    return max(maxNum,x);
}

int main(){
    int t=0;
    cin>>t;

    for(int i=0;i<t;i++){
        int n,k;
        cin>>n;
        cin>>k;
        ans.push_back(solve(n,k));
    }

    for(int i=0;i<ans.size();i++){
        cout << ans[i] << "\n";
    }

    return 0;
}