#include <iostream>
#include <vector>
using namespace std;
/*
Time Complexity = O(n)
Space Complexity =O(1)

leet code question 283
*/

void moveZeroes(vector<int>& arr){
    int j=0;

    for(int i =0;i<arr.size();i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}

int main(){
    vector<int> arr={1,0,3,0,5,7,0,29,89,0};

    moveZeroes(arr);

    for(int nums:arr){
        cout<<nums<<" ";
    }
}