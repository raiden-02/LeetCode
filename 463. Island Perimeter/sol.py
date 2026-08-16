class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        ans = 0

        for i in range(m):
            for j in range(n):
                if(grid[i][j] == 1):
                    if(i - 1 >= 0 and grid[i - 1][j] == 0):
                        ans += 1
                    if(i + 1 < m and grid[i + 1][j] == 0):
                        ans += 1
                    if(j - 1 >= 0 and grid[i][j - 1] == 0):
                        ans += 1
                    if(j + 1 < n and grid[i][j + 1] == 0):
                        ans += 1
                    if(i - 1 < 0):
                        ans += 1
                    if(i + 1 >= m):
                        ans += 1
                    if(j - 1 < 0):
                        ans += 1
                    if(j + 1 >= n):
                        ans += 1
        
        return ans
