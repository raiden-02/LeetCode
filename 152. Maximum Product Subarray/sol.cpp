class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxdp(nums.size()), mindp(nums.size());
        int ans;
        maxdp[0] = mindp[0] = ans = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > 0) {
                maxdp[i] = max(maxdp[i - 1] * nums[i], nums[i]);
                mindp[i] = min(mindp[i - 1] * nums[i], nums[i]);
            }
            
            else {
                maxdp[i] = max(mindp[i - 1] * nums[i], nums[i]);
                mindp[i] = min(maxdp[i - 1] * nums[i], nums[i]);
            }
            
            ans = max(ans, maxdp[i]);
        }
        
        return ans;
    }
};

// --- alternate solution ---

//intuitive memoization
class Solution {
    vector<unordered_map<int, int>> dp;
    
    int helper(vector<int> const& nums, int ind, int prod) {
        if(ind >= nums.size())
            return prod;
        
        if(dp[ind].find(prod) != dp[ind].end())
            return dp[ind][prod];
        
        return dp[ind][prod] = max(prod, max(helper(nums, ind + 1, prod * nums[ind]), helper(nums, ind + 1, nums[ind])));
    }
public:
    int maxProduct(vector<int>& nums) {
        dp.resize(nums.size());
        return helper(nums, 1, nums[0]);
    }
};

//linear dp O(n) space
