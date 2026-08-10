#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> result(n, 0); // Initialize result vector with 0s
    stack<int> st; // Stack to keep track of indices

    for (int i = 0; i < n; ++i) {
        // While the stack is not empty and the current temperature is greater than the temperature at the index stored at the top of the stack
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int index = st.top(); // Get the index of the previous temperature
            st.pop(); // Remove it from the stack
            result[index] = i - index; // Calculate the number of days until a warmer temperature
        }
        st.push(i); // Push the current index onto the stack
    }

    return result; // Return the result vector
}

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = dailyTemperatures(temperatures);

    cout << "Days until a warmer temperature: ";
    for (int days : result) {
        cout << days << " "; // Output the result
    }
    cout << endl;

    return 0;
}