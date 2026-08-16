class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, n));
        int ans = 0;
        
        for(auto &mine : mines) grid[mine[0]][mine[1]] = 0;
        
        
        for(int i = 0; i < n; i++) {
            //min of left 1s, right 1s, top 1s, bottom 1s
            int l = 0, r = 0, u = 0, d = 0;
            
            for(int j = 0, k = n - 1; j < n and k >= 0; j++, k--) {
                grid[i][j] = min(grid[i][j], l = grid[i][j] == 0 ? 0 : l + 1);
                grid[i][k] = min(grid[i][k], r = grid[i][k] == 0 ? 0 : r + 1);
                grid[j][i] = min(grid[j][i], u = grid[j][i] == 0 ? 0 : u + 1);
                grid[k][i] = min(grid[k][i], d = grid[k][i] == 0 ? 0 : d + 1);
            }
        }
        
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ans = max(ans, grid[i][j]);
        
        return ans;
    }
};
