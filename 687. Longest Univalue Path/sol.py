# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def longestUnivaluePath(self, root: TreeNode) -> int:
        self.ans = 0
        
        def helper(root):
            if(not root):
                return 0
            
            left = helper(root.left)
            right = helper(root.right)
            
            leftadd = rightadd = 0
            if(root.left and root.left.val == root.val):
                leftadd = left + 1
            
            if(root.right and root.right.val == root.val):
                rightadd = right + 1
            
            self.ans = max(self.ans, leftadd + rightadd) #leftadd or rightadd would be zero if the conditions arent satisfied which implies we are only gonna add the valid path
            
            return max(leftadd, rightadd)
        
        helper(root)
        return self.ans
