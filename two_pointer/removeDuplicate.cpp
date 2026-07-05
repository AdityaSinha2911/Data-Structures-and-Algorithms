#include <iostream>
#include <vector>

using namespace std;

// leetcode ques:26

int removeDuplicates(vector<int>& nums) {
    int i = 0;
    int j = 1;

    while (j < nums.size()) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
        j++;
    }

    return i + 1;
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};

    int k = removeDuplicates(nums);

    cout << "Number of unique elements: " << k << endl;
    cout << "Array after removing duplicates: ";

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}