class Solution {
    vector<int> dp;
    
    int helper(int const& n, int cur) {
        if(cur == n)
            return 1;
        
        if(cur > n)
            return 0;
        
        if(dp[cur] != -1)
            return dp[cur];
        
        int ans = 0;
        
        for(int i = n - 1; i >= 1; i--)
            ans = max(ans, helper(n, cur + i) * i);
        
        return dp[cur] = ans;
    }
public:
    int integerBreak(int n) {
        int ans = 0;
        dp.resize(n + 1, -1);
        
        for(int i = n - 1; i >= 1; i--)
            ans = max(ans, helper(n, i) * i);
        
        return ans;
    }
};
