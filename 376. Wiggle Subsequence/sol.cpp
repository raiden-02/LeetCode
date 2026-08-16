//intuitive top down memoiztion
class Solution {
    vector<int> dp;
    int helper(vector<int> const& nums, int ind, int pd, bool f) {
        if(ind >= nums.size())
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int ans = 1, cur = nums[ind];
        for(int i = ind + 1; i < nums.size(); i++) {
            if(f && nums[i] - cur != 0)
                ans = max(ans, helper(nums, i, nums[i] - cur, false) + 1);
            else if(pd * (nums[i] - cur) < 0)
                ans = max(ans, helper(nums, i, nums[i] - cur, f) + 1);
        }
        return dp[ind] = ans;
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        dp = vector<int>(nums.size(), -1);
        int ans = 1;
        for(int i = 0; i < nums.size(); i++)
            ans = max(ans, helper(nums, i, 0, true));
        return ans;
    }
};

//greedy

// --- alternate solution ---

class Solution {
    vector<vector<int>> dp;
    
    int helper(vector<int> &nums, int ind, int prevd) {
        if(ind >= nums.size())
            return 0;
        
        int j = (prevd > 0) ? 1 : (prevd < 0 ? 2 : 0);
        
        if(dp[ind][j] != -1)
            return dp[ind][j];
        
        int ans = 1;
        
        for(int i = ind + 1; i < nums.size(); i++) {
            int d = nums[i] - nums[ind];
            
            if(d == 0) continue;
            
            if(ind == 0 or (prevd > 0 and d < 0) or (prevd < 0 and d > 0))
                ans = max(ans, helper(nums, i, d) + 1);
        }
        
        return dp[ind][j] = ans;
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        dp.resize(nums.size(), vector<int>(3, -1));
        return helper(nums, 0, 0);
    }
};

// --- alternate solution ---

class Solution {
    int dp[1001][3];
    
    int helper(vector<int> const& nums, int ind, int prevd) {
        if(ind >= nums.size())
            return 0;
        
        int j = prevd > 0 ? 1 : prevd < 0 ? 2 : 0;
        
        if(dp[ind][j] != -1)
            return dp[ind][j];
        
        int ans = 1;
        
        for(int i = ind + 1; i < nums.size(); i++) {
            int diff = nums[i] - nums[ind];
            
            if(diff == 0) continue;
            
            if(ind == 0 or prevd * diff < 0)
                ans = max(ans, helper(nums, i, diff) + 1);
        }
        
        return dp[ind][j] = ans;
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return helper(nums, 0, 0);
    }
};

// --- alternate solution ---

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
            return n;
        
        int prevd = nums[1] - nums[0];
        int len = prevd != 0 ? 2 : 1;
        
        for(int i = 2; i < n; i++) {
            int cur = nums[i] - nums[i - 1];
            
            if((cur > 0 && prevd <= 0) || (cur < 0 && prevd >= 0)) {
                prevd = cur;
                len += 1;
            }
        }
        
        return len;
    }
};
