class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> List[List[int]]:
        self.ans = []
        
        def helper(root, s, targetSum, tmp):
            if(not root):
                return
            
            if(not root.left and not root.right and s + root.val == targetSum):
                tmp.append(root.val)
                self.ans.append(tmp)
                return
            
            helper(root.left, s + root.val, targetSum, tmp + [root.val])
            helper(root.right, s + root.val, targetSum, tmp + [root.val])
        
        helper(root, 0, targetSum, [])
        return self.ans
