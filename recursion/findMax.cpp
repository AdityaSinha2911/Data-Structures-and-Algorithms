#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> & nums,int n){
    if(n==1){
        return nums[0];
    }

    int last=nums[n-1];

    int answer=findMax(nums,n-1);

    return max(answer,last);
}

int main(){
    vector<int> nums={1,2,3,4,5};
    cout<<findMax(nums,5);
    return 0;
}