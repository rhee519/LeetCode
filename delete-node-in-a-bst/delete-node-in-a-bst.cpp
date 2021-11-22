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
    void insert(TreeNode*& root, TreeNode*& node) {
        if(!node) return;
        if(!root) {
            root = node; return;
        }
        if(root->val >= node->val) 
            insert(root->left, node);
        else insert(root->right, node);
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(key < root->val) root->left = deleteNode(root->left, key);
        else if(key > root->val) root->right = deleteNode(root->right, key);
        else { // root->val == key
            insert(root->right, root->left);
            root = root->right;
        }
        return root;
    }
};