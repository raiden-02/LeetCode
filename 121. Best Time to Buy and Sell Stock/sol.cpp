class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = 0;
        vector<int> left(n), right(n);
        left[0] = prices[0], right[n - 1] = prices[n - 1];
        
        for(int i = 1; i < n; i++)
            left[i] = min(left[i - 1], prices[i]), right[n - i - 1] = max(right[n - i], prices[n - i - 1]);
        
        for(int i = 0; i < n - 1; i++)
            ans = max(ans, right[i + 1] - left[i]);
        
        return ans;
    }
};
