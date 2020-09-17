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
    ListNode *oddEventList(ListNode *head) {
        // Time complexity: O(N) - N is length of linked list head
        // Space complexity: O(1)
        // if linked list is nullptr or there is only one element
        if (!head || !head->next)
            return head;

        ListNode *d = new ListNode(0, head);        // dummy
        ListNode *o = head,                         // odd
                *e = head->next,                    // even
                *he = head->next;                   // head of even to connect later

        ListNode *t = nullptr;                      // temp
        while (o && e) {
            // t is the one after even
            t = e->next;
            // if t is nullptr, it reaches the end of the list, so stop the loop
            if (!t)
                break;
            // next of odd is the one after even - which is odd position
            o->next = t;
            // next of even is the one after t - which is even position
            e->next = t->next;
            // update odd and even
            o = o->next;
            e = e->next;
        }
        // connect last of odd to head of even
        o->next = he;
        return d->next;
    }
}
