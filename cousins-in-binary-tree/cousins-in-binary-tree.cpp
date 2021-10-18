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
class Solution {
public:
    vector<int> nodes, parents, depths;
    void dfs(TreeNode* root, int x, int y, int parent, int depth) {
        if(root->val == x or root->val == y) {
            nodes.push_back(root->val);
            parents.push_back(parent);
            depths.push_back(depth);
            if(nodes.size() == 2) return;
        }
        if(root->left) dfs(root->left, x, y, root->val, depth+1);
        if(root->right) dfs(root->right, x, y, root->val, depth+1);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, x, y, -1, 0);
        return nodes.size() == 2 and nodes[0] != nodes[1] and parents[0] != parents[1] and depths[0] == depths[1];
    }
};