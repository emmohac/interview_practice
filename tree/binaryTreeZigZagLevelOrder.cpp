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
        std::vector<std::vector<int>> ret;
        if (!root)
            return ret;

        std::queue<TreeNode*> q;
        q.push(root);
        TreeNode *c = nullptr;
        int level = 1;
        while (!q.empty()) {
            int s = q.size();
            std::vector<int> t;
            for (int i = 0; i < s; ++i) {
                c = q.front();
                t.push_back(c->val);
                if (c->left)
                    q.push(c->left);
                if (c->right)
                    q.push(c->right);
                q.pop();
            }
            if (level++ % 2 == 0) 
                std::reverse(t.begin(), t.end());
            ret.push_back(t);
        }
        return ret;
    }
};
