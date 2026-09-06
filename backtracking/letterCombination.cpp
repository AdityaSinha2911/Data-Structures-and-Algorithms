#include <bits/stdc++.h>
using namespace std;

void solve(string& digits, int idx, string& temp, vector<string>& ans, vector<string>& keypad){
    if(idx==digits.size()){
        ans.push_back(temp);
        return;
    }

    int digit=digits[idx]-'0';

    string letters=keypad[digit];

    for(char ch: letters){
        temp.push_back(ch);
        solve(digits,idx+1,temp,ans,keypad);
        temp.pop_back();
    }

}

vector<string> letterCombinations(string digits){
    vector<string> ans;

    if(digits.empty()){
        return ans;
    }

    vector<string> keypad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    string temp;

    solve(digits,0,temp,ans,keypad);
    return ans;
}

int main() {
    string digits = "23";
    vector<string> ans = letterCombinations(digits);

    for(string s:ans){
        cout<<s<<" ";
    }
    cout<<endl;

    return 0;
}