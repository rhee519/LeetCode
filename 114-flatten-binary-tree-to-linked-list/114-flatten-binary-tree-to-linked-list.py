# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def get_rightmost(self, root: TreeNode) -> TreeNode:
        if root.right:
            return self.get_rightmost(root.right)
        elif root.left:
            return self.get_rightmost(root.left)
        return root
    
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if root is None:
            return
        
        if root.left:
            rightmost = self.get_rightmost(root.left)
            rightmost.right = root.right
            root.right = root.left
            root.left = None
        
        self.flatten(root.right)
        