class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        
        for(int i = 0; i < m; i++)
            sort(grid[i].rbegin(), grid[i].rend());
        
        for(int c = 0; c < n; c++) {
            int mx = 0;
            
            for(int r = 0; r < m; r++)
                mx = max(mx, grid[r][c]);
            
            ans += mx;
        }
        
        return ans;
    }
};
