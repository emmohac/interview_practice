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
    void reorderList(ListNode *head) {
        // Time complexity: O(N) - N is length of linked list head
        // Space complexity: O(N) - N is length of linked list head
        // if linked list is nullptr or there is only one element
        if (!head || !head->next)
            return; 
        // create a stack to easily access the nodes in reversed order
        std::stack<ListNode*> container;
        ListNode *t = nullptr;                      // temp
        for (t = head; t != nullptr; t = t->next)
            container.push(t);

        ListNode *c = head;                         // current
        ListNode *n = nullptr;                      // next
        while (c) {
            // temp is the element on top of stack
            t = container.top();
            // next is element after current
            n = c->next;
            // if t is n, the linked list has even length, update current and terminate loop
            if (t == n) {
                c = c->next;
                break;
            } 
            // if c is t, the linked list has odd length, terminate loop
            if (c == t)
                break;
            // connect current with top of stack
            c->next = t;
            // connect top of stack with node after current
            t->next = n;
            // top element has served its purpose, pop to get the following one
            container.pop();
            // update current
            c = n;
        }
        // after current is nullptr, otherwise the linked list is circular
        c->next = nullptr;
    }
}
