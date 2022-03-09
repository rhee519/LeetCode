# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        h = ListNode()
        c, curr = h, head
        while curr:
            if curr.next and curr.val == curr.next.val:
                # skip duplicated nodes
                val = curr.val
                while curr and curr.val == val:
                    curr = curr.next
            else:
                # insert to h
                c.next = curr
                c = c.next
                curr = curr.next
                c.next = None
        
        return h.next
        