#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;

    vector<int>red(n);

    int redMax=0;
    int rSum=0;

    for(int i=0;i<n;i++){
        cin>>red[i];

        rSum+=red[i];
        redMax=max(redMax,rSum);
    }

    int m;
    cin>>m;

    vector<int>blue(m);

    int blueMax=0;
    int bSum=0;

    for(int i=0;i<m;i++){
        cin>>blue[i];

        bSum+=blue[i];
        blueMax=max(bSum,blueMax);
    }

    cout<<redMax+blueMax<<"\n";
    return ;

}

int main(){
    int  t;
    cin>>t;

    while(t>0){
        solve();
        t--;
    }
}