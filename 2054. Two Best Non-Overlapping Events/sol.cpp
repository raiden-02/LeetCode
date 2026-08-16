class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        events.sort()
        pq = []
        ans, max_val = 0, 0

        for event in events:
            while pq and pq[0][0] < event[0]:
                max_val = max(max_val, pq[0][1])
                heapq.heappop(pq)
            
            ans = max(ans, max_val + event[2])
            heapq.heappush(pq, (event[1], event[2]))
        
        return ans
