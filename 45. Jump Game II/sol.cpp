class Solution {
    vector<int> dp;
    int helper(vector<int> &nums, int ind) {
        if(ind >= (int)nums.size() - 1) return 0;

        if(dp[ind] != -1) return dp[ind];

        int ans = INT_MAX / 2;

        for(int i = ind + 1; i <= nums[ind] + ind; i++) {
            ans = min(ans, 1 + helper(nums, i));
        }

        return dp[ind] = ans;
    }
public:
    int jump(vector<int>& nums) {
        dp.resize(nums.size(), -1);
        return helper(nums, 0);
    }
};

//iterative dp

// --- alternate solution ---

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 1; j <= nums[i] and i + j < n; j++)
                dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
        
        return dp[n - 1];
    }
};
