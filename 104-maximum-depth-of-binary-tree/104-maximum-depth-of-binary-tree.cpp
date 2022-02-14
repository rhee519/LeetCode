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
    void dfs(TreeNode* root, int& max_depth, int depth) {
        if(!root) {
            max_depth = max(max_depth, depth);
            return;
        }
        dfs(root->left, max_depth, depth+1);
        dfs(root->right, max_depth, depth+1);
    }
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        dfs(root, max_depth, 0);
        return max_depth;
    }
};