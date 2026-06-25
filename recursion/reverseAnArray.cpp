#include <iostream>
using namespace std;

// void reverseArray(int arr[], int sz){
//     int start=0;
//     int end =sz-1;

//     while(start<end){
//         swap(arr[start],arr[end]);
//         start++;
//         end--;
//     }

//     for(int i=0;i<sz;i++){
//         cout<<arr[i]<<" ";
//     }
// }

void reverseArray(int arr[],int start,int sz){ //start ko humesha 0 kar dena 
    if(start>= sz/2){
        return;
    }

    swap(arr[start],arr[sz-start-1]);

    reverseArray(arr,start+1,sz);
}

int main(){
    int arr[]={1,2,3,4,5};
    reverseArray(arr,0,5);

    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}