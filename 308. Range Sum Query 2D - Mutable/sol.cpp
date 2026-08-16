class NumMatrix {
    vector<vector<int>> farr, mat;
    int m, n;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        mat = matrix;
        m = matrix.size(), n = matrix[0].size();
        farr.resize(m + 1, vector<int>(n + 1));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++)
                farr[i][j] = farr[i][j - 1] + matrix[i - 1][j - 1];
        }

        for(int i = 1; i <= m; i++) {
            for(int j = n; j > 0; j--) {
                int parent = j - (j & -j);

                if(parent > 0)
                    farr[i][j] -= farr[i][parent];
            }
        }
    }
    
    void update(int row, int col, int val) {
        int diff = val - mat[row][col];
        mat[row][col] = val;

        for(int j = col + 1; j <= n; j += (j & -j))
            farr[row + 1][j] += diff;        
    }
    
    int sum(int r, int c) {
        int s = 0;

        for(int j = c; j > 0; j -= (j & -j))
            s += farr[r][j];
        
        return s;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;

        for(int i = row1 + 1; i <= row2 + 1; i++)
            ans += sum(i, col2 + 1)  - sum(i, col1);

        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
