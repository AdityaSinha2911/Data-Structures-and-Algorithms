#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string removeDuplicates(string s, int k) {
    stack<pair<char, int>> st;

    for (char c : s) {
        if (!st.empty() && st.top().first == c) {
            st.top().second++;

            if (st.top().second == k)
                st.pop();
        } else {
            st.push({c, 1});
        }
    }

    string result;

    while (!st.empty()) {
        pair<char, int> p = st.top();
        st.pop();

        result.append(p.second, p.first);
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    string s = "deeedbbcccbdaa";
    int k = 3;

    string result = removeDuplicates(s, k);

    cout << "Result: " << result << endl;

    return 0;
}