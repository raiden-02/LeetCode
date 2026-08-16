class Solution {
public:
    int helper(string const& text1, string const& text2, int i, int j, vector<vector<int>> &dp) {
        if(i == text1.length() || j == text2.length())
            return 0;
        
        if(dp[i][j] != INT_MIN)
            return dp[i][j];
        
        if(text1[i] == text2[j])
            return dp[i][j] = 1 + helper(text1, text2, i + 1, j + 1, dp);
        
        return dp[i][j] = max(helper(text1, text2, i + 1, j, dp), helper(text1, text2, i, j + 1, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), INT_MIN));
        return helper(text1, text2, 0, 0, dp);
    }
};

// --- alternate solution ---

// table
class Solution {
    int dp[1001][1001];
public:
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, 0, sizeof(dp));
        int m = text1.length(), n = text2.length();
        
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {                
                if(text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }

                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];

    }
};

// memoize
