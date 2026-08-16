class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1), indices(nums.size(), -1);
        int maxind = 0;
        
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 and dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    indices[i] = j;
                }
            }
            
            if(dp[i] > dp[maxind])
                maxind = i;
        }
        
        vector<int> ans;
        int ind = maxind;
        
        while(ind >= 0) {
            ans.push_back(nums[ind]);
            ind = indices[ind];
        }
        
        return ans;
    }
};
