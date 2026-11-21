#include <bits/stdc++.h>
using namespace std;

void solve(){
    int t;
    cin>>t;

    int move=0;
    int dmg=0;

    while(dmg<t){
        move++;
        dmg+=(move+2)/3;
    }

    cout<<move<<"\n";
    return;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;

    cin>>t;

    while(t>0){
        solve();
        t--;
    }

    return 0;
}