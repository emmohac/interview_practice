/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    // this function is called to check if the value at root is same as value at head
    // if so, it will check value of left child and head next or right child and head next
    bool hasSameElement(TreeNode *root, ListNode *head) {
        // if the tree has no more node but linked list still has node, 
        // linked list is not sub path of tree
        if (!root && head)
            return false;
        // if the list has no more element but tree still has element, or
        // both tree and list has no more element, then return true
        if (!head && root || !root && !head)
            return true;
        // otherwise, compare the value and check for left child with next node
        // or right child with next node
        return root->val == head->val && (hasSameElement(root->left, head->next) 
                                    || hasSameElement(root->right, head->next));
    }

    bool isSubPath(ListNode *head, TreeNode *root) {
        // Time complexity: O()
        // Space complexity: O()
        // if the tree has no more node but linked list still has node, 
        // linked list is not sub path of tree
        if (!root && head)
            return false;
        // if they both have elements and linked list is sub path of tree
        // return true
        if (hasSameElement(root, head))
            return true;
        // otherwise, look for left child or right child of tree
        else
            return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
