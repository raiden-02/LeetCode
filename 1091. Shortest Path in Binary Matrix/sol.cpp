class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(m == 0 || n == 0 || grid[0][0] == 1)
        return -1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int dist = 1;
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {1, 1}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};

        while(!q.empty()) {
            int s = q.size();

            while(s--) {
                auto cur = q.front(); q.pop();
                int x = cur.first, y = cur.second;

                if(x == m - 1 && y == n - 1)
                    return dist;

                for(auto &dir : dirs) {
                    int dx = x + dir.first, dy = y + dir.second;

                    if(dx >= 0 && dx < m && dy >= 0 && dy < n && grid[dx][dy] == 0) {
                        grid[dx][dy] = 1;
                        if(dx == m - 1 && dy == n - 1) {
                            return dist + 1;
                        }

                        q.push({dx, dy});
                    }
                }
            }

            dist++;
        }

        return -1;
    }
};
