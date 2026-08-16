class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0] == 1)
            return 0;
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        
        for(int i = 0; i < m; i++) {
            if(grid[i][0] != 1)
                dp[i][0] = 1;
            else
                break;
        }
        
        for(int j = 0; j < n; j++) {
            if(grid[0][j] != 1)
                dp[0][j] = 1;
            else
                break;
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(grid[i][j] == 1) continue;
                
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        
        return dp[m - 1][n - 1];
    }
};
