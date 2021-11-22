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
    
    void dfs(TreeNode*& root, TreeNode*& parent, int key) {
        if(!root) return;
        if(root->val > key) {
            dfs(root->left, root, key); return;
        } else if(root->val < key) {
            dfs(root->right, root, key); return;
        }
        
        // found
        insert(root->right, root->left);
        root->left = nullptr;
        root = root->right;
        // insert(parent, root);
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* parent = nullptr;
        dfs(root, parent, key);
        return root;
    }
};