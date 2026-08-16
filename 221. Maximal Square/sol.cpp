class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                dp[i][j] = (i == 0 or j == 0) ? matrix[i][j] - '0' : (matrix[i][j] == '1') ? min(dp[i][j - 1], min(dp[i - 1][j - 1], dp[i - 1][j])) + 1 : 0, ans = max(ans, dp[i][j]);
        }
        
        return ans * ans;
    }
};
