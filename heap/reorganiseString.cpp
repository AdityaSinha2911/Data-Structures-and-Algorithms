#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> freq;

        for(char ch:s){
            freq[ch]++;
        }

        priority_queue<pair<int,char>>pq;

        for(auto &[ch,count]:freq){
            pq.push({count,ch});
        }

        string ans="";

        pair<int,char> prev={0,'#'};

        while(!pq.empty()){
            auto[count,ch]=pq.top();
            pq.pop();

            ans+=ch;

            count--;

            if(prev.first>0){
                pq.push(prev);
            }

            prev={count,ch};
        }

        if(ans.length() != s.length()){
            return "";
        }

        return ans;
    }
};

int main(){
    Solution sol;

    string s = "aab";

    string ans = sol.reorganizeString(s);

    cout<<ans<<endl;

    return 0;
}   