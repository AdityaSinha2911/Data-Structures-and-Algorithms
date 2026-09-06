#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }

    vector<vector<int>> zizagLevelOrder(Node* root){
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }

        queue<Node*> q;
        q.push(root);

        bool leftToRight=true;

        while(!q.empty()){
            int size=q.size();
            vector<int> level;

            for(int i=0;i<size;i++){
                Node* temp=q.front();
                q.pop();

                level.push_back(temp->data);

                if(temp->left != NULL){
                    q.push(temp->left);
                }

                if(temp->right != NULL){
                    q.push(temp->right);
                }
            }
            if(!leftToRight){
                reverse(level.begin(),level.end());
            }
            ans.push_back(level);
            leftToRight= !leftToRight;
        }
        return ans;
        
    }
    
};

int main(){
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    vector<vector<int>> result = root->zizagLevelOrder(root);

    for(vector<int> level : result){
        for(int val : level){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}