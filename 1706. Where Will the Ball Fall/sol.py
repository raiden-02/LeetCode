class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        dp = [[True] * n for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                if(j == 0 and grid[i][j] == -1):
                    dp[i][j] = False
                    
                if(j == n - 1 and grid[i][j] == 1):
                    dp[i][j] = False
                    
                if(grid[i][j] == 1 and j + 1 < n and grid[i][j + 1] == -1):
                    dp[i][j] = dp[i][j + 1] = False
        
        ans = [0 for _ in range(n)]
        for j in range(n):
            x, y = 0, j
            f = True
            #print(j)
            tmp = -1
            
            while(x < m):
                #print(x, y, grid[x][y])
                if(y < 0 or y > n or dp[x][y] == False):
                    f = False
                    break
                #tmp = y
                y += grid[x][y]
                x += 1
                tmp = y
                #print(x, y)
                
            ans[j] = tmp if f else -1
        
        return ans
