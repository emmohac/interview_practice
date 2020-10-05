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
    int uniqueBST(int k) {
        // Time complexity: O(k*k) - k is number of node in root
        // Space complexity: O(k)
        int dp[k + 1];
        for (int i = 0; i < k + 1; ++i)
            dp[i] = 0;
        dp[0] = 1;
        dp[1] = 1;

        for (int num_of_node = 2; num_of_node <= k; ++num_of_node) 
            for (int root_node = 1; root_node < num_of_node; ++root_node)
                dp[num_of_node] += dp[root_node - 1] * dp[num_of_node - root_node];

        return dp[k];
    
    }
};
