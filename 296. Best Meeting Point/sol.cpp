class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rows, cols;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j])
                    rows.push_back(i), cols.push_back(j);
            }
        }
        
        int ans = 0, count = rows.size();
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());
        
        int ansx = rows[count / 2], ansy = cols[count / 2];
        
        for(int i = 0; i < count; i++) ans += abs(ansx - rows[i]) + abs(ansy - cols[i]);
        
        return ans;
    }
};
