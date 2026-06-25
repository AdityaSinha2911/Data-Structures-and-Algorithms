#include <iostream>
using namespace std;

int largestElement(int arr[], int sz){
    int largest=arr[0];
    for(int i=0;i<=sz-1;i++){
        largest=max(largest,arr[i]);
    }

    return largest;
}

int main(){
    int arr[5]={1,2,3,4,5};
    cout<<largestElement(arr,5);
    return 0;
}