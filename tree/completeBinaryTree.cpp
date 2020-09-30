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
   bool isCompleteTree(TreeNode *root) { 
        // Breath First Search
        // Time complexity: O(N) - N number of node in root
        // Space complexity: O(N)
        
        // if no root exist, it is indeed a complete binary tree
        if (!root)
            return true;

        std::queue<TreeNode*> q;
        q.push(root);
        // initially nullptr is not found
        bool found_null = false;
        while (!q.empty()) {
            // current node
            TreeNode *c = q.front();
            // nullptr is found
            if (!c)
                found_null = true;
            // the second time nullptr is found but current is not nullptr then it is not a complete binary tree
            else if (found_null)
                return false;
            // otherwise, append left child then right child
            else {
                q.push(c->left);
                q.push(c->right);
            }
            // remove current node
            q.pop();
        }
        
        return true;
    }
};
