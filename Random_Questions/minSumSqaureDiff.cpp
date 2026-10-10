#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();

        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
        }

        int maxDiff = *max_element(diff.begin(), diff.end());

        vector<int> countDiff(maxDiff + 1, 0);
        
        for (int d : diff) {
            countDiff[d]++;
        }

        int K = k1 + k2;

        for (int currDiff = maxDiff; currDiff > 0 && K > 0; currDiff--) {
            int countOps = min(countDiff[currDiff], K);

            countDiff[currDiff] -= countOps;
            countDiff[currDiff - 1] += countOps;
            K -= countOps;
        }

        
        long long result = 0;
        for (long long d = 1; d <= maxDiff; ++d) {
            result += countDiff[d] * d * d;
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {4, 5, 6};
    int k1 = 3;
    int k2 = 2;

    long long result = sol.minSumSquareDiff(nums1, nums2, k1, k2);
    cout << "Minimum Sum of Squared Differences: " << result << endl;

    return 0;
}