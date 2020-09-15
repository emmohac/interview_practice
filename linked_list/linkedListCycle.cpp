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
    ListNode *detectCycle(ListNode *head)
    {
        // Time complexity: O(N) - N is length of linked list
        // Space complexity: O(1)

        // if there is no linked list or only one element exists
        if (!head || !head->next)
            return nullptr;

        ListNode *s = head, // slow
            *f = head;      // fast

        while (f && f->next)
        {
            // update s
            s = s->next;
            // update f to be x2 faster than s
            f = f->next->next;
            // stop the loop if slow and fast are at same element
            if (s == f)
                break;
        }

        // if slow is not same as fast and the loop stopped, meaning there is no
        // cycle
        if (s != f)
            return nullptr;

        // make slow become head again and keep fast at same position
        s = head;

        // if the condition above did not return nullptr, meaning there is a
        // cycle
        while (s != f)
        {
            // update both pointer equally at this time.
            s = s->next;
            f = f->next;
        }
        return s;
    }

    ListNode *detectCycle2(ListNode *head)
    {
        // Time complexity: O(N) - N is length of linked list
        // Space complexity: O(N)

        // container to hold unique pointer
        std::unordered_set<ListNode *> container;
        ListNode *c = head; // current
        while (c)
        {
            // if the pointer is already in container, there is a cycle
            if (container.find(c) != container.end())
                return c;
            // insert the pointer in the container and update current
            container.insert(c);
            c = c->next;
        }
        return nullptr;
    }
};
