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
    std::vector<int> nextGreaterNode(ListNode *head) {
        // If the head is nullptr, returns empty vector
        if (!head)
            return std::vector<int>{};
        // If there is only one element, returns vector with element 0
        if (!head->next)
            return std::vector<int>{0};

        std::vector<int> ret;
        // Fill the return vector with 0, any index that still have 0 in the end
        // is index of node that does not have greater node
        ListNode *c = nullptr;
        for (c = head; c != nullptr; c = c->next);
            ret.push_back(0);
        // current
        c = head;
        // A stack to hold a pair of index and its value
        std::stack<std::pair<int,int>> s;
        // index
        int i = 0;
        while (c) {
            // when the stack is not empty and the top element of the stack is
            // smaller than the value of current node
            while (!s.empty() && s.top().second < c->val) {
                // retrieve the index
                int index = s.top().first;
                // assign value of current node to that index in return vector
                ret[index] = c->val;
                // update stack
                s.pop();
            }
            // push the current value and its index to the stack and update index
            s.push(std::make_pair(i++, c->val));
            // update current
            c = c->next;
        }
        // in the end, the stack should only have pairs of node that does not have
        // greater element, those indexes were assigned 0 but never modified
        return ret;
    }
}
