class Solution {
    int max_diff(vector<int> const& nums, vector<vector<int>> &dp, int l, int r) {
        if (l == r) return nums[l];
        
        if (dp[l][r] != -1) return dp[l][r];

        return dp[l][r] = max(nums[l] - max_diff(nums, dp, l + 1, r), nums[r] - max_diff(nums, dp, l, r - 1));
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return max_diff(nums, dp, 0, n - 1) >= 0;
    }
};
