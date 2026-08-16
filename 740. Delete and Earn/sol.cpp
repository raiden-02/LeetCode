class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int x : nums) freq[x]++;
        
        const int maxm = *max_element(nums.begin(), nums.end());
        int dp[maxm + 1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i <= maxm; i++)
            dp[i] = max(dp[max(0, i - 1)], dp[max(0, i - 2)] + freq[i] * i);
        
        return dp[maxm];
    }
};
