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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* curr = head, *prev = nullptr, *even_head = nullptr, *even_curr = nullptr;
        int idx = 0;
        while(curr) {
            idx++;
            if(idx%2 == 0) {
                if(even_head) {
                    even_curr->next = curr;
                    even_curr = even_curr->next;
                } else {
                    even_head = even_curr = curr;
                }
                if(prev) prev->next = curr->next;
                curr = curr->next;
                even_curr->next = nullptr;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        if(prev) prev->next = even_head;
        return head;
    }
};