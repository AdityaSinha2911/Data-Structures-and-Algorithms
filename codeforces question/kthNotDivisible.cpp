#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;

    long long ans = k + (k - 1) / (n - 1);

    cout << ans << '\n';
}

int main(){
    int t;
    cin>>t;

    while(t>0){
        solve();
        t--;
    }
}