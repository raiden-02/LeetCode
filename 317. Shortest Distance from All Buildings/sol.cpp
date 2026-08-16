class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int sum = 0, minDis = INT_MAX;
        for(auto x: grid)
            for(auto y: x) if(y == 1) sum++;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 0) bfs(grid, m, n, i, j, sum, minDis);
        return minDis == INT_MAX ? -1 : minDis;
    }
    
    void bfs(vector<vector<int>>& grid, int m, int n, int r, int c, int sum, int& minDis) {
        vector<vector<int>>visited(m, vector<int>(n));
        vector<pair<int, int>>dir{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        int lvl = 1, dis = 0, count = 0;
        q.push({r, c});
        while(count < sum && !q.empty()) {
            int s = q.size();
            while(s--) {
                auto p = q.front();
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int R = p.first + dir[i].first;
                    int C = p.second + dir[i].second;
                    if(R < 0 || C < 0 || R == m || C == n || visited[R][C]) continue;
                    visited[R][C] = 1;
                    if(grid[R][C] == 1) {
                        dis += lvl;
                        count++;
                    }
                    if(grid[R][C] == 0)
                        q.push({R, C});
                }
            }
            lvl++;
            
        }
        if(count == sum) minDis = min(minDis, dis);
    }
};
