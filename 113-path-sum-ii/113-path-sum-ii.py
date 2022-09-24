# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.paths = []
    
    def dfs(self, root: TreeNode, targetSum: int, currSum: int, path: List[int]):
        path = path+[root.val]
        currSum += root.val
        if not root.left and not root.right and currSum == targetSum:
            self.paths.append(path)
        
        if root.left:
            self.dfs(root.left, targetSum, currSum, path)
        if root.right:
            self.dfs(root.right, targetSum, currSum, path)
    
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        if root:
            self.dfs(root, targetSum, 0, [])
        return self.paths