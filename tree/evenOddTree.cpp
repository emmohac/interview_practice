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
    bool isEvenOddTree(TreeNode *root) {
        // Breath First Search
        // Time complexity: O(N) - N number of node in root
        // Space complexity: O(N)
        
        // if no root exist, return true
        if (!root)
            return true;

        std::queue<TreeNode*> q;
        q.push(root);
        // current node
        TreeNode *c = nullptr;
        // current level 
        int level = 0;
        while (!q.empty()) {
            // get the size of the current queue
            int s = q.size();
            // the last value seen in the queue, initially determined by the odd or even of the level
            int last_value = level % 2 == 0 ? INT_MIN : INT_MAX;
            // loop through every node at its level
            for (int i = 0; i < s; ++i) {
                // get the current node
                c = q.front();
                // if level is even, the value in the queue must be odd and strictly decreasing
                if (level % 2 == 0 && (c->val <= last_val || c->val % 2 == 0))
                    return false;
                // if level is odd, the value in the queue must be even and stricly increasing
                if (level % 2 != 0 && (c->val >= last_val || c->val % 2 != 0))
                    return false;
                // if the node has left child, put in queue
                if (c->left)
                    q.push(c->left);
                // if the node has right child, put in queue
                if (c->right)
                    q.push(c->right);
                // remove the current node
                q.pop();
                // update the last value to be the current value
                last_value = c->val;
            }
        }
        return true;
    }
};
