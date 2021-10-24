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
    int height = -1;
    void getHeight(TreeNode* root) {
        height++; 
        if(root->left) getHeight(root->left);
    }
    
    int findRightEnd(TreeNode* root, int node, int h) {
        if(!root) return -1;
        if(h == height) return node;
        int right = findRightEnd(root->right, node*2+1, h+1);
        if(right != -1) return right;
        return findRightEnd(root->left, node*2, h+1);
    }
    
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        getHeight(root);
        return findRightEnd(root, 1, 0);
    }
};