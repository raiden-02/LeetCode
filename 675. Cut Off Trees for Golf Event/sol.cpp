class Solution {
    //neighbor visit is faster than current visit, reduces redundant enqueues
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int m, n;
    
    int bfs(int sx, int sy, int ex, int ey, vector<vector<int>> &grid) {
        if (sx == ex && sy == ey)
            return 0;
        
        vector<vector<bool>> vis(m, vector<bool>(n));
        queue<pair<int, int>> q;
        q.push({sx, sy});
        int lvl = 0;
        vis[sx][sy] = true;
        
        while(not q.empty()) {
            int s = q.size();
            
            while(s--) {
                auto cur = q.front(); q.pop();
                int x = cur.first, y = cur.second;
                
                if(x == ex and y == ey)
                    return lvl;
                
                for(auto &dir : dirs) {
                    int dx = x + dir.first, dy = y + dir.second;

                    if(dx >= 0 and dx < m and dy >= 0 and dy < n and not vis[dx][dy] and grid[dx][dy] > 1) {
                        if(dx == ex and dy == ey)
                            return lvl + 1;
                        q.push({dx, dy});
                        vis[dx][dy] = true;
                    }
                }
            }
            
            lvl++;
        }
        
        return -1;
    }
public:
    int cutOffTree(vector<vector<int>>& forest) {
        m = forest.size(), n = forest[0].size();
        
        if(not forest[0][0])
            return -1;
        
        vector<vector<int>> vec;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(forest[i][j] > 1)
                    vec.push_back({forest[i][j], i, j});
            }
        }
        
        sort(vec.begin(), vec.end());
        
        int cx = 0, cy = 0, ans = 0;
        
        for(int i = 0; i < vec.size(); i++) {
            auto &cur = vec[i];
            
            int t = bfs(cx, cy, cur[1], cur[2], forest);
            if(t == -1)
                return -1;
            
            ans += t;
            cx = cur[1];
            cy = cur[2];
        }
        
        return ans; 
    }
};
