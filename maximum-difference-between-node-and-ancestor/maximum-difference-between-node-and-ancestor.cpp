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
    int dfs(TreeNode* root, int& maxVal, int& minVal, int& ans) {
        if(!root) return 0;
        int lmax = -1, lmin = INT_MAX;
        int rmax = -1, rmin = INT_MAX;
        dfs(root->left, lmax, lmin, ans);
        dfs(root->right, rmax, rmin, ans);
        // cout << "val: " << root->val << "\n";
        // cout << "lmax: " << lmax << "\n";
        // cout << "lmin: " << lmin << "\n";
        // cout << "rmax: " << rmax << "\n";
        // cout << "rmin: " << rmin << "\n";
        
        int cmax = max(lmax, rmax);
        int cmin = min(lmin, rmin);
        if(cmax != -1) { // cmax exists
            ans = max(ans, abs(root->val-cmax));
        }
        if(cmin != INT_MAX) { // cmin exists
            ans = max(ans, abs(root->val-cmin));
        }
        
        maxVal = max(root->val, cmax);
        minVal = min(root->val, cmin);
        return 0;
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        int maxVal = 0, minVal = INT_MAX;
        dfs(root, maxVal, minVal, ans);
        return ans;
    }
};