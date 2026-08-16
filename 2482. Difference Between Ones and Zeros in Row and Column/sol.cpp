class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> oner(m), onec(n);
        vector<vector<int>> diff(m, vector<int>(n));

        for(int i = 0; i < m; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                cnt += grid[i][j] == 1;
            }
            oner[i] = cnt;
        }

        for(int j = 0; j < n; j++) {
            int cnt = 0;
            for(int i = 0; i < m; i++) {
                cnt += grid[i][j] == 1;
            }
            onec[j] = cnt;
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
               diff[i][j] = oner[i] + onec[j] - (m - oner[i]) - (n - onec[j]);
            }
        }

        return diff;
    }
};
