/*
 * class Node {
 *      int val;
 *      std::vector<Node*> children;
 *      Node () {}
 *      Node(int val) : val(val) {}
 *      Node(int val, std::vector<Node*> children) : val(val), children(children) {}
 * };
 */

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(Node *root) {
        std::vector<std::vector<int>> ret;
        if (!root)
            return ret;

        std::queue<Node*> q;
        q.push(root);
        Node *c = nullptr;
        while (!q.empty()) {
            int s = q.size();
            std::vector<int> t;
            for (int i = 0; i < s; ++i) {
                c = q.front();
                t.push_back(c->val);
                for (Node *n : c->children)
                    q.push(n);
                q.pop();
            }
            ret.push_back(t);
        }
        return ret;
    }
}
