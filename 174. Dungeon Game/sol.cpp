class Solution {
    int m, n;
    vector<vector<int>> dp;
    
    int helper(vector<vector<int>> &dungeon, int i, int j) {
        if(i == m - 1 and j == n - 1) {
            if(dungeon[i][j] < 0) return -dungeon[i][j] + 1;
            return 1;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        
        if(i + 1 < m) {
            int down = helper(dungeon, i + 1, j);
            
            if(dungeon[i][j] >= down) ans = min(ans, 1);
            
            else ans = min(ans, down - dungeon[i][j]);
        }
        
        if(j + 1 < n) {
            int right = helper(dungeon, i, j + 1);
            
            if(dungeon[i][j] >= right) ans = min(ans, 1);
            
            else ans = min(ans, right - dungeon[i][j]);
        }
        
        return dp[i][j] = ans;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size(), n = dungeon[0].size();
        dp.resize(m, vector<int>(n, -1));
        
        return helper(dungeon, 0, 0);
    }
};
