/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        queue<pair<Node*, int>> q;
        // (first: Node*, second: level)
        
        // init
        if(!root) return v;
        
        q.push(make_pair(root, 0));
        
        // bfs
        while(!q.empty()) {
            pair<Node*, int> cur = q.front(); q.pop();
            
            int level = cur.second;
            if (v.size() <= level) {
                v.push_back(vector<int>());
            }
            v[level].push_back(cur.first->val);
            for(auto i : cur.first->children) { // typeof cur.first->children == vector<Node*>
                if (i == nullptr) continue; // don't push to queue
                q.push(make_pair(i, level+1));
            }
        }
        
        return v;
    }
};