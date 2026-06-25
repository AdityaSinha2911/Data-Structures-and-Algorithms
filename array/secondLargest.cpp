#include <iostream>
#include <climits>
using namespace std;

int secondLargest(int arr[],int sz){

    if(sz<2){
        return -1;
    }

    int largest =INT_MIN;
    int secondLargest= INT_MIN;

    for(int i=0;i<=sz-1;i++){
        if(arr[i]>largest){
            secondLargest=largest;
            largest=arr[i];
        }else if(arr[i]>secondLargest && arr[i]!=largest){
            secondLargest=arr[i];
        }
    }

    if(secondLargest==INT_MIN){
        return -1;
    }

    return secondLargest;
}

int main(){
    int arr[5]={4,5,2,9,7};
    cout<<secondLargest(arr,5);

    return 0;
}