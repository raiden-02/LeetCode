# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ans = ""

    def dfs(self, root: Optional[TreeNode], cur: str):
        if(root.left == None and root.right == None):
            if(self.ans == ""):
                self.ans = cur
            else:
                self.ans = min(self.ans, cur)
            return
        
        if(root.left != None):
            self.dfs(root.left, str(chr(root.left.val + 97)) + cur)
        
        if(root.right != None):
            self.dfs(root.right, str(chr(root.right.val + 97)) + cur)

    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        if(root == None): 
            return ""
        
        self.dfs(root, str(chr(root.val + 97)))
        return self.ans
