#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data=val;
            left=nullptr;
            right=nullptr;
        }

        vector<vector<int>> levelOrder(Node* root){
            vector<vector<int>>ans;

            if(root==NULL){
                return ans;
            }

            queue<Node*> q;
            q.push(root);

            while(!q.empty()){
                int size=q.size();
                vector<int>level;

                for(int i=0;i<size;i++){
                    Node* temp=q.front();
                    q.pop();

                    level.push_back(temp->data);

                    if(temp->left !=NULL){
                        q.push(temp->left);
                    }

                    if(temp->right != NULL){
                        q.push(temp-> right);
                    }
                }
                ans.push_back(level);
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

    vector<vector<int>> result = root->levelOrder(root);

    for(vector<int> level : result){
        for(int val : level){
            cout<<val<<" ";
        }
        cout<<endl;
    }

    return 0;
}
