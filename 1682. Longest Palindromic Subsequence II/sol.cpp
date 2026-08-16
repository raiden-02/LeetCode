class Solution {
    vector<vector<vector<int>>> dp;
    int helper(string const& s, int start, int end, int p) {
        if(start >= end)
            return 0;
        
        if(dp[start][end][p] != -1)
            return dp[start][end][p];
        
        if(s[start] - 'a' == p)
            return dp[start][end][p] = helper(s, start + 1, end, p);
        if(s[end] - 'a' == p)
            return dp[start][end][p] = helper(s, start, end - 1, p);
        
        if(s[start] == s[end])
            return dp[start][end][p] = 2 + helper(s, start + 1, end - 1, s[start] - 'a');
        
        return dp[start][end][p] = max(helper(s, start + 1, end, p), helper(s, start, end - 1, p));
    }
public:
    int longestPalindromeSubseq(string s) {
        dp = vector<vector<vector<int>>>(s.length(), vector<vector<int>>(s.length(), vector<int>(27, -1)));
        return helper(s, 0, s.length() - 1, 26);
    }
};
