#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


long long totalHours(vector<int>& piles, int speed){
    long long hours=0;

    for(int i=0;i<piles.size();i++){
        hours+=ceil(double(piles[i])/speed);
    }

    return hours;
}

int minSpeed(vector<int>& piles,int h){
    int low=1; 
    int high= *max_element(piles.begin(),piles.end());

    int ans=-1;

    while(low<=high){
        int mid = low+(high-low)/2;

        long long hours=totalHours(piles,mid);

        if(hours<=h){
            ans=hours;
            // to check for even more optimal solution
            high=mid-1;
        }else{
            low=mid+1;
        }
    }

    return ans;
}

int main(){
    vector<int> piles={3,6,7,11};
    int h=8;

    cout<<minSpeed(piles,h)<<endl;

    return 0;
}