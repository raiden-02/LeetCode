class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        int n = grid[0].size(), m = grid.size();
        
        for(int j = 0; j < n; j++) {
            int r = 0, c = j;
            bool f = false;
            
            while(r < m and c < n and c >= 0) {
                if((c + 1 < n and grid[r][c] == 1 and grid[r][c + 1] == -1) or (c - 1 >= 0 and grid[r][c] == -1 and grid[r][c - 1] == 1)) {
                    ans.push_back(-1);
                    f = true; break;
                }

                else if(grid[r][c] == 1) r++, c++;
                else r++, c--;
            }
            
            if(not f) if(c >= 0 and c < n) ans.push_back(c); else ans.push_back(-1);
        }
        
        return ans;
    }
};
