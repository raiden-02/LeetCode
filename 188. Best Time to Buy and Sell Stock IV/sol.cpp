class Solution {
    int dp[2][1001][101];
    
    int helper(int ind, vector<int> const& prices, int k, bool toBuy) {
        if(ind >= prices.size() or k <= 0)
            return 0;
        
        if(dp[toBuy][ind][k] != -1)
            return dp[toBuy][ind][k];
        
        int ans = 0;
        
        ans = max(ans, helper(ind + 1, prices, k, toBuy));
        
        if(toBuy)
            ans = max(ans, helper(ind + 1, prices, k, false) - prices[ind]);
        else
            ans = max(ans, helper(ind + 1, prices, k - 1, true) +  prices[ind]);
        
        return dp[toBuy][ind][k] = ans;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return helper(0, prices, k, true);
    }
};
