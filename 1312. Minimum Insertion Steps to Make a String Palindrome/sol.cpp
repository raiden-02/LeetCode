class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                s[i - 1] == tmp[j - 1] ? dp[i][j] = dp[i - 1][j - 1] + 1 : dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        return n - dp[n][n];
    }
};
