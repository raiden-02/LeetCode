class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if(nums.empty()) {
            if(lower == upper)
                return {to_string(lower)};
            return {to_string(lower) + "->" + to_string(upper)};
        }
        
        vector<string> ans;
        int n = nums.size();
        
        if(nums[0] - lower >= 1)
            lower == nums[0] - 1 ? ans.push_back(to_string(lower)) : ans.push_back(to_string(lower) + "->" + to_string(nums[0] - 1));
            
        
        for(int i = 0; i < n - 1; i++) {
            if(nums[i + 1] - nums[i] <= 1) continue;
            
            nums[i] + 1 == nums[i + 1] - 1 ? ans.push_back(to_string(nums[i] + 1)) : ans.push_back(to_string(nums[i] + 1) + "->" + to_string(nums[i + 1] - 1));
        }
        
        if(upper - nums.back() >= 1)
            upper == nums.back() + 1 ? ans.push_back(to_string(upper)) : ans.push_back(to_string(nums.back() + 1) + "->" + to_string(upper));
        
        return ans;
    }
};
