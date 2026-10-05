#include <bits/stdc++.h>
using namespace std;

int scoreOfParenthesis(string s){
    int n=s.size();
    stack<int> st;

    st.push(0);

    for(int i=0;i<n;i++){
        if(s[i]==')'){
            st.push(0);
        }else{
            int inner=st.top();
            st.pop();

            int value=0;

            if(inner==0){
                value=1;
            }else{
                value=2*inner;
            }

            st.top() +=value;
        }

    }
    return st.top();
}

int main(){
    string s;
    cin>>s;

    int result=scoreOfParenthesis(s);

    cout<<result<<endl;

    return 0;
}