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
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* curr = head;
        while(curr != nullptr) {
            curr = curr->next; len++;
        }
        
        vector<ListNode*> answer(k, nullptr);
        int idx = 0;
        while(len > 0) {
            int size = ceil((float)len/k--); 
            len -= size;
            answer[idx++] = curr = head;
            while(--size) curr = curr->next;
            head = curr->next; curr->next = nullptr;
        }
        
        return answer;
    }
};