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
    int rob(TreeNode* root) {
        if(!root) return 0;
        TreeNode* left = root->left, * right = root->right;
        int max_exclude = rob(left) + rob(right);
        int max_include = root->val;
        if(left) {
            if(left->left) max_include += left->left->val;
            if(left->right) max_include += left->right->val;
        }
        if(right) {
            if(right->left) max_include += right->left->val;
            if(right->right) max_include += right->right->val;
        }
        return root->val = max(max_exclude, max_include);
    }
};