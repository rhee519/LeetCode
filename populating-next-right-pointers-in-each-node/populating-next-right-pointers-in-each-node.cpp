/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // BFS
        queue<pair<Node*, int>> q;
        if(!root) return root;
        q.push({root, 0});
        pair<Node*, int> curr = {nullptr, 0};
        while(!q.empty()) {
            auto p = q.front(); q.pop();
            Node* parent = p.first;
            int level = p.second;
            if(curr.first and curr.second == level) {
                curr.first->next = parent;
            }
            if(parent->left) q.push({parent->left, level+1});
            if(parent->right) q.push({parent->right, level+1});
            curr = p;
        }
        return root;
    }
};