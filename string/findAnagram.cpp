#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();

        vector<int> ans;

        if(m>n)return ans;

        vector<int> pCount(26,0);
        vector<int> window(26,0);

        for(int i=0;i<m;i++){
            pCount[p[i]-'a']++;
            window[s[i]-'a']++;
        }

        if(pCount==window){
            ans.push_back(0);
        }

        for(int i=m;i<n;i++){
            window[s[i-m]-'a']--;

            window[s[i] - 'a']++;

            if(pCount==window){
                ans.push_back(i-m+1);
            }
        }

        return ans;
    }
};

int main(){
    Solution sol;
    string s,p;
    cin>>s>>p;

    vector<int> ans=sol.findAnagrams(s,p);

    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";

    return 0;
}