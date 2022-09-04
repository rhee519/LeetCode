# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, vertical: Dict, root: TreeNode, level: int, idx: int):
        if idx not in vertical:
            vertical[idx] = {}
        if level not in vertical[idx]:
            vertical[idx][level] = []
        vertical[idx][level].append(root.val)
        
        if root.left:
            self.dfs(vertical, root.left, level+1, idx-1)
        if root.right:
            self.dfs(vertical, root.right, level+1, idx+1)
        
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        vertical = {}
        self.dfs(vertical, root, 0, 0)
        
        ans = []
        column_idx = list(vertical.keys())
        column_idx.sort()
        
        for c_idx in column_idx:
            level_idx = list(vertical[c_idx].keys())
            level_idx.sort()
            column = []
            for l_idx in level_idx:
                vertical[c_idx][l_idx].sort()
                column += vertical[c_idx][l_idx]
            ans.append(column)
            
        return ans