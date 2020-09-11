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
    ListNode *deleteDuplicate(ListNode *head) {
        // Time complexity: O(N) - N is the length of head
        // Space complexity: O(K) - K is the number of unique element

        // returns nullptr if head is nullptr or if there is only 
        // one element in the list
        if (!head || !head->next)
            return nullptr;

        // create dummy node in case there is no unique element
        ListNode *k = new ListNode(-1, head);
        std::unordered_map<int,int> counts;
        // count how many times each element occurs
        for (ListNode *c = head; c != nullptr; c = c->next)
            counts[c->val] += 1;
        // a pointer to use
        ListNode *t = k;
        ListNode *to_delete = nullptr;
        // check t->next because t is k and i k is actually dummy node
        while (t->next) {
            // if the next element is not unique
            if (counts[t->next->val] != 1) {
                // mark it
                to_delete = t->next;
                // update t->next
                t->next = to_delete->next;
                // delete marked node
                delete to_delete;
            } else 
                t = t->next;
        }
        return k->next;
    }
}
