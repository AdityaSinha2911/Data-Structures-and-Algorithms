#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:

    struct cmp {
        bool operator()(const pair<int,string>& a,
                        const pair<int,string>& b) {

            // Frequency same hai
            if (a.first == b.first)
                return a.second < b.second;

            // Smaller frequency top par
            return a.first > b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> freq;

        for (string word : words) {
            freq[word]++;
        }


        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;

        for (auto &[word, count] : freq) {

            pq.push({count, word});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};