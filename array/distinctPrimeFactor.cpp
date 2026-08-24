#include <bits/stdc++.h>
using namespace std;

int distinctPrimeFactor(vector<int>& nums){
    unordered_set<int> st;

    for(int i=0;i<nums.size();i++){
        int n=nums[i];
        for(int j=2;j*j<=n;j++){
            if(n%j==0){
                st.insert(j);
                while(n%j==0){
                    n/=j;
                }
            }
        }
        if(n>1) st.insert(n);
    }
    return st.size();
}

int main(){
    
    vector<int> nums = {2, 4, 3, 7, 10};
    int result = distinctPrimeFactor(nums);
    cout << "Number of distinct prime factors: " << result << endl;
    return 0;
}