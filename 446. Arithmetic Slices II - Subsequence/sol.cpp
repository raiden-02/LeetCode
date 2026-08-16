class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        
        vector<unordered_map<int, int>> dp(nums.size());
        
        unordered_map<int, int> freq;
        
        for(int x : nums) freq[x]++;
        
        for(auto &x : freq)
            if(x.second >= 3) ans += pow(2, x.second) - x.second - (x.second * (x.second - 1)) / 2 - 1;
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                long d = (long)nums[i] - (long)nums[j];
                if(d > INT_MAX or d < INT_MIN or d == 0) continue;
                
                dp[i][d] += 1 + dp[j][d];
                ans += dp[j][d];
            }
        }
        
        return ans;
    }
};
