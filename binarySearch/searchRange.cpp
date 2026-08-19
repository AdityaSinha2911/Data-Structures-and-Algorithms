#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {

    int first = -1;
    int last = -1;

    // Find first occurrence
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            first = mid;
            right = mid - 1;     // Search left side
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    // Find last occurrence
    left = 0;
    right = nums.size() - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            last = mid;
            left = mid + 1;      // Search right side
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return {first, last};
}

int main() {

    vector<int> nums = {5, 7, 7, 8, 8, 10};

    vector<int> result = searchRange(nums, 8);

    cout << "first: " << result[0]
         << " last: " << result[1] << endl;

    return 0;
}