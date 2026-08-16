class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() and board[0].empty())
            return;
        
        int m = board.size(), n = board[0].size();
        
        auto bound = [&m, &n](int x, int y) {
            return x < m and x >= 0 and y < n and y >= 0;
        };
        
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if((i == 0 or j == 0 or i == m - 1 or j == n - 1) and board[i][j] == 'O') {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = true;
                    
                    while(not q.empty()) {
                        auto cur = q.front(); q.pop();
                        int x = cur.first, y = cur.second;
                        
                        for(auto &dir : dirs) {
                            int dx = x + dir.first, dy = y + dir.second;
                            
                            if(bound(dx, dy) and board[dx][dy] == 'O' and not vis[dx][dy])
                                q.push({dx, dy}), vis[dx][dy] = true;
                        }
                    }
                }
            }
        }
        
        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++) 
                if(board[i][j] == 'O' and not vis[i][j]) board[i][j] = 'X';
    }
};
