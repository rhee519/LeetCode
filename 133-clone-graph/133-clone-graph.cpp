/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        
        unordered_map<Node*, Node*> ptr;
        queue<Node*> q;
        q.push(node);
        
        // clone nodes & mapping old-new node ptr's
        while(!q.empty()) {
            Node* curr = q.front(); q.pop();
            Node* clone = new Node(curr->val);
            ptr[curr] = clone;
            for(Node* next: curr->neighbors) {
                if(ptr.count(next)) continue;
                q.push(next);
            }
        }
        
        // connect new nodes
        for(auto& e: ptr) {
            Node* origin = e.first, *clone = e.second;
            vector<Node*> nb;
            for(Node* next: origin->neighbors) {
                nb.push_back(ptr[next]);
            }
            clone->neighbors = nb;
        }
        
        return ptr[node];
    }
};