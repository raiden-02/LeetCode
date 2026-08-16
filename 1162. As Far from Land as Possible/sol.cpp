class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(m == 0 or n == 0) return -1;

        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        if(q.size() == m * n) return -1;

        int ans = 0;

        while(not q.empty()) {
            int s = q.size();
            ans++;

            while(s--) {
                auto cur = q.front(); q.pop();
                int x = cur.first, y = cur.second;

                for(auto &dir : dirs) {
                    int dx = x + dir.first, dy = y + dir.second;
                    if(dx >= 0 and dx < m and dy >= 0 and dy < m and grid[dx][dy] == 0) {
                        q.push({dx, dy});
                        grid[dx][dy] = 1;
                    }
                }
            }
        }

        return ans - 1;
    }
};
