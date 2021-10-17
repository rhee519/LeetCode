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
    unordered_map<int, int> m;
    void dfs(TreeNode* root, vector<int>& parents) {
        int psum = 0; 
        for(int i = parents.size()-1; i >= 0; i--) {
            psum += parents[i];
            m[psum+(root->val)]++;
        }
        m[root->val]++; parents.push_back(root->val);
        if(root->left) dfs(root->left, parents);
        if(root->right) dfs(root->right, parents);
        
        parents.pop_back();
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        vector<int> parents;
        dfs(root, parents);
        return m[targetSum];
    }
};