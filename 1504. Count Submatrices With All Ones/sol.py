class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        dp = mat
        
        for i in range(m):
            for j in range(n - 2, -1, -1):
                if(mat[i][j]):
                    dp[i][j] += dp[i][j + 1]
        
        ans = 0
        
        for i in range(m):
            for j in range(n):
                if(mat[i][j] == 0): continue
                
                minl = float('inf')
                
                for k in range(i, m):
                    minl = min(minl, dp[k][j])
                    ans += minl
        
        return ans
