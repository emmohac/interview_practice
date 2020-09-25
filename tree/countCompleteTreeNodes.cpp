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
    int countNodes(TreeNode *root) {
        // Time complexity: O(log(N)) - N is number of nodes in root
        // Space complexity: O(log(N))

        // if there is no root, return 0 
        if (!root)
            return 0;

        int leftNodes = 0,
            rightNodes = 0;
        
        // count the nodes on the right
        for (TreeNode *r = root->right; r; r = r->right)
            ++rightNodes;

        // count the nodes on the left
        for (TreeNode *l = root->left; l; l = l->left)
            ++leftNodes;

        // if left nodes is same as right nodes, this is a perfect binary tree
        // so the number of node is pow(2, heigh of tree) - 1
        if (rightNodes == leftNodes)
            return pow(2, leftNodes + 1) - 1;
        // this is not a perfect tree, so recursively calculate number of node on left and right plus root node
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
