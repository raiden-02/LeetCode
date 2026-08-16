class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, r = 0, ans = 0, s = 0;
        unordered_map<int, int> mp;
        
        while(r < nums.size()) {
            mp[nums[r]]++, s += nums[r];
            
            while(l < r and mp[nums[r]] > 1)
                s -= nums[l], mp[nums[l++]]--;
            
            ans = max(ans, s), r++;
        }
        
        return ans;
    }
};
