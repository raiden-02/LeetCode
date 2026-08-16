class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> grid(m, vector<int>(n, INT_MAX));
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        auto bound = [&](int x, int y) {
            return x >= 0 && y >= 0 && x < m && y < n;
        };
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0)
                    grid[i][j] = 0;
                
                else {
                    queue<pair<int, int>> q;
                    bool f = false;
                    q.push(make_pair(i, j));
                    int dist = 0;
                    
                    while(!q.empty()) {
                        int s = q.size();
                        while(s--) {
                            
                            int x = q.front().first, y = q.front().second;
                            q.pop();
                            if(matrix[x][y] == 0) {
                                f = true;
                                grid[i][j] = dist;
                                break;
                            }
                            
                            for(auto &dir : dirs) {
                                int dx = dir.first + x, dy = dir.second + y;
                                if(bound(dx, dy))
                                    q.push(make_pair(dx, dy));
                            }
                        }
                        if(f) break;
                        dist++;
                    }
                }
            }
        }
        return grid;
    }
};

// --- alternate solution ---

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        size_t m = mat.size(), n = mat[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<size_t, size_t>> q;

        for(size_t i = 0; i < m; i++) {
            for(size_t j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }

        vector<vector<int>> ans(m, vector<int>(n, 0));
        int len = 0;

        while(!q.empty()) {
            int s = q.size();
            while(s--) {
                auto cur = q.front(); q.pop();
                size_t x = cur.first, y = cur.second;

                for(auto &dir : dirs) {
                    int dx = x + dir.first, dy = y + dir.second;

                    if(dx >= 0 && dx < m && dy >= 0 && dy < n && !vis[dx][dy]) {
                        q.push({dx, dy});
                        ans[dx][dy] = len + 1;
                        vis[dx][dy] = true;
                    }
                }
            }

            len++;
        }

        return ans;
    }
};

// --- alternate solution ---

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        queue<pair<int, int>> q;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0)
                    ans[i][j] = 0, q.push({i, j});
            }
        }
        
        while(not q.empty()) {
            auto cur = q.front(); q.pop();
            int x = cur.first, y = cur.second;
            
            for(auto &dir : dirs) {
                int dx = x + dir.first, dy = y + dir.second;
                
                if(dx >= 0 and dx < m and dy >= 0 and dy < n) {
                    if(ans[dx][dy] > ans[x][y] + 1)
                        ans[dx][dy] = ans[x][y] + 1, q.push({dx, dy});
                }
            }
        }
        
        return ans;
    }
};
