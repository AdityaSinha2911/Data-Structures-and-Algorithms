#include <iostream>
using namespace std;

void leftRotateByOnePlace(int arr[],int sz){
    int temp= arr[0];

    for(int i =1;i<sz;i++){
        arr[i-1]=arr[i];
    }
    arr[sz-1]=temp;
}

int main(){
    int arr[4]={1,2,3,4};
    leftRotateByOnePlace(arr,4);

    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }

    // output: 2 3 4 1
}