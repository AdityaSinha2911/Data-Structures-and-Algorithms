#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;

    vector<string>grid(n);

    for(int i=0;i<n;i++){
        cin>>grid[i];
    }


    /*
    condition: (first approach)
    pehla ki agar 1 sabse last mei hai tab sahi chal rhaa-- sabse pehle yei case check karna hai
    then check karna hai ki , 1 kei bagal mei right or down mei koi 1 hai yaa nhi-- aur uss 1 kei boundary par koi 1 jo ki coundary ko touch karta ho
    */

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(grid[i][j]=='1'){
                char right=grid[i][j+1];
                char down=grid[i+1][j];

                if(right != '1' && down != '1'){
                    cout<<"NO"<<"\n";
                    return;
                }
            }
        }
    }

    cout<<"YES"<<"\n";
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
}