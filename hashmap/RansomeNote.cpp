#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> freq;

    // Count frequencies of characters in magazine
    for (char c : magazine) {
        freq[c]++;
    }

    // Check if ransomNote can be constructed
    for (char c : ransomNote) {
        if (freq[c] == 0) {
            return false; // Not enough characters in magazine
        }
        freq[c]--;
    }

    return true; // Ransom note can be constructed
}

int main() {
    string ransomNote = "a";
    string magazine = "b";

    bool result = canConstruct(ransomNote, magazine);

    if (result) {
        cout << "Ransom note can be constructed from magazine." << endl;
    } else {
        cout << "Ransom note cannot be constructed from magazine." << endl;
    }

    return 0;
}