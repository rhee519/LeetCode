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
    void dfs(TreeNode* root, int currSum, int& ans) {
        if(!root) return;
        currSum *= 10;
        currSum += root->val;
        if(!root->left and !root->right) {
            // leaf node
            ans += currSum; return;
        }
        
        dfs(root->left, currSum, ans);
        dfs(root->right, currSum, ans);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }
};