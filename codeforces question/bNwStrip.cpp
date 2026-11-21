#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve(){
    int n;
    int k;

    cin>>n;
    cin>>k;

    string s;
    cin>>s;

    int currW=0;

    for(int i=0;i<k;i++){
        if(s[i]=='W'){
            currW++;
        }
    }

    if(k==n){
        cout<<currW<<endl;
        return;
    }

    int minW=currW;

    for(int i=k;i<n;i++){
        if(s[i-k]=='W'){
            currW--;
        }

        if(s[i]=='W'){
            currW++;
        }

        minW=min(minW,currW);
    }

    cout<<minW<<endl;

    return;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t>0){
        solve();
        t--;
    }

    return 0;
}