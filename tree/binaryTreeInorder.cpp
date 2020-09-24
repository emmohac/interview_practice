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
    // helper function
    void inorder(TreeNode *root, std::vector<int> &v) {
        // if there is a root
        if (root) {
            // recursively go to the left
            inorder(root->left, v);
            // visit the current node
            v.push_back(v->val);
            // recursively go to the right
            inorder(root->right, v);
        }
    }
    std::vector<int> inorderTraversal(TreeNode *root){
        // Time complexity: O(N) - N is number of node in root
        // Space complexity: O(N)
        std::vector<int> ret;
        inorder(root, ret);
        return ret;
    }
};
