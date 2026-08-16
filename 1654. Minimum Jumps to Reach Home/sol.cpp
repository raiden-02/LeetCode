class Solution {
    int dp[2][6001];
    unordered_set<int> vis;
    
public:
    int helper(int const& f, int const& b, int const& p, int ind, bool prev) {
        if(ind == p) return 0;
        
        if(ind < 0 or ind > 6000 or vis.find(ind) != vis.end()) return 1e9;
        
        if(dp[prev][ind] != -1) return dp[prev][ind];
        
        dp[prev][ind] = 1 + helper(f, b, p, ind + f, 0);
        
        if(not prev)
            dp[prev][ind] = min(dp[prev][ind], 1 + helper(f, b, p, ind - b, 1));
        
        return dp[prev][ind];
    }
    

    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        vis = unordered_set<int>(forbidden.begin(), forbidden.end());
        memset(dp, -1, sizeof(dp));
        
        int ans = helper(a, b, x, 0, false);
        return ans > 1e9 ? -1 : ans;               
    }
};
