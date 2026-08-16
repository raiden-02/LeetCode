class Solution:
    def check(self, i, j, m, n):
        return i >= 0 and i < m and j >= 0 and j < n
    
    def dfs(self, land, i, j, m, n, tmp):
        if(i > tmp[0] or j > tmp[1]):
            tmp[0], tmp[1] = i, j
        
        land[i][j] = 0

        if(self.check(i + 1, j, m, n) and land[i + 1][j] == 1):
            self.dfs(land, i + 1, j, m, n, tmp)
        
        if(self.check(i, j + 1, m, n) and land[i][j + 1] == 1):
            self.dfs(land, i, j + 1, m, n, tmp)

    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        m, n = len(land), len(land[0])
        ans = []

        for i in range(m):
            for j in range(n):
                if(land[i][j] == 1):
                    tmp = [i, j]
                    self.dfs(land, i, j, m, n, tmp)
                    ans.append([i, j, tmp[0], tmp[1]])
        
        return ans
