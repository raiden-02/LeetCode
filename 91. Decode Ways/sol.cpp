class Solution {
    int dp[101];
    
    int helper(string const& s, int ind) {
        if(ind >= s.length())
            return 1;
        
        if(s[ind] == '0')
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int ans = 0;
        string cur = s.substr(ind, 2);
        int x = stoi(cur);
        
        if(x >= 10 and x <= 26)
            ans = helper(s, ind + 2);
        
        return dp[ind] = ans + helper(s, ind + 1);
    }
public:
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return helper(s, 0);
    }
};

// --- alternate solution ---

class Solution {
    vector<int> dp;
    
    int helper(string const& s, int ind) {
        if(ind >= s.length())
            return 1;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int ans = 0;
        
        if(s[ind] - '0' >= 1)
            ans += helper(s, ind + 1);
        
        int x = stoi(s.substr(ind, 2));
        
        if(x >= 10 and x <= 26)
            ans += helper(s, ind + 2);
        
        return dp[ind] = ans;
    }
public:
    int numDecodings(string s) {
        dp.resize(s.length(), -1);
        return helper(s, 0);
    }
};
