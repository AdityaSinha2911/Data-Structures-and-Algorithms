#include <iostream>
#include <vector>
#include <string>
using namespace std;

int maxLengthSubarray(string s){
    vector<int> freq(26,0);
    int left=0,ans=0;

    for(int right=0;right< s.size();right++){
        freq[s[right]-'a']++;

        while(freq[s[right]-'a']>2){
            freq[s[left]-'a']--;
            left++;
        }

        ans=max(ans,right-left+1);
    }

    return ans;
}

int main() {
    string s = "abcabcbb";
    int result = maxLengthSubarray(s);
    cout << "The length of the longest substring with at most 2 occurrences of each character is: " << result << endl;
    return 0;
}