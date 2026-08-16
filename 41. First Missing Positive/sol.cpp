class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        if(nums[0] > 1) return 1;
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] < 0 and nums[i] > 1) return 1;
            
            if(nums[i - 1] >= 0 and nums[i] - nums[i - 1] > 1) return nums[i - 1] + 1;
        }
        
        return nums.back() <= 0 ? 1 : nums.back() + 1;
    }
};
