#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(nums1.begin(), nums1.end());

        // minimum odd then, sab odd ho sakta
        if (mn % 2 == 1){
            return true;
        }

        // minimum even hai agar, then check for any odd elemet in array, agar mila toh false ho jaayega
        for (int x : nums1) {
            if (x % 2 == 1){
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {2, 4, 6, 8};
    bool result = solution.uniformArray(nums1);
    cout << (result ? "true" : "false") << endl; // Output: true

    vector<int> nums2 = {2, 3, 4, 6};
    result = solution.uniformArray(nums2);
    cout << (result ? "true" : "false") << endl; // Output: false

    vector<int> nums3 = {1, 3, 5};
    result = solution.uniformArray(nums3);
    cout << (result ? "true" : "false") << endl; // Output: true

    return 0;
}