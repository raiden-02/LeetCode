class Solution {
    vector<vector<int>> dp;
    
    int helper(vector<int> const& coins, int ind, int amount) {
        if(amount == 0)
            return 0;
        
        if(ind >= coins.size() or amount < 0)
            return 1e4 + 1;
        
        if(dp[ind][amount] != -1)
            return dp[ind][amount];
        
        return dp[ind][amount] = min(helper(coins, ind, amount - coins[ind]) + 1, min(helper(coins, ind + 1, amount - coins[ind]) + 1, helper(coins, ind + 1, amount)));
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size(), vector<int>(amount + 1, -1));
        
        int ans = helper(coins, 0, amount);
        return ans >= 1e4 + 1 ? -1 : ans;
    }
};
