class Solution {
    vector<vector<int>> dp;
    int helper(string const& s, int start, int end) {
        if(start > end)
            return 0;
        
        if(start == end)
            return dp[start][end] = 1;
        
        if(dp[start][end] != -1)
            return dp[start][end];
        
        if(s[start] == s[end])
            return dp[start][end] = 2 + helper(s, start + 1, end - 1);
        
        return dp[start][end] = max(helper(s, start, end - 1), max(helper(s, start + 1, end), helper(s, start + 1, end - 1)));
    }
public:
    int longestPalindromeSubseq(string s) {
        dp = vector<vector<int>>(s.length(), vector<int>(s.length(), -1));
        return helper(s, 0, s.length() - 1);
    }
};
