#include <iostream>
#include <vector>
using namespace std;

class LockingTree{
    public:
    vector<int>parent;
    vector<int>locked;
    vector<vector<int>>children;

    LockingTree(vector<int>& parent){
        int n=parent.size();

        this->parent=parent;

        children.resize(n);
        locked.resize(n,-1);

        for(int i=1; i<n;i++){
            children[parent[i]].push_back(i);
        }
    }

    bool lock(int num, int user){
        if(locked[num]!=-1){
            return false;
        }

        locked[num]=user;
        return true;
    }

    bool unlock(int num, int user){
        if(locked[num]!=user){
            return false;
        }

        locked[num]=-1;

        return true;
    }

    void dfs(int node, vector<int>& lockedNode){
        if(locked[node]!=-1){
            lockedNode.push_back(node);
        }

        for(int child:children[node]){
            dfs(child,lockedNode);
        }
    }

    bool upgrade(int num, int user){
        if(locked[num]!=-1)return false;

        int p=parent[num];

        while(p!=-1){
            if(locked[p]!=-1){
                return false;
            }
            p=parent[p];
        }

        vector<int> lockedNode;

        for(int child:children[num]){
            dfs(child,lockedNode);
        }

        if(lockedNode.size()==0){
            return false;
        }

        for(int num:lockedNode){
            locked[num]=-1;
        }

        locked[num]=user;
        return true;
    }

};

int main(){
    // 1+1=11 ;)
    return 0;
}