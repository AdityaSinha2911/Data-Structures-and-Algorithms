#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& nums,int target){
    int n= nums.size();
    int m= nums[0].size();

    int low=0, high=n*m-1;

    while (low<=high){
        int guess=low+ (high-low)/2;

        int row=guess/m;
        int col=guess%m;

        if(nums[row][col]==target) return true;

        if(nums[row][col]>target){
            high=guess-1;
        }else{
            low=guess+1;
        }
    }

    return false;

}

int main(){
    // predefined 2D matrix
    vector<vector<int>> nums = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };  

    int target;
    cin >> target;  

    if(searchMatrix(nums, target)){
        cout << "Target found in the matrix." << endl;
    } else {
        cout << "Target not found in the matrix." << endl;
    }
}