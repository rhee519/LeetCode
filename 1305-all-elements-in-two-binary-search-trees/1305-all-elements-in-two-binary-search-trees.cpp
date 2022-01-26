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
    void dfs(vector<int>& con, TreeNode* root) {
        if(!root) return;
        dfs(con, root->left);
        con.push_back(root->val);
        dfs(con, root->right);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans, con1, con2;
        int i = 0, j = 0;
        dfs(con1, root1);
        dfs(con2, root2);
        while(i < con1.size() and j < con2.size()) {
            if(con1[i] <= con2[j]) ans.push_back(con1[i++]);
            else ans.push_back(con2[j++]);
        }
        
        while(i < con1.size()) ans.push_back(con1[i++]);
        while(j < con2.size()) ans.push_back(con2[j++]);
        
        return ans;
    }
};