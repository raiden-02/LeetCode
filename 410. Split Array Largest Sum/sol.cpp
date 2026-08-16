class Solution {
    int dp[1001][51];
    
    int helper(vector<int> &nums, int m, int ind) {
        if(ind >= nums.size()) {
            if(m == 0) return 0;
            return INT_MAX;
        }
        
        if(m <= 0)
            return INT_MAX;
        
        if(dp[ind][m] != -1)
            return dp[ind][m];
        
        int ans = INT_MAX, s = 0;
        
        for(int i = ind; i < nums.size(); i++) {
            s += nums[i];
            ans = min(ans, max(s, helper(nums, m - 1, i + 1)));
        }
        
        return dp[ind][m] = ans;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        memset(dp, -1, sizeof(dp));
        return helper(nums, m, 0);
    }
};
