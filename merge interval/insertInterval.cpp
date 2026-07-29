#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

    vector<vector<int>> ans;

    for (int i = 0; i < intervals.size(); i++) {

        // Case 1: Current interval is completely before newInterval
        if (intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
        }

        // Case 2: Current interval is completely after newInterval
        else if (intervals[i][0] > newInterval[1]) {
            ans.push_back(newInterval);
            newInterval = intervals[i];
        }

        // Case 3: Overlapping intervals
        else {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
    }

    ans.push_back(newInterval);

    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};

    vector<vector<int>> result = insert(intervals, newInterval);

    cout << "Intervals after insertion: ";
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}