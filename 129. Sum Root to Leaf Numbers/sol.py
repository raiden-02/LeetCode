# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ans = 0

    def helper(self, root: Optional[TreeNode], val: int):
        if(root == None): 
            return
        
        if(root.left == None and root.right == None):
            self.ans += root.val + val * 10
            return
        
        self.helper(root.left, val * 10 + root.val)
        self.helper(root.right, val * 10 + root.val)

    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        self.helper(root, 0)
        return self.ans
