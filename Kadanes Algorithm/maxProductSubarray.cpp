#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMaxProduct = nums[0];
        int currMinProduct = nums[0];
        int maxProduct = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int tempMax = max({
                nums[i],
                nums[i] * currMaxProduct,
                nums[i] * currMinProduct
            });

            int tempMin = min({
                nums[i],
                nums[i] * currMaxProduct,
                nums[i] * currMinProduct
            });

            currMaxProduct = tempMax;
            currMinProduct = tempMin;

            if (currMaxProduct > maxProduct) {
                maxProduct = currMaxProduct;
            }
        }

        return maxProduct;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {2, 3, -2, 4};
    int maxProd = obj.maxProduct(nums);
    cout << "Maximum Product Subarray: " << maxProd << endl; // Output: Maximum Product Subarray: 6
    return 0;
}