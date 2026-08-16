class Solution {
    string helper(int i, int j, int const& m, int const& n, vector<vector<int>> &grid, string path) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return "0";
        
        grid[i][j] = 0;
        string left = helper(i, j - 1, m, n, grid, "L");
        string right = helper(i, j + 1, m, n, grid, "R");
        string up = helper(i - 1, j, m, n, grid, "U");
        string down = helper(i + 1, j, m, n, grid, "D");
        
        return path + left + right + up + down;
    }
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        
        unordered_set<string> st;
        int m = grid.size(), n = grid[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1)
                    st.insert(helper(i, j, m, n, grid, "S"));
            }
        }
        
        return st.size();
    }
};
