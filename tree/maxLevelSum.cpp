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
   int maxLevelSum(TreeNode *root) { 
        // Breath First Search
        // Time complexity: O(N) - N number of node in root
        // Space complexity: O(N)
        
        // if no root exist, return empty result
        if (!root)
            return 0;

        int max_val = INT_MIN;
        int level = 0;
        std::queue<TreeNode*> q;
        q.push(root);
        // current node
        TreeNode *c = nullptr;
        int s = 0,
            temp_level = 0;
        while (!q.empty()) {
            int temp = 0;
            // get the size of the current queue
            s = q.size();
            // update level
            ++temp_level;
            // loop through every node at its level
            for (int i = 0; i < s; ++i) {
                // get the current node
                c = q.front();
                // visit the current node
                temp += c->val;
                // if the node has left child, put in queue
                if (c->left)
                    q.push(c->left);
                // if the node has right child, put in queue
                if (c->right)
                    q.push(c->right);
                // remove the current node
                q.pop();
            }
            // if sum at current level is greater than max, update max
            // and update level
            if (temp > max_level) {
                max_val = temp;
                level = temp_level;
            }
        }
        return level;
    }
};
