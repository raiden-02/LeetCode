class Solution {
    /*      1
        0       2
            3
    */
            
    vector<vector<vector<bool>>> vis;
    int n;
    
    void dfs(int i, int j, int quad, vector<string> const& grid) {
        if(i < 0 or i >= n or j < 0 or j >= n or vis[i][j][quad]) return;
        
        vis[i][j][quad] = true;
        
        if(quad == 0)
            dfs(i, j - 1, 2, grid);
        
        else if(quad == 1)
            dfs(i - 1, j, 3, grid);
        
        else if(quad == 2)
            dfs(i, j + 1, 0, grid);
        
        else
            dfs(i + 1, j, 1, grid);
        
        if(grid[i][j] == '/') {
            if(quad == 0)
                dfs(i, j, 1, grid);
            else if(quad == 1)
                dfs(i, j, 0, grid);
            else if(quad == 2)
                dfs(i, j, 3, grid);
            else
                dfs(i, j, 2, grid);
        }
        
        else if(grid[i][j] == '\\') {
            if(quad == 0)
                dfs(i, j, 3, grid);
           else if(quad == 3)
                dfs(i, j, 0, grid);
           else if(quad == 1)
                dfs(i, j, 2, grid);
           else
                dfs(i, j, 1, grid);
        }
        
        else {
            dfs(i, j, (quad + 1) % 4, grid);
            dfs(i, j, (quad + 2) % 4, grid);
            dfs(i, j, (quad + 3) % 4, grid);
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        vis.resize(n, vector<vector<bool>>(n, vector<bool>(4, false)));
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int quad = 0; quad < 4; quad++) {
                    if(not vis[i][j][quad])
                        dfs(i, j, quad, grid), ans++;
                }
            }
        }
        
        return ans;
    }
};
