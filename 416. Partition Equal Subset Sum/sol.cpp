class Solution {
    vector<unordered_map<int, int>> dp;
    
    bool helper(vector<int> const& nums, int ind, int s, int const& total) {
        if(s == total)
            return true;
        
        if(ind >= nums.size() or s > total)
            return false;
        
        if(dp[ind].find(s) != dp[ind].end())
            return dp[ind][s];
        
        return dp[ind][s] = helper(nums, ind + 1, s + nums[ind], total) or helper(nums, ind + 1, s, total);
    }
public:
    bool canPartition(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        
        if(s % 2)
            return false;
        
        s /= 2;
        dp.resize(nums.size());
        
        return helper(nums, 0, 0, s);
    }
};
