#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr, int n, int idx,vector<int>& temp){
    if(idx==n){
        for(int x:temp){
            cout<<x<<" ";
            cout<<endl;
            return;
        }
    }

    // choose
    temp.push_back(arr[idx]);

    // explore
    solve(arr,n,idx+1,temp);

    // undo
    temp.pop_back();

    // Don't choose
    solve(arr,n,idx+1,temp);
}

int main() {

    vector<int> arr = {1, 2, 3};
    vector<int> temp;

    solve(arr, arr.size(), 0, temp);

    return 0;
}