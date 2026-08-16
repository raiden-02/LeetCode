class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        #dp[i][j] will hold no of valid sub matrices in grid of size i + 1 and j + 1
        m, n = len(matrix), len(matrix[0])
        dp = matrix
        ans = 0
        
        for i in range(m):
            for j in range(n):
                if(i == 0 or j == 0 or dp[i][j] == 0):
                    ans += dp[i][j]
                    continue
                    
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
                ans += dp[i][j]
                    
        
        return ans
