# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        n = 0
        tmp = head

        while tmp is not None:
            tmp = tmp.next
            n += 1
        
        extra = n % k
        partlen = int(n / k)
        
        print(extra, partlen)
        cnt = 0
        tmp, phead, tail = head, head, None
        ans = []

        while tmp is not None:
            if cnt == partlen:
                if extra > 0:
                    tail = tmp
                    if tmp is not None:
                        tmp = tmp.next
                    extra -= 1
                
                tail.next = None
                ans.append(phead)
                phead = tmp
                tail = None
                cnt = 0

            else:    
                tail = tmp
                tmp = tmp.next
                cnt += 1
        
        ans.append(phead)
        phead = tmp
        tail = None
        cnt = 0

        while len(ans) < k:
            ans.append(None)

            
        
        return ans
