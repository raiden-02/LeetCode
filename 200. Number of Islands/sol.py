class Solution:
    def dfs(self, grid, m, n, i, j):
        grid[i][j] = "0"

        if(i + 1 < m and grid[i + 1][j] == "1"):
            self.dfs(grid, m, n, i + 1, j)
        if(i - 1 >= 0 and grid[i - 1][j] == "1"):
            self.dfs(grid, m, n, i - 1, j)
        if(j + 1 < n and grid[i][j + 1] == "1"):
            self.dfs(grid, m, n, i, j + 1)
        if(j - 1 >= 0 and grid[i][j - 1] == "1"):
            self.dfs(grid, m, n, i, j - 1)


    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        ans = 0

        for i in range(m):
            for j in range(n):
                if(grid[i][j] == "1"):
                    ans += 1
                    self.dfs(grid, m, n, i, j)
        
        return ans
