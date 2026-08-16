class Solution {
    static const int N = 1e4 + 1;
    int dp[N];
    
    int helper(int n) {
        if(n == 0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        int ans = INT_MAX / 2;
        
        for(int i = 1; i * i <= n; i++)
            ans = min(ans, helper(n - i * i) + 1);
        
        return dp[n] = ans;
    }
public:
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        
        return helper(n);
    }
};

// --- alternate solution ---

class Solution {
    vector<int> dp;
    
    int helper(int n) {
        if(n == 0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        int ans = INT_MAX;
        for(int i = 1; i*i <= n; i++)
            ans = min(ans, helper(n - i*i) + 1);
        
        return dp[n] = ans;
    }
public:
    int numSquares(int n) {
        dp.resize(n + 1, -1);
        
        return helper(n);
    }
};
