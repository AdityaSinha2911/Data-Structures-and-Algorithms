#include <bits/stdC++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;

    int ans=INT_MAX;
    int left=0;

    // int temp size banana hai, sliding window banani hai, aur uska length badhate chalna hai, jab tak teeno elements kei ek ek frequency naa ho jaaye,
    // jaise hi teeno kei ek ek frequency ho jaaye, uskei baad, temp aur ans mei sei min ko ans mei daal do, then temp ko reset to zero
    // aur phir piche sei sliding window ki size ko kam karte rehna hai, aur min ko store karate jana hai,

    vector<int> freq(4,0);
    
    for(int right=0;right<s.size();right++){
        freq[s[right]-'0']++;

        while(freq[1]>0 && freq[2]>0 && freq[3]>0){
            int len=right-left+1;

            ans=min(len,ans);

            freq[s[left]-'0']--;
            left++;
        }
    }

    if(ans==INT_MAX){
        cout<<"0"<<"\n";
        return;
    }else{
        cout<<ans<<"\n";
        return;
    }
    
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