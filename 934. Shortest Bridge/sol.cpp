class Solution {
    vector<vector<bool>> vis;
    vector<pair<int, int>> k1, dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;
    
    void dfs(int i, int j, vector<vector<int>> const& grid) {
        if(vis[i][j]) return;
        
        k1.push_back({i, j});
        vis[i][j] = true;
        
        for(auto &dir : dirs) {
            int dx = i + dir.first, dy = j + dir.second;
            
            if(dx >= 0 and dx < m and dy >= 0 and dy < n and not vis[dx][dy] and grid[dx][dy])
                dfs(dx, dy, grid);
        }
    }
    
    int bfs(vector<vector<int>> const& grid) {
        queue<pair<int, int>> q;
        int lvl = 0;
        
        for(auto &x : k1)
           q.push(x);
        
        while(not q.empty()) {
            int s = q.size();
            
            while(s--) {
                auto cur = q.front(); q.pop();
                int x = cur.first, y = cur.second;
                
                for(auto &dir : dirs) {
                    int dx = x + dir.first, dy = y + dir.second;
                    
                    if(dx >= 0 and dx < m and dy >= 0 and dy < n and not vis[dx][dy]) {
                        if(grid[dx][dy]) return lvl;
                        q.push({dx, dy}), vis[dx][dy] = true;
                    }
                }
            }
            
            lvl++;
        }
        
        return lvl;
    }
    
    pair<int, int> helper(vector<vector<int>> const& grid) {
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(grid[i][j]) return {i, j};
        return {-1, -1};
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        
        auto start = helper(grid);
        
        vis.resize(m, vector<bool>(n, false));
        dfs(start.first, start.second, grid);
        
        return bfs(grid);
    }
};
