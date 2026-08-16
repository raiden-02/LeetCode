class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        long long l = 0, ans = 1, s = 0;
        
        for(int r = 0; r < n; r++) {
            while(nums[r] * (r - l) - s > k)
                s -= nums[l], l++;
            
            s += nums[r];
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};
