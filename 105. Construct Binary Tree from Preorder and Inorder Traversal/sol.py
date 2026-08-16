# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        n = len(inorder)
        mp = {inorder[i] : i for i in range(n)}
        self.i = 0
        
        def helper(l, r):
            if l > r:
                return None
            
            part = mp[preorder[self.i]]
            self.i += 1
            
            root = TreeNode(inorder[part])
            root.left = helper(l, part - 1)
            root.right = helper(part + 1, r)
            
            return root
        
        return helper(0, n - 1)
