class Solution {
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    
    void dfs(int i, int j, vector<vector<int>> &grid) {
        grid[i][j] = 0;
        
        for(auto &dir : dirs) {
            int x = i + dir.first, y = j + dir.second;
            
            if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y])
                dfs(x, y, grid);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        
        array<int, 2> xbound = {0, m - 1}, ybound = {0, n - 1};
        
        for(int &x : xbound) {
            for(int j = 0; j < n; j++)
                if(grid[x][j])
                    dfs(x, j, grid);
        }
        
        for(int &y : ybound) {
            for(int i = 0; i < m; i++)
                if(grid[i][y])
                    dfs(i, y, grid);
        }
        
        for(auto &x : grid) {
            for(int &y : x)
                ans += y;
        }
        
        return ans;
    }
};
