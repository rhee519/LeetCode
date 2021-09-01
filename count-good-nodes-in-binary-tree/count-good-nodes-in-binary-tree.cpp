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
private:
    int goodCnt = 0;
public:
    int dfs(TreeNode* root, int maxVal) {
        if(root->val >= maxVal) {
            goodCnt++; maxVal = root->val;
        }
        if(root->left) dfs(root->left, maxVal);
        if(root->right) dfs(root->right, maxVal);
        
        return 0;
    }
    
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return goodCnt;
    }
};