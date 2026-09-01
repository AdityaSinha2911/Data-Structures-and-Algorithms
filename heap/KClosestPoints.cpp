#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
    priority_queue<pair<int,pair<int,int>>> pq;

    for(auto point: points){
        int x=point[0];
        int y=point[1];

        int distance= x*x+y*y;

        pq.push({distance,{x,y}});

        if(pq.size()>k){
            pq.pop();
        }
    }

    vector<vector<int>> ans;

    while(!pq.empty()){
        int x=pq.top().second.first;
        int y=pq.top().second.second;

        ans.push_back({x,y});

        pq.pop();
    }

    return ans;
}

int main(){
    vector<vector<int>> points = {{1,3},{-2,2},{5,8},{0,1}};
    int k = 2;

    vector<vector<int>> ans = kClosest(points,k);

    for(auto point: ans){
        cout<<"["<<point[0]<<","<<point[1]<<"] ";
    }
    cout<<endl;

    return 0;
}