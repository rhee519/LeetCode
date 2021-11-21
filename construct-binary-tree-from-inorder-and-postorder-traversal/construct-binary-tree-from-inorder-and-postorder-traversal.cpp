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
    unordered_map<int, int> index;
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr) {
        // inorder[il:ir]과 postorder[pl:pr]이 대응
        // 이를 Tree로 구성하여 head를 return
        if(il > ir or pl > pr) return nullptr;
        if(il == ir and pl == pr and inorder[il] == postorder[pl]) {
            return new TreeNode(inorder[il]);
        }
        
        TreeNode* root = new TreeNode(postorder[pr]);
        int mid = index[postorder[pr]];
        
        // left: inorder[il:mid-1] == postorder[pl:pl+(mid-1)-il]
        // right: inorder[mid+1:ir] == postorder[pl+mid-il:pr-1]
        TreeNode* left = build(inorder, postorder, il, mid-1, pl, pl+(mid-1)-il);
        TreeNode* right = build(inorder, postorder, mid+1, ir, pl+mid-il, pr-1);
        root->left = left; root->right = right;
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        
        return build(inorder, postorder, 0, n-1, 0, n-1);
    }
    
    // inorder => left, root, right
    // postorder => left, right, root
};