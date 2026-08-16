class Solution {
    unordered_map<int, int> mp;
public:
    int climbStairs(int n) {
        if(n == 0) 
            return 1;
        
        if(n < 0)
            return 0;
        
        if(mp.find(n) != mp.end())
            return mp[n];
        
        return mp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};

// --- alternate solution ---

class Solution {
public:
    int climbStairs(int n) {
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1, dp[1] = 1;
        
        for(int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
        
        return dp[n];
    }
};
