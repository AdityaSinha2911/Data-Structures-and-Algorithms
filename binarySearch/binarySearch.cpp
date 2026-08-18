#include <iostream>
using namespace std;

int binarySearch(int arr[],int sz, int target){
    int high=sz;
    int low=0;

    while(low<=high){
        int mid = (low+high)/2;

        if(arr[mid]==target){
            return mid;
        }

        if(arr[mid]<target){
            low=mid;
        }else{
            high =mid;
        }
    }

    return -1;
}

int rotatedBinarySearch(int arr[],int sz, int target){
    int high=sz;
    int low=0;

    while(low<=high){
        int mid = (low+high)/2;

        if(arr[mid]==target){
            return mid;
        }

        if(arr[mid]>target){
            low=mid;
        }else{
            high =mid;
        }
    }

    return -1;
}

int main(){
    int arr[5]={1,2,4,5,9};

    int arr2[6]={9,7,5,4,2,1};

    cout<<binarySearch(arr,5,9)<<endl;

    cout<<"rotated binary search: "<<rotatedBinarySearch(arr2,6, 7)<<endl;

    return 0;
}