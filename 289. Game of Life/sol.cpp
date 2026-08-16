class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> ans = board;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {1, -1}, {-1, 1}, {1, 1}, {-1, -1}};
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int live = 0;
                
                for(auto &dir : dirs) {
                    int dx = i + dir.first, dy = j + dir.second;
                    if(dx >= 0 and dx < m and dy >= 0 and dy < n and board[dx][dy])
                        live += 1;
                }
                
                if(board[i][j]) {
                    if(live < 2 || live > 3)
                        ans[i][j] = 0;
                }
                
                else {
                    if(live == 3)
                        ans[i][j] = 1;
                }
            }
        }
        
        board = ans;
    }
};
