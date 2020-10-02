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
    bool flipEquiv(TreeNode *root1, TreeNode *root2) {
        // Time complexity: O(N) - N is the minimum number of node within 2 trees
        // Space complexity: O(N) - the function is called N time, N is same as above

        // if both roots are nullptr, return true
        if (!root1 && !root2)
            return true;
        // if one of the root is nullptr, return false
        if (!root1 && root2 || !root2 && root1)
            return false;
        // first compare the value, if false then no need to call the other flipEquiv
        return root1->val == root2->val &&
            // check on left of root1 and right of root2
            (flipEquiv(root1->left, root2->right) &&
            // and check on right of root1 and left of root2
            flipEquiv(root1->right, root2->left)) ||
            // or because the other tree can be partially flipped, not
            // stricly flipped
            (flipEquiv(root1->right, root2->right) &&
            flipEquiv(root1->left, root2->left));
    }
};
