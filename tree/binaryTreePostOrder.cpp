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
    void postorder(TreeNode *root, std::vector<int> &v) {
        if (root) {
            postorder(root->left, v);
            postorder(root->right, v);
            v.push_back(v->val);
        }
    }

    std::vector<int> postorderTraversal(TreeNode *root){
        std::vector<int> ret;
        postorder(root, ret);
        return ret;
    }
};
