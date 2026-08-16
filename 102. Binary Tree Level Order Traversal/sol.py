# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if(not root):
            return root
        
        q = []
        q.append(root)
        ans = [[root.val]]
        
        while(q != []):
            s = len(q)
            tmp = []
            
            while(s):
                cur = q.pop(0)
                if(cur.left):
                    q.append(cur.left)
                    tmp.append(cur.left.val)
                if(cur.right):
                    q.append(cur.right)
                    tmp.append(cur.right.val)
                s -= 1
            
            if(tmp != []):
                ans.append(tmp)
        
        return ans
