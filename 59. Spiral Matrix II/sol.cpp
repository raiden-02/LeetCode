class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int counter = n, m = n - 1;
        int i = 0, j = -1;
        int di = 0, num = 1;
        
        while(counter) {
            for(int k = 0; k < counter; k++) {
                i += dirs[di].first;
                j += dirs[di].second;
                ans[i][j] = num++;
            }
            
            if(di % 2 == 0)
                n--;
            else
                m--;
            
            di = (di + 1) % 4;
            
            counter = di % 2 == 0 ? n : m;
        }
        
        return ans;
    }
};
