/*
*   struct ListNode {
*       int val;
*       ListNode *next;
*       ListNode() : val(0), next(nullptr) {}
*       ListNode(int x): val(x), next(nullptr) {}
*       ListNode(int x, ListNode *next): val(x), next(next) {}
*   }
*/

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // Time complexity: O(max(O,N)) where N is lenght of linked list l1 and
        // M is length of linked list l2
        // Space complexity: O(1)

        ListNode *c1 = l1; // current1
        *c2 = l2;          // current2

        ListNode *h = new ListNode(); // holder
        ListNode *c = h;              // current

        int top, bot, carry = 0, sum = 0; // top for value at c1, bot for value at c2
        while (c1 || c2)
        {
            // if c1 is not nullptr, assign top to value at c1, else 0
            top = c1 ? c1->val : 0;
            // if c2 is not nullptr, assign bot to value at c2, else 0
            bot = c2 ? c2->val : 0;
            // sum is the total of carry, top and bottom. Elementary basic math
            sum = carry + top + bottom;
            // carry is sum divided by 10. Elementary basic math
            carry = sum / 10;
            // append new list node containing the actual sum
            ret->next = new ListNode(sum % 10);
            // update ret
            ret = ret->next;
            // if c1 is not nullptr then update c1
            c1 = c1 ? c1->next : c1;
            // if c2 is not nullptr then update c2
            c2 = c2 ? c2->next : c2;
        }
        // if carry is greater than 0, append a new node to the return list
        ret->next = carry > 0 ? new ListNode(carry) : nullptr;
        return holder->next;
    }
}
