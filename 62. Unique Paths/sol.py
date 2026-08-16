class Solution:
    """
    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
    """
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0] * n for _ in range(m)]
        dp[0][0] = 1
        
        for i in range(m):
            for j in range(n):
                if(i == 0 and j == 0): continue
                
                a = dp[i - 1][j] if i - 1 >= 0 else 0
                b = dp[i][j - 1] if j - 1 >= 0 else 0
                
                dp[i][j] = a + b
        
        return dp[m - 1][n - 1]
