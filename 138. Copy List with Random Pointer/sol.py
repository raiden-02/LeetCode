#hashmap method
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if(not head):
            return None
        
        mp = {}
        cur = head
        
        while(cur):
            mp[cur] = Node(cur.val)
            cur = cur.next
        
        for key, value in mp.items():
            value.next = mp[key.next] if key.next else None
            value.random = mp[key.random] if key.random else None
        
        return mp[head]

#o(1) method
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

# --- alternate solution ---

class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if(not head):
            return None
        
        cur = head
        while(cur):
            tmp = cur.next
            cur.next = Node(cur.val)
            cur.next.next = tmp
            cur = tmp
        
        cur = head
        while(cur and cur.next):
            cur.next.random = cur.random.next if cur.random else None
            cur = cur.next.next
        
        cur = head.next
        ans = cur
        while(cur.next):
            cur.next = cur.next.next
            cur = cur.next
        
        return ans
