# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def hasPathSum(self, root: TreeNode, targetSum: int) -> bool:
        if(not root):
            return False
        
        def dfs(root, s, targetSum):
            if(not root): return False
            
            if(not root.left and not root.right and targetSum == s + root.val):
                return True
            
            return dfs(root.left, s + root.val, targetSum) or dfs(root.right, s + root.val, targetSum)
        
        return dfs(root, 0, targetSum)
