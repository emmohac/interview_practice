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
    void inorder(TreeNode *root, std::vector<int> &v) {
        if (root) {
            inorder(root->left, v);
            v.push_back(v->val);
            inorder(root->right, v);
        }
    }

    std::vector<int> inorderTraversal(TreeNode *root){
        std::vector<int> ret;
        inorder(root, ret);
        return ret;
    }
};
