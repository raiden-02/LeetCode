class Solution {
    vector<vector<bool>> vis;
    int m, n, size, ans;
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    void dfs(int i, int j, int const& ei, int const& ej, vector<vector<int>> &grid, int trav) {
        if(trav >= size) {
            if(i == ei and j == ej) ans++;
            return;
        }
        
        for(auto &dir : dirs) {
            int dx = i + dir.first, dy = j + dir.second;
            
            if(dx >= 0 and dx < m and dy >= 0 and dy < n and grid[dx][dy] != -1 and not vis[dx][dy])
                vis[dx][dy] = true, dfs(dx, dy, ei, ej, grid, trav + 1), vis[dx][dy] = false;
        }
    } 
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size(), size = 0, ans = 0;
        vis.resize(m, vector<bool>(n, false));
        int si, sj, ei, ej;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1)
                    si = i, sj = j;
                
                else if(grid[i][j] == 2)
                    ei = i, ej = j;
                
                if(grid[i][j] != -1) size++;
            }
        }
        
        vis[si][sj] = true;
        dfs(si, sj, ei, ej, grid, 1);
        
        return ans;
    }
};

// --- alternate solution ---

class Solution {
    int ans = 0, nEmpty = 0, sx, sy, ex, ey, m, n;
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    void dfs(vector<vector<int>> &grid, int x, int y, int len) {
        if(len >= nEmpty) {
            if(x == ex and y == ey) ans++;
            return;
        }

        for(auto &dir : dirs) {
            int dx = x + dir.first, dy = y + dir.second;

            if(dx >= 0 and dx < m and dy >= 0 and dy < n and grid[dx][dy] != -1) {
                int val = grid[dx][dy];
                grid[dx][dy] = -1, dfs(grid, dx, dy, len + 1), grid[dx][dy] = val;
            }
        }
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1)
                    sx = i, sy = j;

                else if(grid[i][j] == 2)
                    ex = i, ey = j;

                if(grid[i][j] != -1) nEmpty++;
            }
        }

        grid[sx][sy] = -1, dfs(grid, sx, sy, 1);

        return ans;
    }
};
