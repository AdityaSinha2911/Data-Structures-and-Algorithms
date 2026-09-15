#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int v, vector<vector<int>>& nums){
    vector<vector<int>> adj(v);
    vector<int> indegree(v,0);

    for(int i=0;i<nums.size();i++){
        int src = nums[i][0];
        int dest= nums[i][1];

        adj[src].push_back(dest);
        indegree[src]++;
    }

    queue<int> q;

    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int> ans;

    while(!q.empty()){
        int node=q.front();
        q.pop();

        ans.push_back(node);

        for(int i=0;i<adj[node].size();i++){
            int neigh=adj[node][i];

            indegree[neigh]--;

            if(indegree[neigh]==0){
                q.push(neigh);
            }
        }
    }

    if(ans.size() != v){
        return {};
    }

    return ans;
}

int main() {
    int v = 4; // Number of courses
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 1},
        {3, 2}
    };

    vector<int> order = findOrder(v, prerequisites);

    if (order.empty()) {
        cout << "No valid order exists to complete all courses." << endl;
    } else {
        cout << "A valid order to complete all courses is: ";
        for (int course : order) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}