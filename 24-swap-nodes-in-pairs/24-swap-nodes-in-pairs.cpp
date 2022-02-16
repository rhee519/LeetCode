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
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr = new ListNode(0, head); // dummy node
        if(head and head->next) head = head->next;
        while(curr) {
            // swap curr->next & curr->next->next
            ListNode* first = curr->next;
            if(!first) break;
            ListNode* second = first->next;
            if(!second) break;
            first->next = second->next;
            second->next = first;
            curr->next = second;
            curr = first;
        }
        return head;
    }
};