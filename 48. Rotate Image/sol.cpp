class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        reverse(matrix.begin(), matrix.end());
        
        for(int i = 0; i < m; i++) {
            for(int j = i + 1; j < m; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};

// --- alternate solution ---

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        reverse(matrix.begin(), matrix.end());
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};
