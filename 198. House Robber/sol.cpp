class Solution {
public:
    int rob(vector<int>& nums) {
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
};

// --- alternate solution ---

class Solution {
public:
    int rob(vector<int>& nums) {
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
        
        return max(nums[n - 2], nums[n - 1]);
    }
};

// --- alternate solution ---

class Solution {
    //dp[i] = dp[i - 2] + dp[i - 3];
    public int rob(int[] nums) {
        int n = nums.length;
        if(n == 1)
            return nums[0];
        if(n == 2)
            return Math.max(nums[1], nums[0]);
        nums[2] += nums[0];
        for(int i = 3; i < n; i++) {
            nums[i] += Math.max(nums[i - 2], nums[i - 3]);
        }
        
        return Math.max(nums[n - 1], nums[n - 2]);
    }
}
