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
    TreeNode *find_smallest(TreeNode *root) {
        while (root->left)
            root = root->left;
        return root;
    }
    TreeNode *deleteNode(TreeNode *root, int val) {
        // Time Complexity: O(log(N)) - N is number of node in root
        // Space complexity: O(log(N))
        // if root is nullptr, return nullptr
        if (!root)
            return nullptr;
        // if key < current node value, look on the left
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        // if key > current node value, look on the right
        else if (root->val > key)
            root->right = deleteNode(root->right, key);
        // if key is same as current value
        else {
            // if key is a leaf node
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            // if key has right child
            else if (!root->left) {
                TreeNode *ret = root->right;
                delete root;
                return ret;
            } 
            // if key has left child
            else if (!root->right) {
                TreeNode *ret = root->left;
                delete root;
                return ret;
            } 
            // if key has both children
            else {
                // find the smallest element of the right child
                TreeNode *smallest = find_smallest(root->right);
                // update value of root
                root->val = smallest->val;
                // delete the node that has the value of current node
                root->right = deleteNode(root->right, root->val);
                // return root
                return root
            }
        }
        return root;
    }
};
