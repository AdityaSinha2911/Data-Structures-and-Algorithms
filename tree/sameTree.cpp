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

    bool isSame(Node* p, Node* q){
        if(p==NULL && q==NULL){
            return true;
        }

        if(p==NULL || q==NULL){
            return false;
        }

        if(p->val != q->val){
            return false;
        }

        bool r1= isSame(p->left, q->left);
        bool r2= isSame(p->right, q->right);

        if(r1==true && r2==true){
            return true;
        }

        return false;
    }
};

int main(){
    Node* root1= new Node(1);
    root1->left= new Node(2);
    root1->right= new Node(3);

    Node* root2= new Node(1);
    root2->left= new Node(2);
    root2->right= new Node(3);

    if(root1->isSame(root1, root2)){
        cout<<"The two trees are same"<<endl;
    }
    else{
        cout<<"The two trees are not same"<<endl;
    }

    return 0;
}   