class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), s = 0;

        for(int i = 0; i < n; i++) {
            s += mat[i][i];
        }

        for(int i = n - 1; i >= 0; i--) {
            s += mat[i][n - i - 1];
        }

        return n % 2 ? s - mat[(int)n / 2][(int)n / 2] : s;
    }
};
