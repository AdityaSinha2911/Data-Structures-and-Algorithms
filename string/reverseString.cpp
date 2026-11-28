#include <bits/stdc++.h>
using namespace std;

string reverse(string s){
    int n =s.size();

    int i=0;
    int j=n-1;

    while(i<n && s[i]==' ')i++;
    while(j>=0 && s[j]==' ')j--;

    string ans="";

    string temp="";

    while(j>=i){
        if(s[j]==' '){
            if(!temp.empty()){
                reverse(temp.begin(),temp.end());
                if(!ans.empty())ans+=" ";
                ans+=temp;
                temp="";
            }
        }else{
            temp+=s[j];
        }

        j--;
    }

    if(!temp.empty()){
        reverse(temp.begin(),temp.end());
        if(!ans.empty())ans+=" ";
        ans+=temp;
    }

    return ans;
}

int main() {
    string s = "  hello world  ";

    cout << reverse(s);

    return 0;
}