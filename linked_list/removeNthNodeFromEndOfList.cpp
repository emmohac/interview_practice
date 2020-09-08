/**
* struct ListNode {
*   int val;
*   ListNode *next;
*   ListNode() : val(0), next(nullptr) {}
*   ListNode(int x) : val(x), next(nullptr);
*   ListNode(int x, ListNode *next) : val(x), next(next) {}
*};
*/

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Time complexity: O(N) - N is the length of head
        // Space complexity: O(1)

        // returns nullptr if head is nullptr or if there is only 
        // one element in the list, assuming n is valid - meaning n will be 1
        if (!head || !head->next)
            return nullptr;

        // special case when n is 1, the last element in the list is removed
        if (n == 1) {
            ListNode *current = head;
            // stop at the element before the last element in the linked list
            while (current->next->next)
                current = current->next;
            ListNode *to_delete = current->next;
            // current becomes the last element
            current->next = nullptr;
            delete to_delete;
        } else { // general case
            ListNode *current = head;
            // start with 1
            for (int i = 1; i < n; ++i)
                current = current->next;
            ListNode *to_change = head;
            // current is n-1 nodes away from to_change
            while (current->next) {
                current = current->next;
                to_change = to_change->next;
            }
            // to_change is now the nth element that needs to be deleted
            ListNode *to_delete = to_change->next;
            // update corresponding value and next pointer
            to_change->val = to_delete->val;
            to_change->next = to_delete->next;
            delete to_delete;
        }
        return head;
    }
}
