#python dp memoization using lru cache

class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        freq = [(x.count('0'), x.count('1')) for x in strs]
        #dp = [[[-1 for _ in range(n + 1)] for _ in range(m + 1)] for _ in range(len(strs))]
        
        @lru_cache(None)
        def helper(ind, z, o):
            if(ind >= len(strs)):
                return 0
            
            """if(dp[ind][z][o] != -1):
                return dp[ind][z][o]"""
            
            ans = helper(ind + 1, z, o)
            
            if(z + freq[ind][0] <= m and o + freq[ind][1] <= n):
                ans = max(ans, helper(ind + 1, z + freq[ind][0], o + freq[ind][1]) + 1)
                
            #dp[ind][z][o] = ans
            return ans
        
        return helper(0, 0, 0)
