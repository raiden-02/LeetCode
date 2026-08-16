class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int di = 0, len = 1;
        int total = R * C, vis = 1;
        int i = r0, j = c0;
        vector<vector<int>> ans;
        ans.push_back({i, j});
        
        while(vis < total) {
            
            for(int k = 0; k < len; k++) {
                i += dirs[di].first;
                j += dirs[di].second;
    
                if(i < R && j < C && i >= 0 && j >= 0) {
                    ans.push_back({i, j});
                    vis++;
                }
                
                if(vis == total) break;
            }
            di = (di + 1) % 4;
            
            if(di % 2 == 0)
                len += 1;
        }
        
        return ans;
    }
};
