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
    int diameter = 0;
public:
    int height(TreeNode* root) {
        if(!root) return 0;
        int heightLeft = height(root->left), heightRight = height(root->right);
        root->val = max(heightLeft, heightRight) + 1;
        int dist = heightLeft + heightRight;
        diameter = max(diameter, dist);
        
        return root->val;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};