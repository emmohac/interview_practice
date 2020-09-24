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
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        // Time Complexity: O(log(N)) - N is number of node in root
        // Space complexity: O(log(N))
        if (!root)
            root = new TreeNode(val);
        else if (root->val < val)
            root->right = insertIntoBST(root->right, val);
        else if (root->val > val)
            root->left = insertIntoBST(root->left, val);
        return root;
    }
};
