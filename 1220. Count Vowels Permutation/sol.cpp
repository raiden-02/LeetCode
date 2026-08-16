class Solution {
public:
    /*a e i o u;
    0 1 2 3 4;*/
    vector<vector<int>> mp, dp;
    const int mod = 1e9 + 7;
    
    int helper(int cur, int const& n, int s) {
        if(s == n) return 1;
        
        if(s > n) return 0;
        
        if(dp[cur][s] != -1) return dp[cur][s];
        
        int ans = 0;
        
        for(int &neigh : mp[cur])
            ans = (ans + helper(neigh, n, s + 1)) % mod;
        
        return dp[cur][s] = ans;
    }
    
    int countVowelPermutation(int n) {
        int ans = 0;
        mp.resize(5), dp.resize(5, vector<int>(n + 1, -1));
        mp[0] = {1};
        mp[1] = {0, 2};
        mp[2] = {0, 1, 3, 4};
        mp[3] = {2, 4};
        mp[4] = {0};
        
        for(int i = 0; i < 5; i++)
            ans = (ans + helper(i, n, 1)) % mod;
        
        return ans;
    }
};
