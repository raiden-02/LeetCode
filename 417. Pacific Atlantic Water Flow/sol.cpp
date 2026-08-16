class Solution {
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    
    void dfs(int x, int y, vector<vector<int>> const& mat, int prev, vector<vector<bool>> &vis) {
        if(x < 0 || x >= mat.size() || y < 0 || y >= mat[0].size() || vis[x][y] || mat[x][y] < prev)
            return;
        
        vis[x][y] = true;
        for(auto &dir : dirs) {
            dfs(x + dir.first, y + dir.second, mat, mat[x][y], vis);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return {};
        
        vector<vector<bool>> visp = vector<vector<bool>>(matrix.size(), vector<bool>(matrix[0].size()));
        vector<vector<bool>> visa = vector<vector<bool>>(matrix.size(), vector<bool>(matrix[0].size()));
        
        for(int i = 0; i < matrix.size(); i++) {
            dfs(i, 0, matrix, INT_MIN, visp);
            dfs(i, matrix[0].size() - 1, matrix, INT_MIN, visa);
        }
        
        for(int i = 0; i < matrix[0].size(); i++) {
            dfs(0, i, matrix, INT_MIN, visp);
            dfs(matrix.size() - 1, i, matrix, INT_MIN, visa);
        }
        
        vector<vector<int>> ans;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(visp[i][j] && visa[i][j])
                    ans.push_back({i, j});
            }
        }
        
        return ans;
    }
};
