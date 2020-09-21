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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Time complexity: O(N + M) - N is length of l1, M is length of l2
        // Space complexity: O(N + M) - N is elements in l1, M is elements in l2

        ListNode *c = nullptr;                      // current

        // adding element from l1 and l2 into s1 and s2 respectively
        std::stack<int> s1;
        for (c = l1; c != nullptr; c = c->next)
            s1.push(c->val);

        std::stack<int> s2;
        for (c = l2; c != nullptr; c = c->next)
            s2.push(c->val);

        // reclaim memory since not being used anymore
        delete c;

        ListNode *ret = nullptr;                    // return
        ListNode *t = nullptr;                      // temp

        int top, bot, carry = 0, sum = 0;

        while (!s1.empty() || !s2.empty()) {
            // if s1 is not empty, top is assigned to top of s1
            top = !s1.empty() ? s1.top() : 0;
            // if s2 is not empty, top is assigned to top of s2
            bot = !s2.empty() ? s2.top() : 0;
            // sum is total of carry, top and bot
            sum = carry + top + bot;
            // carry is sum divided by 10. Elementary basic math
            carry = sum / 10;
            // add to front of linked list
            // t is new node that carries the actual sum and points next to ret, initially nullptr
            t = new ListNode(sum % 10, ret);
            // update ret to be t
            ret = t;
            // if s1 is not empty, pop the top value
            if (!s1.empty())
                s1.pop();
            // if s2 is not empty, pop the top value
            if (!s2.empty())
                s2.pop();
        }
        // if carry is greater than 0 than add front to ret linked list
        ret = carry > 0 ? new ListNode(carry, ret) : ret;
        return ret;
    }
}
