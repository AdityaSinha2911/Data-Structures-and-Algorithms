#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int data){
        val=data;
        left=nullptr;
        right=nullptr;
    }

    Node* searchInBST(Node* root, int target){
        if(root==NULL){
            return NULL;
        }

        if(root->val ==target){
            return root;
        }

        if(root->val >target){
            return searchInBST(root->left,target);
        }else{
            return searchInBST(root->right, target);
        }
    }
};

int main(){
    Node* root= new Node(4);
    root->left= new Node(2);
    root->right= new Node(7);
    root->left->left= new Node(1);
    root->left->right= new Node(3);

    int target= 2;
    Node* result= root->searchInBST(root, target);

    if(result!=NULL){
        cout<<"Target "<<target<<" found in the BST."<<endl;
    }else{
        cout<<"Target "<<target<<" not found in the BST."<<endl;
    }

    return 0;
}