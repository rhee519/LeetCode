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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first = head, *curr = head, *prev = nullptr;
        int i = n;
        while(first) {
            if(i <= 0) {
                prev = curr;
                curr = curr->next;
            }
            i--;
            first = first->next;
        }
        
        // remove curr
        if(prev) {
            prev->next = curr->next;
            curr->next = nullptr;
        } else { // prev == nullptr, curr == head
            head = head->next;
        }
        
        return head;
    }
};