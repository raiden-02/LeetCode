class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4) return 0;
        
        int ans = numeric_limits<int>::max();
        sort(nums.begin(), nums.end());
        
        for(int left = 0, right = n - 4; left < 4 && right < n; left++, right++) {
            ans = min(ans, nums[right] - nums[left]);
        }

        return ans;
    }
};
