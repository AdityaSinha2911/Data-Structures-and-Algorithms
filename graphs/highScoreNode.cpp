#include <bits/stdc++.h>
using namespace std;

#define LL long long

int edgeScore(vector<int>& edges){
    vector<LL>res(edges.size(),0);

    for(int i=0;i<edges.size();i++){
        int idx=edges[i];

        res[idx]+=i;
    }

    LL maxEdes=0;

    for(int i=0;i<res.size();i++){
        maxEdes=max(maxEdes,res[i]);
    }


    for(int i=0;i<res.size();i++){
        if(res[i]==maxEdes){
            return i;
        }
    }


    return -1;
}

int main(){

    return 0;
}