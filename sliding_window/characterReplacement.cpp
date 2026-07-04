#include <iostream>
#include <unordered_map>
#include <climits>
#include <string>

using namespace std;

/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other
uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above
operations.
*/

// LeetCode ques. :424

int characterReplacement(string s,int k){
    int low=0;
    int high=0;
    int res=INT_MIN;

    int n=s.size();
    int maxFreq=0;

    unordered_map<char,int> f;

    for(high=0;high<n;high++){
        f[s[high]]++;
        maxFreq=max(maxFreq,f[s[high]]);
        while((high-low+1)-maxFreq>k){
            f[s[low]]--;
            low++;
        }
        res=max(high-low+1,res);
    }

    return res;
}

int main() {

    string s = "ABAB";
    int k = 2;

    cout << "String = " << s << endl;
    cout << "k = " << k << endl;

    cout << "Answer = " << characterReplacement(s, k);

    return 0;
}