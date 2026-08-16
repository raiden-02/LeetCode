int m = maze.size(), n = maze[0].size(), steps = 0;
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        queue<vector<int>> q;
        q.push(entrance);
        vis[entrance[0]][entrance[1]] = true;
        
        while(not q.empty()) {
            int s = q.size();
            
            while(s--) {
                auto cur = q.front(); q.pop();
                int x = cur[0], y = cur[1];
                
                if(x != entrance[0] and y != entrance[1] and (x == m - 1 or y == n - 1 or x == 0 or y == 0) and maze[x][y] == '.')
                    return steps;
                
                for(auto &dir : dirs) {
                    int dx = x + dir.first, dy = y + dir.second;
                    
                    if(dx >= 0 and dx < m and dy >= 0 and dy < n and not vis[dx][dy] and maze[dx][dy] == '.') {
                        if((dx == m - 1 or dy == n - 1 or dy == 0 or dx == 0) and maze[dx][dy] == '.')
                            return steps + 1;
                        
                        q.push({dx, dy}), vis[dx][dy] = true;
                    }
                }
            }
            
            steps++;
        }
        
        return -1;
    }
