# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(val=-1, next=head)
        nodes = [dummy]
        curr = head
        while curr:
            nodes.append(curr)
            curr = curr.next
        
        # swap values of nodes[k] && nodes[-k]
        nodes[k].val, nodes[-k].val = nodes[-k].val, nodes[k].val
        
        return head