#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    unordered_set<string> st;

    void solve(string& s, int i, string& curr,int count, int& maxLen){
        if(count<0) return;
        int n=s.size();

        if(i==n){
            if(count==0){
                if(curr.length()>maxLen){
                    maxLen=curr.length();
                    st.clear();
                }
            }
            return;
        }

        if(s[i]!= '(' && s[i] != ')'){
            curr.push_back(s[i]);
            solve(s,i+1,curr,count,maxLen);
            curr.pop_back();
            return;
        }

        curr.push_back(s[i]);

        solve(s,i+1,curr,count+(s[i]=='('?1:-1),maxLen);
        
        curr.pop_back();

        solve(s,i+1,curr,count,maxLen);
    }

    public:
    vector<string> removeInvalidParenthesis(string s){
        int maxLen=0;

        st.clear();

        string curr="";

        solve(s,0,curr,0,maxLen);

        return vector<string>(begin(st),end(st));
    }
};

int main(){
    // driver code 
    Solution sol;
    vector<string> result = sol.removeInvalidParenthesis("()())()");
    for(const string& s : result){
        cout << s << endl;
    }
    return 0;
}