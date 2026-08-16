# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if(head is None):
            return None
        
        odd, eve = head, head.next
        he = eve
        
        while(eve and eve.next):
            odd.next = odd.next.next
            eve.next = eve.next.next
            odd = odd.next
            eve = eve.next
        
        odd.next = he
        return head
