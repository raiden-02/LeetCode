class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int s = 0, ans = numeric_limits<int>::max();

        while(r < nums.size()) {
            s += nums[r++];

            while(s >= target && l <= r) {
                ans = min(ans, r - l);
                s -= nums[l++];
            }
        }

        return ans == numeric_limits<int>::max() ? 0 : ans;
    }
};
