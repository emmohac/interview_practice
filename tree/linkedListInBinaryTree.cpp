/*
 * struct TreeNode {
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode(): val(0), left(nullptr), right(nullptr) {}
 *      TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
 *      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 */
class Solution {
public:
    bool hasSameElement(TreeNode *root, ListNode *head) {
        if (!root && head)
            return false;
        if (!head && root || !root && !head)
            return true;
        return root->val == head->val && (hasSameElement(root->left, head->next) || hasSameElement(root->right, head->next));
    }

    bool isSubPath(TreeNode *root, ListNode *head) {
        if (!root && head)
            return false;
        if (hasSameElement(root, head))
            return true;
        return isSubPath(root->left, head) || isSubPath(root->right, head);
    }
};
