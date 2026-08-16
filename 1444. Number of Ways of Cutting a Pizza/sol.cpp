class Solution {
    int dp[51][51][11];
    int presum[51][51];
    const int MOD = 1e9 + 7;
    
    int helper(vector<string> const& pizza, int r, int c, int k) {
        if(k == 1) return presum[r][c] ? 1 : 0;
        
        if(dp[r][c][k] != -1) return dp[r][c][k];
        
        int ans = 0;
        
        for(int i = r + 1; i < pizza.size(); i++) {
            if((presum[r][c] - presum[i][c]) and presum[i][c])
                ans = (ans + helper(pizza, i, c, k - 1)) % MOD;
        }
        
        for(int j = c + 1; j < pizza[0].size(); j++) {
            if((presum[r][c] - presum[r][j]) and presum[r][j])
                ans = (ans + helper(pizza, r, j, k - 1)) % MOD;
        }
        
        return dp[r][c][k] = ans;
    }
public:
    int ways(vector<string>& pizza, int k) {
        memset(dp, -1, sizeof(dp));
        
        for(int i = pizza.size() - 1; i >= 0; i--) {
            for(int j = pizza[0].size() - 1; j >= 0; j--) {
                presum[i][j] = presum[i][j + 1] + presum[i + 1][j] - presum[i + 1][j + 1] + (pizza[i][j] == 'A');
            }
        }
        
        if(presum[0][0] < k) return 0; //total no of apples less than the number of people
        
        return helper(pizza, 0, 0, k);
    }
};
