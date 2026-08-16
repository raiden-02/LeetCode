class Solution {
    int dp[5001][4][4][4];
    int mod = 1e9 + 7;
    
    int helper(int const& n, int ind, int a, int b, int c) {
        if(ind >= n)
            return 1;
        
        if(dp[ind][a][b][c] != -1)
            return dp[ind][a][b][c];
        
        int ans = 0;
        
        for(int i = 1; i <= 3; i++) {
            if(i == a) continue;
            
            for(int j = 1; j <= 3; j++) {
                if(j == i || j == b) continue;
                
                for(int k = 1; k <= 3; k++) {
                    if(k == j || k == c) continue;
                    
                    ans += helper(n, ind + 1, i, j, k), ans %= mod;
                }
            }
        }
        
        return dp[ind][a][b][c] = ans;
    }
public:
    int numOfWays(int n) {
        memset(dp, -1, sizeof(dp));
        
        return helper(n, 0, 0, 0, 0);
    }
};
