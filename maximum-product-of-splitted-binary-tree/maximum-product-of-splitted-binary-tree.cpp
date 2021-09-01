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
    long long total_sum = 0;
    long long max_product = 0;
    const int modulo = 1e9 + 7;
public:
    long long getTotalSum(TreeNode* root) {
        // get total sum of subtree from root
        // by DFS
        long long lSum = 0; long long rSum = 0;
        if(root->left) lSum = getTotalSum(root->left);
        if(root->right) rSum = getTotalSum(root->right);
        
        return root->val = root->val + lSum + rSum;
    }
    long long getMaxProd(TreeNode* root) {
        // total_sum should be updated in advance!
        if(root->left) {
            long long lSum = root->left->val;
            max_product = max(max_product, (total_sum - lSum) * lSum);
            getMaxProd(root->left);
        }
        if(root->right) {
            long long rSum = root->right->val;
            max_product = max(max_product, (total_sum - rSum) * rSum);
            getMaxProd(root->right);
        }
        
        return max_product;
    }
    
    int maxProduct(TreeNode* root) {
        total_sum = getTotalSum(root);  // total_sum is updated!
        int maxProduct = getMaxProd(root) % modulo;
        
        return maxProduct;
    }
};