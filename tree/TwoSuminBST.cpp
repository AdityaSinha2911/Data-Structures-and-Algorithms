#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int data) {
        val = data;
        left = right = NULL;
    }
};


class Solution {
public:

    stack<Node*> asc;
    stack<Node*> desc;


    Node* getNextSmall() {

        if (asc.empty()) {
            return NULL;
        }

        Node* small = asc.top();
        asc.pop();

        Node* rightChild = small->right;

        while (rightChild) {
            asc.push(rightChild);

            rightChild = rightChild->left;
        }

        return small;
    }


    Node* getNextBig() {

        if (desc.empty()) {
            return NULL;
        }

        Node* big = desc.top();
        desc.pop();

        Node* leftChild = big->left;

        while (leftChild) {
            desc.push(leftChild);

            leftChild = leftChild->right;
        }

        return big;
    }


    bool findTarget(Node* root, int k) {

        if (root == NULL) {
            return false;
        }


        // Initialize ascending stack
        Node* t = root;

        while (t) {
            asc.push(t);
            t = t->left;
        }


        // Initialize descending stack
        t = root;

        while (t) {
            desc.push(t);
            t = t->right;
        }


        Node* i = getNextSmall();
        Node* j = getNextBig();


        while (i && j && i != j) {

            int sum = i->val + j->val;


            if (sum == k) {
                return true;
            }


            if (sum > k) {
                j = getNextBig();
            }
            else {
                i = getNextSmall();
            }
        }


        return false;
    }
};

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(7);

    Solution solution;
    int k = 9;

    if (solution.findTarget(root, k)) {
        cout << "Found two elements in the BST that sum up to " << k << endl;
    }
    else {
        cout << "No two elements found in the BST that sum up to " << k << endl;
    }

    return 0;
}