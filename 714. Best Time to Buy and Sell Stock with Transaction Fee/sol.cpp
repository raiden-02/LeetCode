class Solution {
    vector<vector<int>> dp;
    int helper(vector<int> const& prices, int const& fee, int ind, int opt) {
        if(ind == prices.size())
            return 0;
        
        if(dp[ind][opt] != -1)
            return dp[ind][opt];
        
        if(opt == 0)
            return dp[ind][opt] = max(helper(prices, fee, ind + 1, 1) - prices[ind], helper(prices, fee, ind + 1, 0));
        
        return dp[ind][opt] = max(helper(prices, fee, ind + 1, 0) + prices[ind] - fee, helper(prices, fee, ind + 1, 1));
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        dp = vector<vector<int>>(prices.size(), vector<int>(2, -1));
        return helper(prices, fee, 0, 0);
    }
};

// --- alternate solution ---

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> buy(n), sell(n);
        buy[0] = -prices[0];
        
        for(int i = 1; i < n; i++) {
            buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i] - fee);
        }
        
        return sell.back();
    }
};

// --- alternate solution ---

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int buy = -prices[0], sell = 0;
        
        for(int i = 1; i < n; i++) {
            int buy1 = max(buy, sell - prices[i]);
            int sell1 = max(sell, buy + prices[i] - fee);
            buy = buy1, sell = sell1;
        }
        
        return sell;
    }
};
