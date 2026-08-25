#include <iostream>
#include <vector>

using namespace std;

// [10,12,14,4,6,8]

int indexOfLowestElement(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] < nums[high]) {
            high = mid; 
        } else {
            low = mid + 1; 
        }
    }

    return high; 
}

int main() {
    vector<int> nums = {10, 12, 14, 4, 6, 8};
    int index = indexOfLowestElement(nums);
    if (index != -1) {
        cout << "Index of the lowest element: " << index << endl;
        cout << "Lowest element: " << nums[index] << endl;
    } else {
        cout << "No lowest element found." << endl;
    }
    return 0;
}
