//djikstra

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        while(not pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int d = cur[0], x = cur[1], y = cur[2];
            
            for(auto &dir : dirs) {
                int dx = x + dir.first, dy = y + dir.second, nd = INT_MIN;
                
                if(dx >= 0 and dx < n and dy >= 0 and dy < n)
                    nd = grid[dx][dy];
                
                if(nd != INT_MIN) {
                    nd = max(nd, d);
                    
                    if(nd < dist[dx][dy])
                        dist[dx][dy] = nd, pq.push({nd, dx, dy});
                }
            }
        }
        
        return dist[n - 1][n - 1];
    }
};
