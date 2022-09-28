# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        prev, curr, post = None, head, head
        for i in range(n):
            post = post.next
        while post:
            prev, curr, post = curr, curr.next, post.next
        if prev:
            prev.next = curr.next
        else: # curr == head
            head = head.next
        
        return head