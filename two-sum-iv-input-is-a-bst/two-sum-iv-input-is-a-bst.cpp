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
class BSTIterator {
private:
    stack<TreeNode*> st;
    bool fromLeft = true;
    void push(TreeNode* root) {
        while(root) {
            st.push(root);
            root = fromLeft? root->left : root->right;
        }
    }
public:
    BSTIterator(TreeNode* root, bool fromLeft = true) : fromLeft(fromLeft) {
        push(root);
    }
    int next() {
        TreeNode* top = st.top(); st.pop();
        if(fromLeft) push(top->right);
        else push(top->left);
        
        return top->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator leftIt(root), rightIt(root, false);
        int left = leftIt.next();
        int right = rightIt.next();
        
        // two-pointer
        while(left < right) {
            if(left + right == k) return true;
            else if(left + right < k) { // increase left
                left = leftIt.next();
            } else { // decrease right
                right = rightIt.next();
            }
        }
        
        return false;
    }
};