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
    void insert(TreeNode* root, TreeNode* child) {
        if(root->val < child->val) {
            if(root->right) insert(root->right, child);
            else root->right = child;
        } else {
            if(root->left) insert(root->left, child);
            else root->left = child;
        }
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1; i < preorder.size(); i++) {
            TreeNode* child = new TreeNode(preorder[i]);
            insert(root, child);
        }
        
        return root;
    }
};