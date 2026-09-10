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

    Node* LCA(Node* root, Node* p, Node* q){
        if(root==NULL){
            return NULL;
        }

        if(root->val < p->val && root->val < q->val){
            return LCA(root->right, p, q);
        }else if(root->val > p->val && root->val > q->val){
            return LCA(root->left, p, q);
        }else{
            return root;
        }

        return NULL;

    }
};

int main(){
    Node* root= new Node(6);
    root->left= new Node(2);
    root->right= new Node(8);
    root->left->left= new Node(0);
    root->left->right= new Node(4);
    root->right->left= new Node(7);
    root->right->right= new Node(9);
    root->left->right->left= new Node(3);
    root->left->right->right= new Node(5);

    Node* p= root->left; // Node with value 2
    Node* q= root->left->right; // Node with value 4

    Node* lca= root->LCA(root, p, q);

    if(lca!=NULL){
        cout<<"Lowest Common Ancestor of "<<p->val<<" and "<<q->val<<" is: "<<lca->val<<endl;
    }else{
        cout<<"Lowest Common Ancestor not found."<<endl;
    }

    return 0;
}