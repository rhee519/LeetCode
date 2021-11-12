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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr = head, * prev = nullptr;
        while(curr) {
            if(curr->val == val) {
                if(curr == head) {
                    curr = head = head->next;
                } else {
                    curr = curr->next;
                    if(prev) prev->next = curr;
                }
            } else {
                prev = curr; curr = curr->next;
            }
        }
        return head;
    }
};