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
    ListNode *rotateRight(ListNode *head) {
        // Time complexity: O(N) - N is length of linked list head
        // Space complexity: O(1)
        // if linked list is nullptr or there is only one element
        if (!head || !head->next)
            return head;
        // there is at least one element
        int len = 1;
        ListNode *tail = head;
        // finding tail and length of the linked list
        while (tail->next) {
            tail = tail->next;
            ++len;
        }
        // getting k since k can be greater than the actual length
        k %= len;
        // k is 0 means n elements get rotated n times, result in itself
        if (!k)
            return head;
        // steps from tail to the new tail - moving k element to the right means last element of new list is at position length - k
        int steps = len - k;
        ListNode *new_tail = tail;
        // making circular linked list to find new tail
        tail->next = head;
        // finding the new tail
        while (steps--) 
            new_tail = new_tail->next;
        // the one after new tail is the new head
        ListNode *new_head = new_tail->next;
        // terminate circular linked list
        new_tail->next = nullptr;
        return new_head;
    }
}
