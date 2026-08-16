class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        auto bound = [&](int &x, int &y) {
            return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
        };
        
        queue<pair<int, int>> q;
        int count = 0;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    count += 1;
            }
        }
        
        if(count == 0)
            return 0;
        
        int ans = -1;
        while(!q.empty()) {
            int s = q.size();
            
            while(s--) {
                auto cur = q.front(); q.pop();
                int x = cur.first, y = cur.second;
                
                for(auto &dir : dirs) {
                    int dx = x + dir.first, dy = y + dir.second;
                    
                    if(bound(dx, dy)  && grid[dx][dy] == 1) {
                        q.push({dx, dy});
                        count -= 1;
                        grid[dx][dy] = 2;
                    }
                }
            }
            ans += 1;
        }
        
        return count == 0 ? ans : -1;
    }
};
