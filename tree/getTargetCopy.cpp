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
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
        // Breath First Search
        // Time complexity: O(N) - N number of node in root
        // Space complexity: O(N)
        
        // if no root exist, return empty result
        if (!original || !cloned)
            return nullptr;

        // a queue that contains pair of original and cloned 
        std::queue<std::pair<TreeNode*, TreeNode*>> q;
        
        q.push(std::make_pair(original, cloned));
        while (!q.empty()) {
            // get the original and the cloned
            TreeNode *o = q.front().first,
                     *c = q.front().second;
            // if the original is same as target, return cloned
            if (o == target)
                return c;
            // if original has left child, cloned also has left child
            if (o->left)
                q.push(std::make_pair(o->left, c->left));
            // if original has right child, cloned also has right child
            if (o->right)
                q.push(std::make_pair(o->right, c->right));
            // remove the current pair
            q.pop();
        }
        return nullptr;
    }
};
