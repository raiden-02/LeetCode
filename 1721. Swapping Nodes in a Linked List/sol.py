# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: ListNode, k: int) -> ListNode:
        if(not head):
            return None
        
        temp = head
        n = 0
        s1, s2 = -1, -1
        while(temp):
            n += 1
            if(n == k):
                s1 = temp.val
            temp = temp.next

        temp = head
        c = 0
        while(temp):
            c += 1
            if(c == n - k + 1):
                s2 = temp.val
                break
            temp = temp.next
        
        temp = head
        c = 0
        f1, f2 = True, True
        while((f1 or f2) and temp):
            c += 1
            if(c == k):
                temp.val = s2
                f1 = False
            if(c == n - k + 1):
                temp.val = s1
                f2 = False
            temp = temp.next
        
        return head
