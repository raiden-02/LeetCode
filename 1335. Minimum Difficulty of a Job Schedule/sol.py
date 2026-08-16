class Solution:
    """
    in each step we can select jobs from (i, n - rmaining days)
    ans = max(todays jobs) + next recur(i + 1)
    """
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        
        if(n < d):
            return -1
        
        if(n == d):
            return sum(jobDifficulty)
        
        @lru_cache(None)
        def helper(ind, rem):
            if(rem == 0):
                return max(jobDifficulty[ind:])
            
            ans = float('inf')
            cur = -1
            
            for i in range(ind, n - rem):
                if(i >= n):
                    break
                cur = max(cur, jobDifficulty[i])
                ans = min(ans, helper(i + 1, rem - 1) + cur)
            
            return ans
        
        return helper(0, d - 1)
