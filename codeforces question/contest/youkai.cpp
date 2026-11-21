#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long x;
    cin >> n >> x;

    vector<long long> h(n);

    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        h[i] = (a + x - 1) / x;
    }

    sort(h.begin(), h.end());

    long long ans = 0;

    for (int i = 0; i < n - 1; i++) {
        ans = max(ans, h[i] - i - 1);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}