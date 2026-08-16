class Solution {
    int helper(vector<int> nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        
        if(n == 1)
            return nums[0];
        
        if(n == 2)
            return max(nums[0], nums[1]);
        
        nums[2] += nums[0];
        
        for(int i = 3; i < n; i++)
            nums[i] += max(nums[i - 2], nums[i - 3]);
        
        return *max_element(nums.begin(), nums.end());
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        return max(helper(vector<int>(nums.begin(), nums.begin() + n - 1)), helper(vector<int>(nums.begin() + 1, nums.end()))); 
    }
};
