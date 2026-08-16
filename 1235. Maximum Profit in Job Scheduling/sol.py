class Solution:
    """
    in every turn we either select the time range (if its valid) or we skip that time range
    """
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        n = len(profit)
        times = [(startTime[i], endTime[i], profit[i]) for i in range(n)]
        times.sort(key = lambda x : x[0])
        
        @lru_cache(None)
        def helper(ind):
            if(ind >= n):
                return 0
            
            nextInd = find(ind)
            dontSkip = times[ind][2] + (0 if nextInd == -1 else helper(nextInd))
            skip = helper(ind + 1)
            
            return max(skip, dontSkip)
        
        def find(ind):
            for i in range(ind + 1, n):
                if(times[i][0] >= times[ind][1]):
                    return i
            return -1
        
        return helper(0)
