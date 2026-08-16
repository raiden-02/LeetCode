class Solution {
    int m, n;
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int dfs(vector<vector<int>> &grid, int x, int y) {    
        int ans = 1;
        grid[x][y] = 0;
        
        for(auto &dir : dirs) {
            int dx = x + dir.first, dy = y + dir.second;
            
            if(dx >= 0 and dx < m and dy >= 0 and dy < n and grid[dx][dy])
                ans += dfs(grid, dx, dy);
        }
        
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j])
                    ans = max(ans, dfs(grid, i, j));
            }
        }
        
        return ans;
    }
};

// --- alternate solution ---

class Solution {
    int m, n;
    vector<vector<bool>> vis;
    
    int dfs(int i, int j, vector<vector<int>> &grid) {
        if(i < 0 or i >= m or j < 0 or j >= n or vis[i][j] or grid[i][j] == 0) return 0;
        
        vis[i][j] = true;
        
        return 1 + dfs(i + 1, j, grid) + dfs(i, j + 1, grid) + dfs(i - 1, j, grid) + dfs(i, j - 1, grid);
        
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vis.resize(m, vector<bool>(n, false));
        int ans = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                if(grid[i][j] and not vis[i][j])
                    ans = max(ans, dfs(i, j, grid));
        }
        
        return ans;
    }
};
