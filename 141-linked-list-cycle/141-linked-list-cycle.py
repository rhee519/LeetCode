# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head or not head.next:
            return False
        c1, c2 = head, head.next
        while c1 and c2:
            if c1 == c2:
                return True
            if not c2.next:
                return False
            c1 = c1.next
            c2 = c2.next.next
        return False
        