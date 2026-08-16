class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        dp = [-1] * len(arr)
        
        def helper(arr, i, k, dp):
            if(i >= len(arr)):
                return 0
            
            if(dp[i] != -1):
                return dp[i]
            
            m = -1
            ans = 0
            for j in range(i, i + k):
                
                if(j >= len(arr)):
                    break
                
                m = max(arr[j], m)
                cutNow = m * (j - i + 1)
                cutLater = helper(arr, j + 1, k, dp)
                ans = max(cutNow + cutLater, ans)
            
            dp[i] = ans
            return ans
                
            
        return helper(arr, 0, k, dp)
