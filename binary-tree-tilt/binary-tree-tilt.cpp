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
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        TreeNode *left = root->left, *right = root->right;
        int ltilt_sum = findTilt(left);
        int rtilt_sum = findTilt(right);
        int left_val = left? left->val : 0;
        int right_val = right? right->val : 0;
        root->val += left_val + right_val;
        int tilt = abs(left_val-right_val);
        // cout << "root: " << root->val << ", tilt: " << tilt << "\n";
        return tilt + ltilt_sum + rtilt_sum;
    }
};