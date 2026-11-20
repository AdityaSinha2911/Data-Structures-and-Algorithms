#include <bits/stdc++.h>
using namespace std;

class Tree{
    int val;
    Tree* left;
    Tree* right;

    Tree(int val){
        this->val=val;
        left=right=NULL;
    }
    public:

    Tree* fixTree(Tree* root){
        if(root->right==NULL)return root->left;

        if(root->left==NULL)return root->right;

        Tree* leftMostRight=root->right;

        while(leftMostRight->left!=NULL){
            leftMostRight=leftMostRight->left;
        }

        leftMostRight->left=root->left;

        return root->right;
    }

    Tree* deleteInBST(Tree* root, int key){
        if(root==NULL){
            return NULL;
        }

        if(root->val ==key){
            fixTree(root);
        }

        if(root->val <key){
            root->right=deleteInBST(root->right,key);
        }else{
            root->left=deleteInBST(root->left,key);
        }

        return root;
    }
};

int main(){

}