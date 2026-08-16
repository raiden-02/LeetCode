# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, root: Optional[TreeNode], val: int, depth: int):
        if(root == None): 
            return
        
        if(depth == 2):
            left = root.left
            right = root.right
            
            nleft = TreeNode(val, left, None)
            root.left = nleft

            nright = TreeNode(val, None, right)
            root.right = nright

        self.helper(root.left, val, depth - 1)
        self.helper(root.right, val, depth - 1) 

    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        if(depth == 1):
            new_root = TreeNode(val, root, None)
            return new_root
            
        self.helper(root, val, depth)
        return root
