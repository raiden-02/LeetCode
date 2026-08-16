class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m, vector<int>(n)));
        int mod = 1e9 + 7, ans = 0;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        dp[0][startRow][startColumn] = 1;
        
        for(int moves = 0; moves < maxMove; moves++) {
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    int cur = dp[moves][i][j] % mod;
                    
                    if(cur > 0) {
                        for(auto &dir : dirs) {
                            int dx = i + dir.first, dy = j + dir.second;
                            
                            if(dx >= 0 and dx < m and dy >= 0 and dy < n)
                                dp[moves + 1][dx][dy] += cur, dp[moves + 1][dx][dy] %= mod;
                                
                            else
                                ans += cur, ans %= mod;
                                
                        }
                    }
                }
            }
        }
        
        return ans % mod;
    }
};

// --- alternate solution ---

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int dp[maxMove + 1][m][n];
        memset(dp, 0, sizeof(dp));
        dp[0][startRow][startColumn] = 1;
        int const mod = 1e9 + 7;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int ans = 0;
        
        for(int move = 0; move < maxMove; move++) {
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    int cur = dp[move][i][j] % mod;
                    if(cur == 0) continue;
                    
                    for(auto &dir : dirs) {
                        int dx = i + dir.first, dy = j + dir.second;
                        
                        if(dx >= 0 and dx < m and dy >= 0 and dy < n)
                            dp[move + 1][dx][dy] += cur, dp[move + 1][dx][dy] %= mod;
                        
                        else
                            ans += cur, ans %= mod;
                    }
                }
            }
        }
        
        return ans % mod;
    }
};
