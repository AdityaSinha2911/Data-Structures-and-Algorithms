#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(string s) {

        // check for every two subsequent elements, if not equal then count++

        int changes = 0;
        for (int i = 0; i < s.size(); i += 2) {
            if (s[i] != s[i + 1]) changes++;
        }
        
        return changes;
    }
};

int main(){

}