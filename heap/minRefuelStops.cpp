#include <bits/stdc++.h>
using namespace std;

int minRefuelStops(int target,int startFuel,vector<vector<int>>& stations){
    priority_queue<int> pq;

    int reach=startFuel;
    int i=0,stop=0;

    while(reach<target){
        while(i<stations.size() && stations[i][0]<=reach){
            pq.push(stations[i][1]);
            i++;
        }

        if(pq.empty()) return -1;

        reach+=pq.top();
        pq.pop();

        stop++;
    }

    return stop;
}

int main(){
    int target=100;
    int startFuel=10;
    vector<vector<int>> stations={{10,60},{20,30},{30,30},{60,40}};

    int ans=minRefuelStops(target,startFuel,stations);

    cout<<ans<<endl;

    return 0;
}