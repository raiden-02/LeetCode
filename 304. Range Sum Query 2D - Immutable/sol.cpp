//intuitive solution
class NumMatrix {
    //sum row1, col1 to row2, col2 = prefix(row2, col2) - prefix(row2, col1 - 1) + prefix(row1, col2) - prefix(row1, col1 - 1)
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        prefix.resize(m, vector<int>(n + 1));
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                prefix[i][j + 1] = prefix[i][j] + matrix[i][j];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int s = 0;
        col2 += 1, col1 += 1;
        
        for(int i = row1; i <= row2; i++)
            s += prefix[i][col2] - prefix[i][col1 - 1];
        
        return s;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
 
 //intial solution

// --- alternate solution ---

class NumMatrix {
private:
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        prefix.resize(m);
        
        for(int i = 0; i < matrix.size(); i++) {
            vector<int> cur(n);
            
            for(int j = 0; j < matrix[0].size(); j++)
                cur[j] = j == 0 ? matrix[i][j] : matrix[i][j] + cur[j - 1];
            
            prefix[i] = cur;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int s = 0;
        for(int i = row1; i <= row2; i++)
            s += prefix[i][col2] - (col1 > 0 ? prefix[i][col1 - 1] : 0);
        
        return s;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
