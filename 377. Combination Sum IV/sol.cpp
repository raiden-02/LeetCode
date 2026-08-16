class Solution {
    int dp[1001];
    int helper(vector<int> const& arr, int target) {
        if(target == 0)
            return 1;
        
        if(target < 0)
            return 0;
        
        if(dp[target] != -1)
            return dp[target];
        
        int ans = 0;
        
        for(int i = 0; i < arr.size(); i++) {
            if(target - arr[i] >= 0)
                ans += helper(arr, target - arr[i]);
        }
        
        return dp[target] = ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return helper(nums, target);
    }
};

// --- alternate solution ---

class Solution {
    int dp[1001];
    
    int helper(vector<int> const& nums, int target) {
        if(target == 0)
            return 1;
        
        if(target < 0)
            return 0;
        
        if(dp[target] != -1)
            return dp[target];
        
        int s = 0, ans = 0;
        
        for(int const& i : nums) {
            s += i;
            ans += helper(nums, target - s);
            s -= i;
        }
        
        return dp[target] = ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return helper(nums, target);
    }
};
