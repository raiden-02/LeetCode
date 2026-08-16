class Solution {
    vector<vector<int>> dp;
    bool helper(string const& s, string const& p, int si, int pi, int const& m, int const& n) {
        if(si == m && pi == n)
            return true;
        
        if(si == m) {
            for(int i = pi; i < n; i++) {
                if((i == n - 1 && p[i] != '*') || (p[i] != '*' && p[i + 1] != '*'))
                    return false;
            }
            return true;
        }
        
        if(si != m && pi == n)
            return false;
        
        if(dp[si][pi] != -1)
            return dp[si][pi];
        
        if(p[pi] == '*') {
            if((s[si] == p[pi - 1] || p[pi - 1] == '.') && (helper(s, p, si + 1, pi + 1, m, n) || helper(s, p, si + 1, pi, m, n)))
                return dp[si][pi] = 1;
            if(helper(s, p, si, pi + 1, m, n)) // if current char doesn't match pi - 1, then si remains the same cuz we need to match it
                return dp[si][pi] = 1;
        }
        
        if((p[pi] == s[si] || p[pi] == '.') && helper(s, p, si + 1, pi + 1, m, n)) //match by same char or .
            return dp[si][pi] = 1;
        
        if(p[pi + 1] == '*' && helper(s, p, si, pi + 1, m, n)) //matching 0 characters
            return dp[si][pi] = 1;
        
        return dp[si][pi] = 0;
    }
public:
    bool isMatch(string s, string p) {
        dp = vector<vector<int>>(s.length(), vector<int>(p.length(), -1));
        return helper(s, p, 0, 0, s.length(), p.length());
    }
};
