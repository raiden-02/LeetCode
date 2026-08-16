class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        self.ans = float('-inf')
        
        def helper(root):
            if(not root):
                return 0
            
            left = max(0, helper(root.left))
            right = max(0, helper(root.right))
            
            self.ans = max(self.ans, left + right + root.val)
            return max(left, right) + root.val
        
        helper(root)
        return self.ans
