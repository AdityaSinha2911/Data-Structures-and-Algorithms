#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    unordered_map<int, int> mp;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        int key = x - i;
        ans += mp[key];
        mp[key]++;
    }

    cout << ans << endl;
}

int main(){
    int t;
    cin>>t;

    while(t>0){
        solve();
        t--;
    }

    return 0;
}