#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // find the abs minimum, or zero
    int min=abs(arr[0]);
    for(int i=0;i<n;i++){
        if(abs(arr[i])<min){
            min=abs(arr[i]);
        }

        if(min==0){
            break;
        }
    }

    cout<<min;
    return 0;
}