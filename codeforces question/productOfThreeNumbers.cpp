#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long x){
    if(x<2)return false;

    if(x==2)return true;

    for(int i=2;i*i<x;i++){
        if(x%i==0){
            return false;
        }
    }

    return true;
}

void solve(int t){
    long long x;
    cin>>x;


    if(isPrime(x)){
        cout<<"NO"<<"\n";
        return;
    }


    vector<int> factors;

    for(auto i=2;i*i<x;i++){
        if(x%i==0){
            factors.push_back(i);
            if(i!=(x/i)){
                factors.push_back(x/i);
            }
        }
    }

    sort(factors.begin(),factors.end());

    for(int i=0;i<factors.size();i++){
        for(int j=i+1;j<factors.size();j++){
            auto a=factors[i];
            auto b=factors[j];

            if(x%(a*b)!=0)continue;

            auto c=x/(a*b);

            if(c>1 && c!=a && c != b){
                cout<<"YES"<<"\n";
                cout<<a<<" "<<b<<" "<<c<<"\n";
                return;
            }
        }
    }

    cout<<"NO"<<"\n";
    return ;
}

int main(){
    int t;
    cin>>t;

    while(t!=0){
        solve(t);
        t--;
    }

    return 0;
}