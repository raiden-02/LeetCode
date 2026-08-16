class Solution {
    vector<vector<int>> dp;
    
    int helper(vector<int> &s, vector<int> &p, int si, int pi) {
        if(si >= s.size() or pi >= p.size()) return 0;
        
        if(dp[si][pi] != -1) return dp[si][pi];
        
        int ans = 0;
        
        for(int i = pi; i < p.size(); i++) {
            if(s[si] == p[i])
                ans = max(ans, 1 + helper(s, p, si + 1, i + 1));
        }
        
        
        return dp[si][pi] = max(ans, helper(s, p, si + 1, pi));
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        dp.resize(nums1.size(), vector<int>(nums2.size(), -1));
        
        for(int i = 0; i < nums1.size(); i++)
            ans = max(ans, helper(nums1, nums2, i, 0));
        
        return ans;
    }
};

// --- alternate solution ---

class Solution {
    int dp[501][501];
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2, int i1 = 0, int i2 = 0) {
        if(i1 == 0 && i2 == 0) {
            memset(dp, -1, sizeof(dp));
        }

        if(i1 >= nums1.size() || i2 >= nums2.size()) return 0;

        if(dp[i1][i2] != -1) return dp[i1][i2];
        
        if(nums1[i1] == nums2[i2])
            return dp[i1][i2] = 1 + maxUncrossedLines(nums1, nums2, i1 + 1, i2 + 1);

        return dp[i1][i2] = max(maxUncrossedLines(nums1, nums2, i1, i2 + 1), maxUncrossedLines(nums1, nums2, i1 + 1, i2));
    }
};
