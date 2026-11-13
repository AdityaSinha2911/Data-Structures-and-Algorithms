#include <bits/stdc++.h>
using namespace std;

void solve(unordered_set<long long>& st){
    long long n;
    cin>>n;

    for(long long i=1;i*i*i<n;i++){
        long long iCube=i*i*i;

        long long rem=n-iCube;

        if(st.find(rem)!=st.end()){
            cout<<"YES"<<"\n";
            return;
        }
    }
    
    cout<<"NO"<<"\n";
    return;

}

int main(){
    int t;
    cin>>t;
    unordered_set<long long> st;

    for (long long i = 1; i * i * i <= 1e12; i++) {
        long long cube = i * i * i;
        st.insert(cube);
    }

    while(t>0){
        solve(st);
        t--;
    }

    return 0;
}
