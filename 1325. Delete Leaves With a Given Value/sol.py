# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isLeaf(self, root: Optional[TreeNode]) -> bool:
        return root != None and root.left == None and root.right == None
    
    def helper(self, root: Optional[TreeNode], target: int):
        if(root == None):
            return
        
        self.helper(root.left, target)
        self.helper(root.right, target)
        
        if(self.isLeaf(root.left) and  root.left.val == target):
            root.left = None
        
        if(self.isLeaf(root.right) and  root.right.val == target):
            root.right = None

    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
        self.helper(root, target)

        if(self.isLeaf(root) and  root.val == target):
            root = None

        return root
