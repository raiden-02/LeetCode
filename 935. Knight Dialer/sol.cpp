class Solution {
    unordered_map<int, vector<int>> dirs = {{0, {4, 6}}, {1, {6, 8}}, {2, {7, 9}}, {3, {4, 8}}, {4, {0, 3, 9}}, {6, {0, 1, 7}}, {7, {2, 6}}, {8, {1, 3}}, {9, {2, 4}}};
    vector<vector<int>> dp;
    int mod = 1e9 + 7;
    
    int helper(int n, int cur) {
        if(n == 0)
            return 1;
        
        if(n < 0)
            return 0;
        
        if(dp[n][cur] != -1)
            return dp[n][cur];
        
        int ans = 0;
        
        for(auto &x : dirs[cur])
            ans = (ans + helper(n - 1, x)) % mod;
        
        return dp[n][cur] = ans % mod;
    }
public:
    int knightDialer(int n) {
        if(n == 1)
            return 10;
        
        dp.resize(n + 1, vector<int>(10, -1));
        int ans = 0;
        
        for(int i = 0; i <= 9; i++) {
            if(i == 5) continue;
            ans = (ans + helper(n - 1, i)) % mod;
        }
        
        return ans;
    }
};
