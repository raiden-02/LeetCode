class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.length();
        long dp[n][n];
        memset(dp, 0, sizeof(dp));
        const long MOD = 1e9 + 7;

        for(int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;

            for(int j = i + 1; j < n; j++) {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] * 2;

                    int l = i + 1, r = j - 1;

                    while(l <= r and s[l] != s[i]) l++;
                    while(l <= r and s[r] != s[i]) r--;

                    if(l > r) dp[i][j] += 2;
                    else if(l == r) dp[i][j] += 1;
                    else dp[i][j] -= dp[l + 1][r - 1];
                }

                else dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];

                dp[i][j] = (dp[i][j] + MOD) % MOD;
            }
        }

        return dp[0][n - 1];
    }
};
