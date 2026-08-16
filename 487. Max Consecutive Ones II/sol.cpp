class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        vector<int> cnt(2);
        int l = 0, r = 0;
        
        while(r < n) {
            cnt[nums[r]]++;
            
            while(cnt[0] > 1 and l <= r)
                cnt[nums[l++]]--;
            
            ans = max(ans, r - l + 1);
            r++;
        }
        
        return ans;
    }
};
