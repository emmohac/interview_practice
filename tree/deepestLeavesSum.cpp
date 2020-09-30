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
   int deepestLeavesSum(TreeNode *root){ 
        // Breath First Search
        // Time complexity: O(N) - N number of node in root
        // Space complexity: O(N)
        
        // if no root exist, return empty result
        if (!root)
            return 0;

        std::queue<TreeNode*> q;
        // temp array
        std::vector<int> t;
        q.push(root);
        // current node
        TreeNode *c = nullptr;
        while (!q.empty()) {
            // get the size of the current queue
            int s = q.size();
            // clear the array to always store the nodes at last level
            t.clear();
            // loop through every node at its level
            for (int i = 0; i < s; ++i) {
                // get the current node
                c = q.front();
                // visit the current node
                t.push_back(c->val);
                // if the node has left child, put in queue
                if (c->left)
                    q.push(c->left);
                // if the node has right child, put in queue
                if (c->right)
                    q.push(c->right);
                // remove the current node
                q.pop();
            }
        }
        int sum = 0;
        // return the sum of all values in t
        return accumulate(t.begin(), t.end(), sum);
    }
};
