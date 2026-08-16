class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), ind = 0, fs = m * n;
        vector<vector<int>> ans(m, vector<int>(n));
        vector<int> vec(fs);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                vec[(ind + k) % fs] = grid[i][j];
                ind++;
            }
        }
        
        ind = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans[i][j] = vec[ind++];
            }
        }
        
        return ans;
    }
};
