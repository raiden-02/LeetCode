class Solution {
    int dp[1000][1000];
    
    int helper(vector<int> const& nums, vector<int> const& mult, int ind, int start, int end) {
        if(start > end || ind == mult.size())
            return 0;
        
        if(dp[ind][start] != -1)
            return dp[ind][start];
        
        return dp[ind][start] = max(helper(nums, mult, ind + 1, start + 1, end) + (nums[start] * mult[ind]), helper(nums, mult, ind + 1, start, end - 1) + (nums[end] * mult[ind]));
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        
        memset(dp, -1, sizeof(dp));
        
        return helper(nums, multipliers, 0, 0, n - 1);
    }
};
