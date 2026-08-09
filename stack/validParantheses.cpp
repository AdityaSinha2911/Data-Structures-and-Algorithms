#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c); // Push opening brackets onto the stack
        } else {
            if (st.empty()) {
                return false; // No matching opening bracket
            }
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false; // Mismatched brackets
            }
        }
    }

    return st.empty(); // Valid if stack is empty at the end
}

int main() {
    string s = "{[()]}";
    if (isValid(s)) {
        cout << "The parentheses are valid." << endl; // Output: The parentheses are valid.
    } else {
        cout << "The parentheses are not valid." << endl;
    }
    return 0;
}