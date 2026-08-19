#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountain(vector<int>& arr){
    int low=0;
    int high=arr.size()-1;

    while(low<high){
        int mid = low+ (high-low)/2;

        if(arr[mid]<arr[mid+1]){
            low=mid+1;
        }else{
            high=mid;
        }
    }

    return high;
}

int main(){
    vector<int> arr={0,1,0};

    cout<<peakIndexInMountain(arr)<<endl;

    return 0;
}