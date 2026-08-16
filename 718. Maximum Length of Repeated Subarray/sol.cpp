class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1));
        int ans = 0;
        
        for(int i = 0; i <= nums1.size(); i++) {
            for(int j = 0; j <= nums2.size(); j++) {
                if(i == 0 or j == 0)
                    dp[i][j] = 0;
                else if(nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1, ans = max(ans, dp[i][j]);
                else
                    dp[i][j] = 0;
            }
        }
        
        return ans;
    }
};

// --- alternate solution ---

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int dp[1001][1001], ans = 0;
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i <= nums1.size(); i++) {
            for(int j = 1; j <= nums2.size(); j++) {
               if(nums1[i - 1] == nums2[j - 1])
                   dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = 0;
                
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};
