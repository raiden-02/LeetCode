class Solution {
    int m, n;
    vector<vector<bool>> vis;
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    
    void dfs(int x, int y, vector<vector<int>> &grid) {
        vis[x][y] = true;
        
        for(auto &dir : dirs) {
            int dx = x + dir.first, dy = y + dir.second;
            
            if(dx >= 0 and dx < m and dy >= 0 and dy < n and not vis[dx][dy] and not grid[dx][dy])
                dfs(dx, dy, grid);
        }
    }
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vis.resize(m, vector<bool>(n, false));
        int ans = 0;
        
        for(int i = 0; i < m; i++) { 
            if(not vis[i][0] and not grid[i][0]) dfs(i, 0, grid); 
            if(not vis[i][n - 1] and not grid[i][n - 1]) dfs(i, n - 1, grid);
        }
        
        for(int j = 0; j < n; j++) { 
            if(not vis[0][j] and not grid[0][j]) dfs(0, j, grid);
            if(not vis[m - 1][j] and not grid[m - 1][j]) dfs(m - 1, j, grid);
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(not vis[i][j] and not grid[i][j])
                    dfs(i, j, grid), ans++;
            }
        }
        
        return ans;
    }
};

// --- alternate solution ---

class Solution {
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;
    
    void dfs(vector<vector<int>> &grid, int x, int y) {
        for(auto &dir : dirs) {
            int dx = dir.first + x;
            int dy = dir.second + y;
            
            if(dx >= 0 and dx < m and dy >= 0 and dy < n and grid[dx][dy] == 0)
                grid[dx][dy] = 1, dfs(grid, dx, dy);
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        m = grid.size(), n = grid[0].size();
        
        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 0)
                grid[i][0] = 1, dfs(grid, i, 0);
            
            if(grid[i][n - 1] == 0)
                grid[i][n - 1] = 1, dfs(grid, i, n - 1);
        }
        
        for(int j = 0; j < n; j++) {
            if(grid[0][j] == 0)
                grid[0][j] = 1, dfs(grid, 0, j);
            
            if(grid[m - 1][j] == 0)
                grid[m - 1][j] = 1, dfs(grid, m - 1, j);
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0)
                    grid[i][j] = 1, dfs(grid, i, j), ans++;
            }
        }
        
        return ans;
    }
};
