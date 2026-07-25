#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int totalSum = 0;
    for (int num : nums) {
        totalSum += num;
    }

    int leftSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (leftSum == totalSum - leftSum - nums[i]) {
            return i;
        }
        leftSum += nums[i];
    }

    return -1; // No pivot index found
}

int main() {
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    int index = pivotIndex(nums);
    if (index != -1) {
        cout << "Pivot Index: " << index << endl; // Output: Pivot Index: 3
    } else {
        cout << "No Pivot Index found." << endl;
    }
    return 0;
}