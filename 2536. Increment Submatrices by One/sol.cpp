class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n));

        for(auto &query : queries) {
            int r1 = query[0], c1 = query[1], r2 = query[2], c2 = query[3];

            for(int r = r1; r <= r2; r++) {
                mat[r][c1]++;
                if(c2 + 1 < n) mat[r][c2 + 1]--;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) 
                mat[i][j] += mat[i][j - 1];
        }

        return mat;
    }
};
