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
    void inorder(TreeNode *root, std::vector<int> &v, int &i, int k) {
        // if there is a root
        if (root) {
            // recursively go to the left
            inorder(root->left, v, i, k);
            // visit the current node
            v.push_back(v->val);
            //increment i and check if i is equal k
            if (++i == k)
                return;
            // recursively go to the right
            inorder(root->right, v, i, k);
        }
    }
    int kthSmallest(TreeNode *root, int k);
        // Time complexity: O(k) 
        // Space complexity: O(k)
        std::vector<int> ret;
        inorder(root, ret, i, k);
        return ret[k-1];
    }
};
