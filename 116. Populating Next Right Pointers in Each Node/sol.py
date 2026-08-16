class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return None
        
        q = [root]
        
        while q:
            s = len(q)
            
            for i, val in enumerate(q):
                if i == s - 1:
                    val.next = None
                else:
                    val.next = q[i + 1]
            
            while s:
                cur = q.pop(0)
                
                if cur.left:
                    q.append(cur.left)
                
                if cur.right:
                    q.append(cur.right)
                
                s -= 1
        
        return root

#time O(n) space O(1)
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

# --- alternate solution ---

class Solution {
public:
    Node* connect(Node* root) {
        if(not root) return root;
        Node* head = root;
        
        while(root and root->left) {
            Node* cur = root;
            
            while(cur) {
                cur->left->next = cur->right;
                cur->right->next = cur->next ? cur->next->left : nullptr;
                cur = cur->next;
            }
            
            root = root->left;
        }
        
        return head;
    }
};

#time O(n) space O(n) with freeing => end space O(1)
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

# --- alternate solution ---

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return None
        
        node = root
        
        while node:
            cur = node
            
            while cur:
                if cur.left:
                    cur.left.next = cur.right
                
                if cur.right and cur.next:
                    cur.right.next = cur.next.left
                
                cur = cur.next
            
            node = node.left
        
        return root
