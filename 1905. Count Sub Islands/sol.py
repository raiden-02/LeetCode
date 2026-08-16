from collections import deque
from typing import List, Set, Tuple

class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        m, n = len(grid1), len(grid1[0])
        dirs = ((0, 1), (1, 0), (-1, 0), (0, -1))

        def bfs(grid: List[List[int]], si: int, sj: int) -> Set[Tuple[int, int]]:
            ret = set()
            q = deque([(si, sj)])
            grid[si][sj] = 0

            while q:
                i, j = q.popleft()
                ret.add((i, j))

                for dr in dirs:
                    ni, nj = i + dr[0], j + dr[1]

                    if 0 <= ni < m and 0 <= nj < n and grid[ni][nj] == 1:
                        q.append((ni, nj))
                        grid[ni][nj] = 0

            return ret
        
        ans = 0

        for i in range(m):
            for j in range(n):
                if grid1[i][j] == 1:
                    original_set = bfs(grid1, i, j)

                    for oi, oj in original_set:
                        if grid2[oi][oj] == 1:
                            other_set = bfs(grid2, oi, oj)

                            if other_set.issubset(original_set):
                                ans += 1
        
        return ans
