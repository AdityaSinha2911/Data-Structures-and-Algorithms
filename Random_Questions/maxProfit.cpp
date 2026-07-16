#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
            } else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice;
            }
        }

        return maxProfit;
    }
};

int main() {
    Solution obj;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int profit = obj.maxProfit(prices);
    cout << "Maximum Profit: " << profit << endl; // Output: Maximum Profit: 5
    return 0;
}
