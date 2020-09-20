/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        // Time complexity: O(N) - N is length of linked list
        // Space complexity: O(1)

        // if there is no linked list or only one element exists
        // or m is same as n, then nothing to reverse
        if (!head || !head->next || m == n)
            return head;

        // a dummy node to return in case m is 1
        ListNode *d = new ListNode(0, head);
        // finding the previous - the node before the node at m
        ListNode *p = d;
        for (int i = 0; i < m - 1; ++i)
            p = p->next;

        // current node is node after previous
        ListNode *c = p->next;
        // the node after the current node
        ListNode *a = nullptr;
        for (int i = 0, k = n - m; i < k; ++i){
            // update after
            a = c->next;
            // next of current is next of after
            c->next = a->next;
            // next of after is next of previous
            a->next = p->next;
            // update previous to be after
            p->next = a;
        }
        return d->next;
    }
};

