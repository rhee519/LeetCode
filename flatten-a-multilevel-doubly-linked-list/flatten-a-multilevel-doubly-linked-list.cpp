/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flattenChild(Node* head) {
        if(!head) return nullptr;
        Node* curr = head->child;
        if(curr) { // head->child exists
            Node* next = head->next;
            head->next = curr;
            curr->prev = head;
            while(curr->next) curr = curr->next;
            curr->next = next;
            if(next) next->prev = curr;
            head->child = nullptr;
        }
        
        flattenChild(head->next);
        return head;
    }
    
    Node* flatten(Node* head) {
//         flattenChild(head);
//         Node* prev = nullptr;
//         for(Node* curr = head; curr; curr = curr->next) {
//             prev = curr;
//             cout << curr->val << " ";
//         } cout << "\n";
//         for(Node* curr = prev; curr; curr = curr->prev) {
//             cout << curr->val << " ";
//         } cout << "\n";
        
        return flattenChild(head);
        // return nullptr;
    }
};