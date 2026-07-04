#include <iostream>
#include <string>
#include <climits>
#include <unordered_map>

using namespace std;

// You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the 
// length of the longest substring that contains exactly k distinct characters.

int longestKSubstring(string &s, int k){
    int low=0; 
    int high=0;
    int res=INT_MIN;

    int n=s.size();

    unordered_map<char, int> f;

    for(high=0;high<n;high++){
        f[s[high]]++;

        while(f.size()>k){
            f[s[low]]--;
            
            if(f[s[low]]==0){
                f.erase(s[low-1]);
            }
            low++;
        }

        if(f.size()==k){
            int len=high-low+1;
            res=max(res,len);
        }
    }

    if(res==INT_MIN) return -1;

    return res;
}

int main() {

    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    cout << "Longest Substring Length = " << longestKSubstring(s, k);

    return 0;
}