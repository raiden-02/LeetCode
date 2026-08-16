class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        self.ans, self.area = 0, 0
        
        def dfs(i, j):
            self.area += 1
            self.ans = max(self.ans, self.area)
            grid[i][j] = 0
            
            for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                dx += i
                dy += j
                if dx >= 0 and dx < m and dy >= 0 and dy < n and grid[dx][dy]:
                    dfs(dx, dy)
                    
        
        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    self.area = 0
                    dfs(i, j)
        
        return self.ans
