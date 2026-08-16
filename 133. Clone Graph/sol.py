"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        mp = {}
        
        def helper(node):
            if(not node):
                return None
        
            if(node in mp):
                return mp[node]

            mp[node] = Node(node.val)

            for neigh in node.neighbors:
                mp[node].neighbors.append(helper(neigh))
            
            return mp[node]
        
        return helper(node)
