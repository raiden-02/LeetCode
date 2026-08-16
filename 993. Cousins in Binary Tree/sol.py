# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        depth = {}
        parent = {}
        
        q = [root]
        lvl = 0
        
        while(q != []):
            s = len(q)
            while(s):
                cur = q.pop(0)
                depth[cur.val] = lvl
                
                if(cur.left):
                    q.append(cur.left)
                    parent[cur.left.val] = cur.val
                if(cur.right):
                    q.append(cur.right)
                    parent[cur.right.val] = cur.val
                
                s -= 1
            lvl += 1
        
        return depth[x] == depth[y] and parent[x] != parent[y]
