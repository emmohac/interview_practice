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
    bool isLeaf(TreeNode *root) {
        return !root->left && !root->right;
    }
    // helper function
    void inorder(TreeNode *root, int current, int &sum){ 
        // if there is a root
        if (root) {
            // update the current value at each node
            current = current * 10 + root->val;
            // if node is leaf
            if (isLeaf(root)) {
                // update sum and terminate
                sum += current;
                return;
            }
            // recursively go to the left
            inorder(root->left, v);
            // recursively go to the right
            inorder(root->right, v);
        }
    }
    std::vector<int> inorderTraversal(TreeNode *root){
        // Time complexity: O(N) - N is number of node in root
        // Space complexity: O(N)
        int sum = 0;
        inorder(root, 0, sum);
        return sum;
    }
};
