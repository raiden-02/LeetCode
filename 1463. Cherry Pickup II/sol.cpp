class Solution {
    private int m, n;
    private int[][][] dp;
    private int[] dirs = new int[]{-1, 0, 1};
    
    private int helper(int[][] grid, int r, int c1, int c2) {
        if(r >= m) return 0;
        
        if(dp[r][c1][c2] != -1)
            return dp[r][c1][c2];
        
        int ans = 0;
        
        for(int i = 0; i < 3; i++) {
            int nc1 = c1 + dirs[i];
            if(nc1 < 0 || nc1 >= n) continue;
            
            for(int j = 0; j < 3; j++) {
                int nc2 = c2 + dirs[j];
                if(nc2 < 0 || nc2 >= n) continue;
                
                ans = Math.max(ans, helper(grid, r + 1, nc1, nc2));
            }
        }
        
        ans += (c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        dp[r][c1][c2] = ans;
        
        return ans;
    }
    
    public int cherryPickup(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        dp = new int[m][n][n];
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    dp[i][j][k] = -1;
        
        return helper(grid, 0, 0, n - 1);
    }
}
