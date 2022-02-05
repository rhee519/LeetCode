/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct compare {
    bool operator() (ListNode*& a, ListNode*& b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(ListNode* list: lists) {
            while(list) {
                pq.push(list);
                list = list->next;
            }
        }
        
        ListNode* head = nullptr;
        if(!pq.empty()) {
            head = pq.top(); pq.pop();
        }
        ListNode* curr = head;
        while(!pq.empty()) {
            ListNode* node = pq.top(); pq.pop();
            node->next = nullptr;
            curr->next = node;
            curr = node;
        }
        
        return head;
    }
};