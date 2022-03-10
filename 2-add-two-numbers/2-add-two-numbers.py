# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        c1, c2, prev = l1, l2, None
        carry = 0
        while c1 and c2:
            prev = c1
            s = c1.val + c2.val + carry
            carry = s//10
            s %= 10
            c1.val = s
            c1, c2 = c1.next, c2.next
        
        if c1:
            prev.next = c1
        elif c2:
            prev.next = c2
            c1 = prev.next
        
        while c1:
            prev = c1
            s = c1.val + carry
            carry = s//10
            s %= 10
            c1.val = s
            c1 = c1.next
        
        if carry:
            prev.next = ListNode(1)
        
        return l1