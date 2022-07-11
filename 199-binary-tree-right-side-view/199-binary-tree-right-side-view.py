# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bfs(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        
        q = deque([(0, root)])
        rlist = []
        
        while q:
            level, node = q.popleft()
            if len(rlist) <= level:
                rlist.append(node.val)
            else:
                rlist[level] = node.val
            if node.left:
                q.append((level+1, node.left))
            if node.right:
                q.append((level+1, node.right))
        
        return rlist
            
    
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        return self.bfs(root)