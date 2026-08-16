class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        for(int i = 0; i < n; i++)
            dp[0][i] = matrix[0][i];
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int a = j - 1 >= 0 ? dp[i - 1][j - 1] : INT_MAX;
                int b = j + 1 < n ? dp[i - 1][j + 1] : INT_MAX;
                dp[i][j] = matrix[i][j] + min(dp[i - 1][j], min(a, b));
            }
        }
        
        int ans = INT_MAX;
        for(int i = 0; i < n; i++)
            ans = min(ans, dp[n - 1][i]);
        
        return ans;
    }
};

// --- alternate solution ---

class Solution {
    const int MAX_INT = numeric_limits<int>::max();
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int prev = j - 1 >= 0 ? matrix[i - 1][j - 1] : MAX_INT;
                int next = j + 1 < n ? matrix[i - 1][j + 1] : MAX_INT;

                matrix[i][j] += min(prev, min(next, matrix[i - 1][j])); 
            }
        }

        return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
};
