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
    void preorder(TreeNode *root, std::vector<int> &v) {
        if (root) {
            v.push_back(v->val);
            preorder(root->left, v);
            preorder(root->right, v);
        }
    }

    std::vector<int> preorderTraversal(TreeNode *root){
        std::vector<int> ret;
        preorder(root, ret);
        return ret;
    }
};
