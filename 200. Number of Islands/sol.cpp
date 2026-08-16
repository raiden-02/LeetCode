class Solution {
    int m, n;
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    
    void dfs(int x, int y, vector<vector<char>> &grid) {
        grid[x][y] = '0';
        
        for(auto &dir : dirs) {
            int dx = x + dir.first, dy = y + dir.second;
            
            if(dx >= 0 and dx < m and dy >= 0 and dy < n and grid[dx][dy] == '1')
                dfs(dx, dy, grid);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
