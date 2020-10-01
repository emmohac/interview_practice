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
    // helper function
    void inorder(TreeNode *root, std::vector<int> &v) {
        // if there is a root
        if (root) {
            // recursively go to the left
            inorder(root->left, v);
            // visit the current node
            v.push_back(v->val);
            // recursively go to the right
            inorder(root->right, v);
        }
    }
    std::vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        // Time complexity: O(N) - N is the maximum number of nodes in root1 and root2
        // Space complexity: O(N)
        
        std::vector<int> v1;
        // get all sorted element in root1 into v1
        inorder(root1, v1);
        std::vector<int> v2;
        // get all sorted element in root2 into v2
        inorder(root2, v2);
        std::vector<int> ret;

        int s1 = v1.size(),
            s2 = v2.size();
        int i = 0,
            j = 0;
        
        // merge them
        while (i < s1 && j < s2) {
            // insert the smaller element to the ret array
            if (v1[i] < v2[j])
                ret.push_back(v1[i++]);
            else
                ret.push_back(v2[j++]);
        }

        // if i is still less than s1, the trees have unequal number of nodes
        // so add the rest of v1 to ret
        while (i < s1)
            ret.push_back(v1[i++]);

        
        // if j is still less than s2, the trees have unequal number of nodes
        // so add the rest of v2 to ret
        while (j < s2)
            ret.push_back(v2[j++]);

        return ret;
    }
};
