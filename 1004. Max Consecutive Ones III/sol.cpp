class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), r = 0, l = 0, flipped = 0, ans = 0, cnt = 0;
        
        while(r < n) {
            if(nums[r] == 0) flipped++;
            else cnt++;
            
            if(l < r and flipped > k) {
                if(nums[l] == 0) flipped--;
                else cnt--;
                l++;
            }
            
            if(cnt > 0) ans = max(ans, r - l + 1);
            r++;
        }
        
        return ans;
    }
};
