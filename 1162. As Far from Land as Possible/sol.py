class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        n = len(grid)
        q = []
        vis = [[False] * n  for _ in range(n)]
        for i in range(n):
            for j in range(n):
                if(grid[i][j] == 1):
                    q.append((i, j))
                    vis[i][j] = True

        lvl = 0
        while(q):
            s = len(q)
            
            while(s):
                x, y = q[0][0], q[0][1]
                q.pop(0)
                
                for i in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                    
                    dx, dy = x + i[0], y + i[1]
                    
                    if(dx >= 0 and dx < n and dy >= 0 and dy < n and not vis[dx][dy]):
                        grid[dx][dy] = lvl
                        q.append((dx, dy))
                        vis[dx][dy] = True
                        
                s -= 1
            lvl += 1

        return lvl - 1 if lvl > 1 else -1
