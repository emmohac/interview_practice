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
    bool allLessThan(TreeNode *root, TreeNode *left) {
        if (!root && !left || root && !left)
            return true;
        if (!root && left)
            return false;
        return root->val > left->val && allLessThan(root, left->left) && allLessThan(root, left->right);
    }

    bool allGreaterThan(TreeNode *root, TreeNode *right) {
        if (!root && !right || root && !right)
            return true;
        if (!root && right)
            return false;
        return root->val < right->val && allGreaterThan(root, right->left) && allGreaterThan(root, right->right);
    }

    bool validateBST(TreeNode *root) {
        if (!root)
            return true;
        return allLessThan(root, root->left) && allGreaterThan(root, root->right) && validateBST(root->left) && validateBST(root->right);
    }
};
