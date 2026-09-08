class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        constexpr int INF = 1e9;

        // cost, row, col, previous direction, turns used
        using State = array<int, 5>;
        priority_queue<State, vector<State>, greater<State>> q;

        array<pair<int, int>, 4> dirs = {{
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0},
        }};

        // row, col, direction, turns
        // direction 4 = no previous move
        vector dist(m, vector(n, vector(5, vector<int>(k + 1, INF))));

        dist[0][0][4][0] = grid[0][0];
        q.push({grid[0][0], 0, 0, 4, 0});

        while (!q.empty()) {
            auto [cost, x, y, prev_dir, turns] = q.top();
            q.pop();

            if (cost != dist[x][y][prev_dir][turns]) continue;

            if (x == m - 1 && y == n - 1) return cost;

            for (int d = 0; d < 4; d++) {
                auto [dx, dy] = dirs[d];
                int nx = x + dx, ny = y + dy;

                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

                int next_turns = turns + (prev_dir != 4 && prev_dir != d);

                if (next_turns > k) continue;

                int next_cost = cost + grid[nx][ny];

                if (next_cost < dist[nx][ny][d][next_turns]) {
                    dist[nx][ny][d][next_turns] = next_cost;
                    q.push({next_cost, nx, ny, d, next_turns});
                }
            }
        }

        return -1;
    }
};
