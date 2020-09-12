/*
*   struct ListNode {
*       int val;
*       ListNode *next;
*       ListNode() : val(0), next(nullptr) {}
*       ListNode(int x): val(x), next(nullptr) {}
*       ListNode(int x, ListNode *next): val(x), next(next) {}
*   }
*/

class Solution {
public:
    ListNode *partitionList(ListNode *head, int x) {
        // Time complexity: O(N) - N is length of head
        // Space complexity: O(1)

        // if head is null or there is only one element
        if (!head || !head->next)
            return head;

        // head of list that has smaller element
        ListNode *h1 = new ListNode();
        // current of h1
        ListNode *c1 = h1;
        // head of list that has greater or equal element
        ListNode *h2 = new ListNode();
        // current of h2
        ListNode *c2 = h2;

        // current
        ListNode *c = head;
        while (c) {
            if (c->val < x) {
                // append to end of h1
                c1->next = c;
                // update its current
                c1 = c1->next;
            } else {
                c2->next = c;
                c2 = c2->next;
            }
            // update current
            c = c->next;
        }
        // update the end of h2 list
        c2->next = nullptr;
        // the last element of h1 points to the first element of h2
        c1->next = h2->next;
        return h1->next;
    }
}
