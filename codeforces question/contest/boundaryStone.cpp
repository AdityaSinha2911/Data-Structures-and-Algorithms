#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, m;
    cin >> x >> y >> m;

    string s;
    cin >> s;

    vector<int> dp(105, -1);
    dp[y] = x;

    int ans = x + y;

    for (char ch : s) {
        vector<int> ndp(105, -1);

        for (int j = 0; j < 105; j++) {
            if (dp[j] == -1) continue;

            int i = dp[j];

            if (i == 0 && j == 0) continue;

            if (ch == '+') {
                if (j > 0) {
                    ndp[j + 1] = max(ndp[j + 1], i);
                }
                else if (i > 0) {
                    ndp[j + 1] = max(ndp[j + 1], i - 1);
                }
            }
            else {
                if (j > 0) {
                    ndp[j - 1] = max(ndp[j - 1], i + 1);
                }

                if (i > 0) {
                    ndp[j] = max(ndp[j], i - 1);
                }
            }
        }

        dp = ndp;

        for (int j = 0; j < 105; j++) {
            if (dp[j] != -1) {
                ans = max(ans, dp[j] + j);
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}