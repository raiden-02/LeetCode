# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        ans: int = 0

        def dfs(root: TreeNode) -> (int, int):
            nonlocal ans

            if (not root): return 0

            ls, rs, lcnt, rcnt = 0, 0, 0, 0

            if (root.left):
                ls, lcnt = dfs(root.left)
            
            if (root.right):
                rs, rcnt = dfs(root.right)
            
            s = ls + rs + root.val
            cnt = lcnt + rcnt + 1

            if (s // cnt == root.val):
                ans += 1

            return (s, cnt)
        
        dfs(root)

        return ans
