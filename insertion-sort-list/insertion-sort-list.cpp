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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *sorted = nullptr;
        ListNode *curr = head, *prev = nullptr;
        while(curr) {
            ListNode* next = curr->next;
            if(sorted) {
                if(curr->val < sorted->val) {
                    curr->next = sorted;
                    sorted = curr;
                } else {
                    ListNode* it = sorted;
                    while(it->next and it->next->val < curr->val) it = it->next;
                    ListNode* temp = it->next;
                    it->next = curr;
                    curr->next = temp;
                }
            } else { // first node
                sorted = curr;
                curr->next = nullptr;
            }
            
            curr = next;
        }
        return sorted;
    }
};