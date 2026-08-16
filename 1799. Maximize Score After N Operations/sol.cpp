class Solution {
    vector<int> dp;

    int helper(vector<int> const& nums, int cnt, int remArrayMask) {
        if(2 * cnt ==  (int)nums.size()) return 0;
        if(dp[remArrayMask] != -1) return dp[remArrayMask];

        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            if((remArrayMask >> i) & 1) continue;

            for(int j = i + 1; j < nums.size(); j++) {
                if((remArrayMask >> j) & 1) continue;

                int curMask = remArrayMask | (1 << i) | (1 << j);

                ans = max(ans, (cnt + 1) * __gcd(nums[i], nums[j]) + helper(nums, cnt + 1, curMask));
            }
        }

        return dp[remArrayMask] = ans;
    }
public:
    int maxScore(vector<int>& nums) {
        int totalstates = 1 << (int)nums.size();
        dp.resize(totalstates, -1);
        return helper(nums, 0, 0);
    }
};
