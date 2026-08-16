class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int m = heights.size(), n = heights[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = 0;
        vector<vector<bool>> vis(m, vector<bool>(n));
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, 0});
        
        while(!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int diff = get<0>(cur), x = get<1>(cur), y = get<2>(cur);
            vis[x][y] = true;
            
            for(auto &dir : dirs) {
                int dx = x + dir.first, dy = y + dir.second;
                
                if(dx >= 0 && dx < m && dy >= 0 && dy < n && !vis[dx][dy]) {
                    int ndiff = max(diff, abs(heights[x][y] - heights[dx][dy]));
                    
                    if(ndiff < dp[dx][dy]) {
                        dp[dx][dy] = ndiff;
                        pq.push({ndiff, dx, dy});
                    }
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};
