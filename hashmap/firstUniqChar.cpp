#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


int firstUniqChar(string s) {
    unordered_map<char, int> freq;

    // Count frequencies
    for (char c : s) {
        freq[c]++;
    }

    // Find first unique character
    for (int i = 0; i < s.size(); i++) {
        if (freq[s[i]] == 1) {
            return i;
        }
   }

    return -1;
}

int main() {
    string s = "leetcode";
    int index = firstUniqChar(s);

    if (index != -1) {
        cout << "First unique character is at index: " << index << endl;
    } else {
        cout << "No unique character found." << endl;
    }

    return 0;
}