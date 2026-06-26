#include <iostream>
#include <vector>

using namespace std;

// leet code question number 268


int missingNumber(vector<int>& nums){
    int n=nums.size();
    int sum=n*(n+1)/2; 

    int arraySum=0;
    for(int i=0;i<n;i++){
        arraySum+= nums[i];
    }
    // the sum of size - the sum of all element, will return the missing element
    return sum-arraySum;
}

int main(){
    vector<int>arr={1,2,3,5,4,0};
    cout<<missingNumber(arr);

    // output: 6
}