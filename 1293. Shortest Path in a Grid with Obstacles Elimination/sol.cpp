class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        const int m = grid.size(), n = grid[0].size();
        if(m == 1 and n == 1) return 0;
        
        if(k > m - 1 + n - 1)
            return m - 1 + n - 1;
                
        queue<vector<int>> q;
        bool vis[m + 1][n + 1][m * n + 1];
        memset(vis, false, sizeof(vis));
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        
        
        q.push({0, 0, k});
        vis[0][0][k] = true;
        int dist = 0;
        
        while(not q.empty()) {
            int s = q.size();
            
            while(s--) {
                auto cur = q.front(); q.pop();
                int x = cur[0], y = cur[1], curk = cur[2];
                if(x == m - 1 and y == n - 1)
                    return dist;
                
                for(auto &dir : dirs) {
                    int dx = x + dir.first, dy = y + dir.second;
                    
                    if(dx >= 0 and dx < m and dy >= 0 and dy < n) {
                        if(dx == m - 1 and dy == n - 1) return dist + 1;
                        
                        if(grid[dx][dy] == 1 and curk > 0 and not vis[dx][dy][curk - 1])
                            q.push({dx, dy, curk - 1}), vis[dx][dy][curk - 1] = true;
                        
                        else if(grid[dx][dy] == 0 and not vis[dx][dy][curk])
                            q.push({dx, dy, curk}),  vis[dx][dy][curk] = true;
                    }
                }
            }
            
            dist++;
        }
        
        return -1;
    }
};
