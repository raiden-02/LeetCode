class Solution {
    vector<vector<int>> dp;
    
    int helper(string const& s, string const& t, int si, int ti) {
        if(ti >= t.length())
            return 1;
        
        if(si >= s.length())
            return 0;
        
        if(dp[si][ti] != -1)
            return dp[si][ti];
        
        int ans = 0;
        
        if(s[si] == t[ti])
            ans += helper(s, t, si + 1, ti + 1);
        
        ans += helper(s, t, si + 1, ti);
        
        return dp[si][ti] = ans;
    }
public:
    int numDistinct(string s, string t) {
        dp.resize(s.length(), vector<int>(t.length(), -1));
        return helper(s, t, 0, 0);
    }
};
