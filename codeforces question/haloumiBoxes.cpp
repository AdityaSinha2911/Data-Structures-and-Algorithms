#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

bool isSorted(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[i - 1]) {
            return false;
        }
    }
    return true;
}

string solve(int n,int k){
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    if(isSorted(nums)){
        return "YES";
    }

    if(k==1 && !isSorted(nums)){
        return "NO";
    }

    return "YES";
}

int main(){
    int t;
    cin>>t;

    
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n;
        cin>>k;
        ans.push_back(solve(n,k));
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
    
    return 0;
}