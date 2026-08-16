class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {   
                if(grid[i][j]) {
                    for(auto &dir : dirs) {
                        int dx = i + dir.first, dy = j + dir.second;
                        
                        if(dx < 0 or dx >= m or dy < 0 or dy >= n or grid[dx][dy] == 0)
                            ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};
