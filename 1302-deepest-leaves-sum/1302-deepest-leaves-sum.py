# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.deepest_sum = 0
        self.max_depth = 0
        
    def deepestLeavesSum(self, root: Optional[TreeNode], depth = 0) -> int:
        if root is None:
            return self.deepest_sum
        if depth == self.max_depth:
            self.deepest_sum += root.val
        elif depth > self.max_depth:
            self.max_depth = depth
            self.deepest_sum = root.val
        
        self.deepestLeavesSum(root.left, depth+1)
        self.deepestLeavesSum(root.right, depth+1)
        return self.deepest_sum
        