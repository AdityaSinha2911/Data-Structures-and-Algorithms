#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    
    Node(int data){
        val=data;
        left=right=NULL;
    }
    bool isMirror(Node* root1, Node* root2){
        if(root1==NULL && root2==NULL){
            return true;
        }

        if(root1==NULL || root2==NULL){
            return false;
        }

        if(root1->val != root2->val){
            return false;
        }

        bool a1= isMirror(root1->left, root2->right);
        bool a2= isMirror(root1->right,root2->left);

        if(a1==true && a2==true){
            return true;
        }

        return false;
    }

    bool isSymmetric(Node* root) {
        if(root==nullptr){
            return true;
        }

        return isMirror(root->left, root->right);
    }    
};

int main(){
    Node* root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(2);
    root->left->left= new Node(3);
    root->left->right= new Node(4);
    root->right->left= new Node(4);
    root->right->right= new Node(3);

    if(root->isSymmetric(root)){
        cout<<"The tree is symmetric"<<endl;
    }
    else{
        cout<<"The tree is not symmetric"<<endl;
    }

    return 0;
}