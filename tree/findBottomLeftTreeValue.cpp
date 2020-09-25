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
    std::vector<std::vector<int>> levelOrderTraversal(TreeNode *root){
        // Breath First Search
        // Time complexity: O(N) - N number of node in root
        // Space complexity: O(N)
        
        std::vector<int> t;
        std::queue<TreeNode*> q;
        q.push(root);
        // current node
        TreeNode *c = nullptr;
        while (!q.empty()) {
            // get the size of the current queue
            int s = q.size();
            // clear everything in the array
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
        // at the end of the loop, t is the array that contains the
        // last level of the tree, therefore, t[0] is the first element that needs to be returned
        return t[0];
    }
};
