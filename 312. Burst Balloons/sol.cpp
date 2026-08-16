class Solution {
    int dp[502][502];
        
    int helper(vector<int> const& nums, int l, int r) {
        if(l == r - 1)
            return 0;
        
        if(dp[l][r] != -1)
            return dp[l][r];
        
        int ans = 0;
        
        for(int i = l + 1; i < r; i++) {
            int cur = nums[l] * nums[i] * nums[r];
            ans = max(ans, cur + helper(nums, l, i) + helper(nums, i, r));
        }
        
        return dp[l][r] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        if(nums.size() == 0)
            return nums[0];
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        memset(dp, -1, sizeof(dp));
        return helper(nums, 0, nums.size() - 1);
    }
};
