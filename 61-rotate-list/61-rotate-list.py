# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head:
            return None
        
        last = head
        size = 1
        
        while last.next:
            last = last.next
            size += 1
        
        last.next = head
        k %= size
        
        prev, curr = None, head
        for _ in range(size-k):
            prev = curr
            curr = curr.next
        
        prev.next = None
        return curr