#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string removeDuplicate(string s) {
    stack<char> st;

    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop(); // Remove the duplicate character
        } else {
            st.push(c); // Add the character to the stack
        }
    }

    // Construct the result string from the stack
    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    // The characters are in reverse order, so reverse the result
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string s = "abbaca";
    string result = removeDuplicate(s);
    cout << "Result after removing duplicates: " << result << endl; // Output: Result after removing duplicates: ca
    return 0;
}