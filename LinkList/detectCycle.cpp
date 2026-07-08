#include <iostream>
using namespace std;

struct ListNode{
    int head;
    ListNode* next;

    ListNode(int x){
        head=x;
        next=NULL;
    }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        bool isCycle=false;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                isCycle=true;
                break;
            }
        }

        if(!isCycle){
            return NULL;
        }

        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};

int main() {
    ListNode* first = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;   // Create cycle

    Solution obj;

    ListNode* ans = obj.detectCycle(first);

    if (ans != NULL)
        cout << "Cycle starts at node: " << ans->head << endl;
    else
        cout << "No cycle found";

    return 0;
}