# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        def reverse(self, head: Optional[ListNode]):
            if head is None:
                return None
            
            cur = head
            prev = None

            while cur:
                nex = cur.next
                cur.next = prev
                prev = cur
                cur = nex
            
            return prev
        
        if head is None:
            return 0
        
        ans = 0

        slow, fast = head, head.next
        
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        p1 = reverse(self, slow.next)
        p2 = head

        while p1 and p2:
            ans = max(ans, p1.val + p2.val)
            p1 = p1.next
            p2 = p2.next
        
        return ans


        


                



        
        
