/*
* struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}
*/

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Time complexity: O(N) - N is length of linked list
        // Space complexity: O(1)
        // if there is no head or linked list has only one node
        if (!head || !head->next)
            return head;
        
        ListNode *c = head,     // current
                *t = nullptr,   // temp
                *p = nullptr;   // prev

        while (c && c->next) {
            // update temp to be the one after current
            t = c->next;
            // element after current is element after temp
            c->next = t->next;
            // element after temp is now current
            t->next = c;
            if (!p)
                head = t;       // head is now element after current, in case prev hasnt been set
            else
                p->next = t;    // otherwise, element after prev is temp
            // prev is now current so that its next element can be updated later
            p = c;
            // updating current
            c = c->next;
        }
        return head;
    }
}
