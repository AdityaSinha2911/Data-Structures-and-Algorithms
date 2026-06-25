#include <iostream>
#include <vector> //for vector use
#include <algorithm> // for reverse use
using namespace std;

// leetCode question no. 189
// move element to right by k places

void rotateByKPlaces(vector<int>& arr,int k){
    int n= arr.size();

    k=k%n; //no. of place to rotate

    reverse(arr.begin(),arr.end());
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.end());
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    rotateByKPlaces(arr, k);
    // output: 5 6 7 1 2 3 4

    for(int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}