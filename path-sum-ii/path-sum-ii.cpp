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
    vector<vector<int>> paths;
    vector<int> path;
    
    bool isLeaf(TreeNode* root) {
        return (root->left == nullptr) && (root->right == nullptr);
    }
    
    int dfs(TreeNode* root, int currentSum, int targetSum) {
        path.push_back(root->val);
        currentSum += root->val;
        if(isLeaf(root)) {
            if(currentSum == targetSum) {
                // path made
                paths.push_back(path);
            }
        }
        if(root->left) {
            dfs(root->left, currentSum, targetSum);
        } 
        if(root->right) {
            dfs(root->right, currentSum, targetSum);
        }
        
        path.pop_back();
        return 0;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root) dfs(root, 0, targetSum);        
        return paths;
    }
};