class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        queue<pair<int, int>> starts;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        
        auto isValid = [&](int x, int y) {
            return x >= 0 and x < m and y >= 0 and y < n;
        };
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) if(isWater[i][j]) starts.push({i, j}), vis[i][j] = true, isWater[i][j] = 0;
        }
        
        while(not starts.empty()) {
            auto cur = starts.front(); starts.pop();
            int x = cur.first, y = cur.second;
            
            for(auto &dir : dirs) {
                int dx = x + dir.first, dy = y + dir.second;
                
                if(isValid(dx, dy) and not vis[dx][dy])
                    starts.push({dx, dy}), isWater[dx][dy] = isWater[x][y] + 1, vis[dx][dy] = true;
            }
        }
        
        return isWater;
    }
};
