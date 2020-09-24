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
    std::vector<std::vector<int>> levelOrderZigZag(TreeNode *root){
        // Breath First Search
        // Time complexity: O(N) - N number of node in root
        // Space complexity: O(N)

        std::vector<std::vector<int>> ret;
        // if the root does not exist, return empty result
        if (!root)
            return ret;

        std::queue<TreeNode*> q;
        q.push(root);
        // current
        TreeNode *c = nullptr;
        // current level
        int level = 1;
        while (!q.empty()) {
            // get the current size of queue
            int s = q.size();
            // temp
            std::vector<int> t;
            // for every node in its level
            for (int i = 0; i < s; ++i) {
                // get the current node
                c = q.front();
                // visit the current node
                t.push_back(c->val);
                // if current node has left child, add to queue
                if (c->left)
                    q.push(c->left);
                // if current node has right child, add to queue
                if (c->right)
                    q.push(c->right);
                // remove current node
                q.pop();
            }
            // if the current level is even, reverse to make zig-zag liked, and update level
            if (level++ % 2 == 0) 
                std::reverse(t.begin(), t.end());
            // add temp to result array
            ret.push_back(t);
        }
        return ret;
    }
};
