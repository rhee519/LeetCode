"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return
        
        q = deque([(root, 0)])
        curr_depth = 0
        st = []
        while q:
            node, depth = q.popleft()
            # print(f"node: {node.val}, depth: {depth}")
            if depth > curr_depth:
                # print(st)
                while st:
                    tail = st.pop()
                    if st:
                        st[-1].next = tail
                curr_depth = depth
            st.append(node)
            if node.left:
                q.append((node.left, depth+1))
            if node.right:
                q.append((node.right, depth+1))
        
        while st:
            tail = st.pop()
            if st:
                st[-1].next = tail
        
        return root