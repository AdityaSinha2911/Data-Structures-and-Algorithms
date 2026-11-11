
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.rbegin(), arr.rend());

    long long alice = 0, bob = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (arr[i] % 2 == 0)
                alice += arr[i];
        }
        else {
            if (arr[i] % 2 != 0)
                bob += arr[i];
        }
    }

    if (alice > bob)
        cout << "Alice\n";
    else if (bob > alice)
        cout << "Bob\n";
    else
        cout << "Tie\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
