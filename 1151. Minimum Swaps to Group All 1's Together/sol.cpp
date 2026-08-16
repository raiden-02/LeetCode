class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones = count(data.begin(), data.end(), 1), n = data.size();
        
        vector<int> dp(n + 1);
        
        for(int i = 1; i < n + 1; i++) {
            if(data[i - 1])
                dp[i] = dp[i - 1];
            else
                dp[i] = dp[i - 1] + 1;
        }
        
        int ans = INT_MAX;
        
        for(int i = ones; i < n + 1; i++)
            ans = min(ans, dp[i] - dp[i - ones]);
        
            
        return ans;
    }
};
