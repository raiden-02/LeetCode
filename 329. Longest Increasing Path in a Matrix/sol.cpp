class Solution {
    int ans = 0;
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int dfs(vector<vector<int>> const& matrix, int i, int j, int const& m, int const& n, vector<vector<int>> &dp) {
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int cur = matrix[i][j], len = 0;
        
        for(auto &dir : dirs) {
            int dx = i + dir.first, dy = j + dir.second;
            
            if(dx >= 0 and dx < m and dy >= 0 and dy < n and matrix[dx][dy] > cur)
                len = max(len, dfs(matrix, dx, dy, m ,n ,dp) + 1);
        }
        
        return dp[i][j] = len;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans = max(ans, dfs(matrix, i, j, m, n, dp) + 1);
            }
        }
        
        return ans;
    }
};
