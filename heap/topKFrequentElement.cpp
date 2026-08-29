#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> topKFreqeuent(vector<int>&nums, int k){
    unordered_map<int,int> freq;

    for(int x: nums){
        freq[x]++;
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

    for(auto &[num,count] : freq){
        pq.push({count,num});

        if(pq.size()>k){
            pq.pop();
        }
    }

    vector<int> ans;

    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}

int main(){
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    vector<int> ans = topKFreqeuent(nums,k);

    for(int x: ans){
        cout<<x<<" ";
    }

    return 0;
}