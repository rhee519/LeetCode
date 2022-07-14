# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if len(preorder) == 0:
            return None
        
        root = TreeNode(val=preorder[0])
        if len(preorder) == 1:
            return root
        
        root_idx = inorder.index(root.val)
        left = self.buildTree(preorder[1:root_idx+1], inorder[:root_idx])
        right = self.buildTree(preorder[root_idx+1:], inorder[root_idx+1:])
        root.left, root.right = left, right
        
        return root