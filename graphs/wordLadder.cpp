#include <bits/stdc++.h>
using namespace std;

int ladderLength(string begin, string end, vector<string>& words){
    int n=words.size();
    unordered_map<string,int> f;

    // push all the elements of word in map
    for(int i=0;i<n;i++){
        f[words[i]]++;
    }

    if(f.find(end)==f.end()){
        return 0;
    }

    queue<pair<string,int>> q;
    q.push({begin,1});

    f.erase(begin);

    while(!q.empty()){
        pair<string,int> p=q.front();
        q.pop();

        string s=p.first;
        int val=p.second;

        if(s==end){
            return val;
        }

        for(int i=0;i<s.size();i++){
            char c=s[i];

            for(int j=97;j<=122;j++){
                if(c==j) continue;

                s[i]=j;

                if(f.find(s) != f.end()){
                    q.push({s,val+1});
                    f.erase(s);
                }
            }

            s[i]=c;
        }
    }
    return 0;
}

int main() {

    string begin = "hit";
    string end = "cog";

    vector<string> words = {
        "hot",
        "dot",
        "dog",
        "lot",
        "log",
        "cog"
    };

    int ans = ladderLength(begin, end, words);

    cout << "Shortest Transformation Length: " << ans << endl;

    return 0;
}