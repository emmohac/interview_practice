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
    std::vector<int> largestValues(TreeNode *root){
        // Breath First Search
        // Time complexity: O(N) - N number of node in root
        // Space complexity: O(N)
        
        std::vector<int> ret;
        // if no root exist, return empty result
        if (!root)
            return ret;

        std::queue<TreeNode*> q;
        q.push(root);
        // current node
        TreeNode *c = nullptr;

        while (!q.empty()) {
            // get the size of the current queue
            int s = q.size();
            int max_val = std::INT_MIN;
            // loop through every node at its level
            for (int i = 0; i < s; ++i) {
                // get the current node
                c = q.front();
                // update the max value of the current row/level
                max_val = std::max(max_val, c->val);
                // if the node has left child, put in queue
                if (c->left)
                    q.push(c->left);
                // if the node has right child, put in queue
                if (c->right)
                    q.push(c->right);
                // remove the current node
                q.pop();
            }
            // append the max value into the ret array
            ret.push_back(max_val);
        }
        return ret;
    }
};
