class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;

        vector<vector<int>> best(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        best[0][0] = startHealth;
        q.push({0, 0});

        array<pair<int, int>, 4> dirs = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == m - 1 && y == n - 1) return true;

            for (auto &[dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;

                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

                int newHealth = best[x][y] - grid[nx][ny];

                if (newHealth <= 0) continue;

                if (newHealth > best[nx][ny]) {
                    best[nx][ny] = newHealth;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }
};
