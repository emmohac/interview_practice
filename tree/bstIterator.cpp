/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    queue<int> q;
    void inorder(TreeNode *root, queue<int> &q) {
        if (root) {
            inorder(root->left, q);
            q.push(root->val);
            inorder(root->right, q);
        }
    }
public:
    BSTIterator(TreeNode* root) {
       inorder(root, this->q); 
    }
    
    /** @return the next smallest number */
    int next() {
        int ret = this->q.front();
        q.pop();
        return ret;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !q.empty();
    }
};
