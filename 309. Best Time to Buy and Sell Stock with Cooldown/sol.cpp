class Solution {
public:
    int helper(vector<int> const& prices, int ind, int todo, vector<vector<int>> &dp) {
        if(ind >= prices.size())
            return 0;
        
        if(dp[ind][todo] != INT_MIN)
            return dp[ind][todo];
        
        int buy = 0;
        if(todo == 0)
            buy = helper(prices, ind + 1, 1, dp) - prices[ind];
        else
            buy = helper(prices, ind + 2, 0, dp) + prices[ind];
        
        int dbuy = helper(prices, ind + 1, todo, dp);
        return dp[ind][todo] = max(buy, dbuy);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, INT_MIN));
        return helper(prices, 0, 0, dp);
    }
};

// --- alternate solution ---

class Solution {
    int dp[5001][2];
    int helper(vector<int> const& prices, int ind, bool buy) {
        if(ind >= prices.size())
            return 0;
        if(dp[ind][buy] != -1)
            return dp[ind][buy];

        int ans = helper(prices, ind + 1, buy);

        if(buy)
            return dp[ind][buy] = max(helper(prices, ind + 1, false) - prices[ind], ans);
        
        return dp[ind][buy] = max(helper(prices, ind + 2, true) + prices[ind], ans);
    }
public:
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return helper(prices, 0, true);
    }
};

// --- alternate solution ---

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1)
            return 0;
        
        vector<int> buy(n), sell(n);
        
        buy[0] = -prices[0], buy[1] = max(-prices[1], buy[0]);
        sell[0] = 0, sell[1] = max(prices[1] - prices[0], sell[0]);
        
        for(int i = 2; i < n; i++) {
            buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }
        
        return sell.back();
    }
};
