# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def countUnivalSubtrees(self, root: TreeNode) -> int:
        if(not root): return 0
        
        mp = {}
        self.ans = 0
        
        def helper(root):
            if(not root):
                return True
            
            a = helper(root.left)
            b = helper(root.right)
            
            if(a and b and (root.left == None or root.left.val == root.val) and (root.right == None or root.right.val == root.val)):
                self.ans += 1
                return True
            
            return False
        
        helper(root)
        return self.ans
