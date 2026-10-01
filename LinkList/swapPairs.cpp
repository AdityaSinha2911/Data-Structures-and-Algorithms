#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {

public:
    ListNode* swapNodes(ListNode* first, ListNode* second) {
        ListNode* temp = second->next;

        second->next = first;
        first->next = temp;

        return second;
    }

    ListNode* swapPairs(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode* first = head;
        ListNode* second = head->next;


        head = swapNodes(first, second);

        ListNode* prev = first;

        while (prev->next != NULL && prev->next->next != NULL) {

            first = prev->next;
            second = first->next;

            ListNode* newHead = swapNodes(first, second);

            prev->next = newHead;

            prev = first;
        }

        return head;
    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head = s.swapPairs(head);
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
}