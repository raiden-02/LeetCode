class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        n = len(inorder)
        mp = {inorder[i] : i for i in range(n)}
        self.i = n - 1
        
        def helper(l, r):
            if self.i < 0 or l > r:
                return None
            
            part = mp[postorder[self.i]]
            self.i -= 1
            
            root = TreeNode(inorder[part])
            root.right = helper(part + 1, r)
            root.left = helper(l, part - 1)
            
            return root
        
        return helper(0, n - 1)
